#include "dll.h"

int mul(Dlist *&head1, Dlist *&tail1,
        Dlist *&head2, Dlist *&tail2,
        Dlist *&Rhead, Dlist *&Rtail)
{
    Dlist *temp2 = tail2;
    int count = 0; //tells us how many zeros for position shifting
    // 123 * 45  123*5 = 615, 123*4 = 492 
    // when we will add we will do 615+4920 =5335
    while (temp2 != nullptr)
    {
        Dlist *temp1 = tail1;

        Dlist *row_head = nullptr;
        Dlist *row_tail = nullptr;

        int carry = 0;

        // Add zeros for positional shifting
        for (int i = 0; i < count; i++)
        {
            insert_first(row_head, row_tail, 0);
        }

        // Multiply one digit of number2 with the complete number1
        while (temp1 != nullptr)
        {
            int prod = temp1->data * temp2->data + carry;

            carry = prod / 10;

            insert_first(row_head, row_tail, prod % 10);

            temp1 = temp1->prev;
        }

        // Add remaining carry
        if (carry != 0)
        {
            insert_first(row_head, row_tail, carry);
        }

        // First partial product
        if (Rhead == nullptr)
        {
            Rhead = row_head;
            Rtail = row_tail;
        }
        else
        {
            Dlist *new_head = nullptr;
            Dlist *new_tail = nullptr;

            addition(Rtail, row_tail, new_head, new_tail);

            Rhead = new_head;
            Rtail = new_tail;
        }

        temp2 = temp2->prev;
        count++;
    }

    return SUCCESS;
}