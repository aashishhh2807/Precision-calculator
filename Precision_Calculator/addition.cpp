#include "dll.h"

int addition(Dlist *&tail1, Dlist *&tail2,
             Dlist *&Rhead, Dlist *&Rtail)
{
    Dlist *temp1 = tail1;    
    Dlist *temp2 = tail2;

    int carry = 0;
    int sum;

    while (temp1 != nullptr || temp2 != nullptr)
    {
        if (temp1 != nullptr && temp2 != nullptr)
            sum = temp1->data + temp2->data + carry;

        else if (temp1 != nullptr && temp2 == nullptr) // 125+83 this is for 1+1 of thrid digit
            sum = temp1->data + carry;

        else
            sum = temp2->data + carry;// 83+125 this is for second number


        carry = 0;

        if (sum > 9)
            carry = 1;

        insert_first(Rhead, Rtail, sum % 10);

        if (temp1 != nullptr)
            temp1 = temp1->prev;

        if (temp2 != nullptr)
            temp2 = temp2->prev;  // this loop will end when both the nos are over
    }

    if (carry == 1) //this is for 74+46 there will be a carry even after the digits over 
        insert_first(Rhead, Rtail, 1);

    return SUCCESS;
}