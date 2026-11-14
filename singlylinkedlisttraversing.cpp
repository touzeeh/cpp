#include <iostream>
#include "linkedlist.h"

void display(const Node* head)
{
    const Node* temp = head;

    while (temp != nullptr)
    {
        std::cout << temp->data << ' ';
        temp = temp->next;
    }
    std::cout << '\n';
}

int main()
{
    Node third{30, nullptr};
    Node second{20, &third};
    Node first{10, &second};

    display(&first)
    return 0;
}
