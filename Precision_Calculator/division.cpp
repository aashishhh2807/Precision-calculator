#include "dll.h"
#include <iostream>

using namespace std;

int division(Dlist *&head1, Dlist *&tail1,
             Dlist *&head2, Dlist *&tail2,
             Dlist *&Rhead, Dlist *&Rtail)
{
    // Division by zero check
    if (head2 == nullptr)
    {
        cout << "Division by zero not possible" << endl;
        return FAILURE;
    }

    // Copy dividend into remainder
    Dlist *rem_head = nullptr;
    Dlist *rem_tail = nullptr;

    Dlist *temp = head1;

    while (temp != nullptr)
    {
        insert_last(rem_head, rem_tail, temp->data);
        temp = temp->next;
    }

    int count = 0;

    while (true)
    {
        // Compare length of remainder and divisor
        int len1 = 0;
        int len2 = 0;

        Dlist *t1 = rem_head;
        Dlist *t2 = head2;

        while (t1 != nullptr)
        {
            len1++;
            t1 = t1->next;
        }

        while (t2 != nullptr)
        {
            len2++;
            t2 = t2->next;
        }

        // Remainder has fewer digits
        if (len1 < len2)
            break;

        // Same number of digits → compare digit by digit
        if (len1 == len2)
        {
            t1 = rem_head;
            t2 = head2;

            bool smaller = false;

            while (t1 != nullptr && t2 != nullptr)
            {
                if (t1->data < t2->data)
                {
                    smaller = true;
                    break;
                }
                else if (t1->data > t2->data)
                {
                    break;
                }

                t1 = t1->next;
                t2 = t2->next;
            }

            if (smaller)
                break;
        }

        // remainder >= divisor
        // remainder = remainder - divisor

        Dlist *new_head = nullptr;
        Dlist *new_tail = nullptr;

        sub(rem_head, rem_tail,
            head2, tail2,
            new_head, new_tail);

        rem_head = new_head;
        rem_tail = new_tail;

        // Remove leading zeros
        while (rem_head != nullptr &&
               rem_head->data == 0 &&
               rem_head->next != nullptr)
        {
            Dlist *temp_zero = rem_head;

            rem_head = rem_head->next;
            rem_head->prev = nullptr;

            delete temp_zero;
        }

        count++;
    }

    // Convert quotient count into linked list
    if (count == 0)
    {
        insert_first(Rhead, Rtail, 0);
    }
    else
    {
        while (count > 0)
        {
            insert_first(Rhead, Rtail, count % 10);
            count /= 10;
        }
    }

    return SUCCESS;
}