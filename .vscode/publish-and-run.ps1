[CmdletBinding()]
param(
    [Parameter(Mandatory = $true)]
    [string]$Source
)

$ErrorActionPreference = 'Stop'
$repoRoot = [System.IO.Path]::GetFullPath((Join-Path $PSScriptRoot '..'))
$sourcePath = [System.IO.Path]::GetFullPath((Resolve-Path -LiteralPath $Source).Path)
$rootPrefix = $repoRoot.TrimEnd([System.IO.Path]::DirectorySeparatorChar) + [System.IO.Path]::DirectorySeparatorChar

if (-not $sourcePath.StartsWith($rootPrefix, [System.StringComparison]::OrdinalIgnoreCase)) {
    throw 'The active source file is outside the C:\Vs Code project folder.'
}
if ([System.IO.Path]::GetExtension($sourcePath) -ne '.cpp') {
    throw 'The Run and Publish action is configured for .cpp files.'
}

Set-Location -LiteralPath $repoRoot
$expectedRemote = 'https://github.com/touzeeh/cpp.git'
$publishFailed = $false

function Invoke-Git {
    param([string[]]$GitArguments)
    & git @GitArguments
    if ($LASTEXITCODE -ne 0) {
        throw "git $($GitArguments -join ' ') failed with exit code $LASTEXITCODE."
    }
}

try {
    if (-not (Test-Path -LiteralPath (Join-Path $repoRoot '.git'))) {
        Invoke-Git @('init', '--initial-branch=main')
    }

    $remoteNames = @(& git remote)
    if ($LASTEXITCODE -ne 0) {
        throw 'Could not read the configured Git remotes.'
    }
    if ($remoteNames -notcontains 'origin') {
        Invoke-Git @('remote', 'add', 'origin', $expectedRemote)
    } else {
        $originUrl = & git config --get remote.origin.url
        $originExitCode = $LASTEXITCODE
        if ($originExitCode -ne 0 -or [string]::IsNullOrWhiteSpace([string]$originUrl)) {
            throw "Could not read the origin URL (git exit code $originExitCode)."
        }
        $originUrl = [string]$originUrl
        if ($originUrl.TrimEnd('/') -ne $expectedRemote) {
            throw "The existing origin points somewhere else: $originUrl"
        }
    }

    $branch = (& git branch --show-current).Trim()
    if ($LASTEXITCODE -ne 0 -or $branch -ne 'main') {
        throw "This project is on branch '$branch'. Switch it to main before using Run and Publish."
    }

    if (-not (& git config user.name)) {
        Invoke-Git @('config', 'user.name', 'touzeeh')
    }
    if (-not (& git config user.email)) {
        Invoke-Git @('config', 'user.email', '214071405+touzeeh@users.noreply.github.com')
    }

    Write-Host 'Publishing project changes to github.com/touzeeh/cpp ...'
    Invoke-Git @('add', '-A', '--', '.')
    & git diff --cached --quiet
    $diffExit = $LASTEXITCODE
    if ($diffExit -eq 1) {
        $fileName = [System.IO.Path]::GetFileName($sourcePath)
        Invoke-Git @('commit', '-m', "Run and sync: $fileName")
    } elseif ($diffExit -ne 0) {
        throw "git diff failed with exit code $diffExit."
    } else {
        Write-Host 'No file changes to commit; checking GitHub for pending commits.'
    }

    Invoke-Git @('push', '--set-upstream', 'origin', 'main')
    Write-Host 'GitHub is up to date.'
} catch {
    $publishFailed = $true
    Write-Warning "GitHub publish did not complete: $($_.Exception.Message)"
    Write-Warning 'The C++ build and run will continue. Sign in to GitHub or fix the reported Git issue, then click Run again to retry.'
}

$compiler = Get-Command 'g++' -ErrorAction SilentlyContinue
if ($null -eq $compiler) {
    Write-Error 'g++ was not found on PATH, so the source could not be built.'
    exit 127
}

$buildDir = Join-Path $repoRoot '.build'
New-Item -ItemType Directory -Path $buildDir -Force | Out-Null
$outputPath = Join-Path $buildDir ([System.IO.Path]::GetFileNameWithoutExtension($sourcePath) + '.exe')
$compileArgs = @('-Wall', '-Wextra', '-Wpedantic', $sourcePath, '-o', $outputPath)
Write-Host "Building $([System.IO.Path]::GetFileName($sourcePath)) ..."
& $compiler.Source @compileArgs
$compileExit = $LASTEXITCODE
if ($compileExit -ne 0) {
    if ($publishFailed) { exit 1 }
    exit $compileExit
}

Write-Host 'Running program ...'
& $outputPath
$runExit = $LASTEXITCODE
if ($publishFailed) { exit 1 }
exit $runExit


