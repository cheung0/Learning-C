#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int company = 0;
    long number = get_long("Number: ");

    // get number of digits of card number
    long temp = number;
    int digits = 0;
    while (temp > 0)
    {
        temp /= 10;
        digits ++;
    }
    
    // checks which companies the card could be
    if (digits == 13)
    {
        if (number / 1000000000000 == 4)
        {
            company = 1;
        }
    }
    else if (digits == 15)
    {
        if (number / 10000000000000 == 34 || number / 10000000000000 == 37)
        {
            company = 2;
        }
    }
    else if (digits == 16)
    {
        if (number / 100000000000000 == 51 || number / 100000000000000 == 52 || number / 100000000000000 == 53 || number / 100000000000000 == 54 || number / 100000000000000 == 55)
        {
            company = 3;
        }
        else if (number / 1000000000000000 == 4)
        {
            company = 1;
        }
    }
    
    // check luhn's algorithm
    if (company != 0)
    {
        int last = 0;
        int second_last = 0;
        int temp2 = 0;
        
        while (number > 0)
        {
            last += number % 10;
            number /= 10;
            temp2 = (temp2 % 10) * 2;
            if (temp2 > 9) 
            {
                second_last += temp2 % 10 + temp2 / 10;
            }
            else
            {
                second_last += temp2;
            }
        }
        
        if ((last + second_last) % 10 == 0)
        {
            if (company == 2)
            {
                printf("AMEX\n");
            }
            else if (company == 1)
            {
                printf("VISA\n");
            }
            else if (company == 3)
            {
                printf("MASTERCARD\n");
            }
        }
        else
        {
            printf("INVALID\n");
        }
    }

    else
    {
        printf("INVALID\n");
    }
}
