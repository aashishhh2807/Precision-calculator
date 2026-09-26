#include "dll.h"
#include <iostream>
#include <cstring>

using namespace std;

int main(int argc, char *argv[])
{
    Dlist *head1 = nullptr;
    Dlist *tail1 = nullptr;

    Dlist *head2 = nullptr;
    Dlist *tail2 = nullptr;

    Dlist *Rhead = nullptr;
    Dlist *Rtail = nullptr;

    // Check number of arguments
    if (argc < 4)
    {
        cout << "Insufficient number of arguments." << endl;
        return FAILURE;
    }

    // Store first number in linked list
    for (int i = 0; argv[1][i] != '\0'; i++)
    {
        int num1 = argv[1][i] - '0';
        insert_last(head1, tail1, num1);
    }

    // Store second number in linked list
    for (int i = 0; argv[3][i] != '\0'; i++)
    {
        int num2 = argv[3][i] - '0';
        insert_last(head2, tail2, num2);
    }

    // Addition
    if (argv[2][0] == '+')
    {
        addition(tail1, tail2, Rhead, Rtail);
        print_list(Rhead);
    }

    // Subtraction
    else if (argv[2][0] == '-')
    {
        if (strlen(argv[1]) > strlen(argv[3]))
        {
            sub(head1, tail1,
                head2, tail2,
                Rhead, Rtail);

            print_list(Rhead);
        }
        else if (strlen(argv[1]) < strlen(argv[3]))
        {
            cout << "-";

            sub(head2, tail2,
                head1, tail1,
                Rhead, Rtail);

            print_list(Rhead);
        }
        else
        {
            int num1 = argv[1][0] - '0';
            int num2 = argv[3][0] - '0';

            if (num1 > num2)
            {
                sub(head1, tail1,
                    head2, tail2,
                    Rhead, Rtail);

                print_list(Rhead);
            }
            else
            {
                cout << "-";

                sub(head2, tail2,
                    head1, tail1,
                    Rhead, Rtail);

                print_list(Rhead);
            }
        }
    }

    // Multiplication
    else if (argv[2][0] == '*')
    {
        mul(head1, tail1,
            head2, tail2,
            Rhead, Rtail);

        print_list(Rhead);
    }

    // Division
    else if (argv[2][0] == '/')
    {
        division(head1, tail1,
                 head2, tail2,
                 Rhead, Rtail);

        print_list(Rhead);
    }

    // Invalid operator
    else
    {
        cout << "Invalid operator." << endl;
        return FAILURE;
    }

    return SUCCESS;
}