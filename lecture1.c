#include <stdio.h>

void cough(int n);

int main(void)
{
    // these are comments
    printf("hello, world\n");

    int number = 3;
    printf("My favorite number is %i.\n", number);
    
    int x = 5;
    int y = 10;
    if (x < y)
    {
        printf("x is less than y\n");
    }
    else if (x > y)
    {
        printf("x is greater than y\n");
    }
    else
    {
        printf("x is equal to y\n");
    }

    int i = 0;
    while (i < 5)
    {
        printf("hello, world\n");
        i ++;
    }

    for (int i = 0; i < 5; i ++)
    {
        printf("hello, world\n");
    }

    float us_dollars = 34.323;
    printf("Your %.2f United States dollars is worth %.2f Hong Kong dollars.\n", us_dollars, us_dollars * 7.75);

    int n = 32;
    if (n % 2 == 0)
    {
        printf("Number is even.\n");
    }
    else
    {
        printf("Number is odd.\n");
    }

    // bool rain = false;
    // bool fired = true;
    if (1 == 1 || 3 < 3)
    {
        printf("I am unhappy.\n");
    }
    else if(1 == 3 && 3 == 2)
    {
        printf("I am happy.\n");
    }

    cough(3);

    // int overflow exists!
}

void cough(int n)
{
    for (int i = 0; i < n; i ++)
    {
        printf("cough\n");
    }
}
