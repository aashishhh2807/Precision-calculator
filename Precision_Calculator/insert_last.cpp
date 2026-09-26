#include "dll.h"

int insert_last(Dlist *&head, Dlist *&tail, int data)
{
    Dlist *newNode = new Dlist;

    if (newNode == nullptr) // to check memory is allocated properly
        return FAILURE;

    newNode->data = data;
    newNode->next = nullptr;
    newNode->prev = nullptr;

    // If the list is empty
    if (head == nullptr)
    {
        head = newNode;
        tail = newNode;

        return SUCCESS;
    }

    // Insert at the end
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;

    return SUCCESS;
}