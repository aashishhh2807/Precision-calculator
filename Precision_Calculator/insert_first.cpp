#include "dll.h"

int insert_first(Dlist *&head, Dlist *&tail, int data)
{
    Dlist *newNode = new Dlist;

    if (newNode == nullptr)
        return FAILURE;

    newNode->data = data;
    newNode->prev = nullptr;
    newNode->next = nullptr;

    // If the list is empty
    if (head == nullptr)
    {
        head = newNode;
        tail = newNode;

        return SUCCESS;
    }

    // Insert before current head
    head->prev = newNode;
    newNode->next = head;
    head = newNode;

    return SUCCESS;
}