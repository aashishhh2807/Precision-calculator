#ifndef DLL_H
#define DLL_H

#define SUCCESS 0
#define FAILURE -1

// Node of the doubly linked list
struct Dlist
{
    int data;
    Dlist *prev;
    Dlist *next;
};

// Linked list functions
int insert_last(Dlist *&head, Dlist *&tail, int data);
int insert_first(Dlist *&head, Dlist *&tail, int data);

void print_list(Dlist *head);

// Arithmetic functions
int addition(Dlist *&tail1, Dlist *&tail2,
             Dlist *&Rhead, Dlist *&Rtail);

int sub(Dlist *&head1, Dlist *&tail1,
        Dlist *&head2, Dlist *&tail2,
        Dlist *&Rhead, Dlist *&Rtail);

int mul(Dlist *&head1, Dlist *&tail1,
        Dlist *&head2, Dlist *&tail2,
        Dlist *&Rhead, Dlist *&Rtail);

int division(Dlist *&head1, Dlist *&tail1,
             Dlist *&head2, Dlist *&tail2,
             Dlist *&Rhead, Dlist *&Rtail);

#endif