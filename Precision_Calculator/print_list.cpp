#include "dll.h"
#include <iostream>

using namespace std;

void print_list(Dlist *head)
{
    if (head == nullptr)
    {
        cout << "INFO : List is empty" << endl;
        return;
    }

    while (head != nullptr)
    {
        cout << head->data;
        head = head->next;
    }

    cout << endl;
}