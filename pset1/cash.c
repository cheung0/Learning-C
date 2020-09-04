#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    int coins = 0;
    float dollars = 0;
    
    // keep prompting user for change owed if given less than or equal to 0
    do
    {
        dollars = get_float("Change owed: ");
    }
    while (dollars <= 0);
    
    // convert from float to int for better precision
    int cents = round(dollars * 100);
    
    // get number of coins with this greedy algorithm
    while (cents > 0)
    {
        if (cents >= 25)
        {
            cents -= 25;
            coins ++;
        }
        else if (cents >= 10)
        {
            cents -= 10;
            coins ++;
        }
        else if (cents >= 5)
        {
            cents -= 5;
            coins ++;
        }
        else 
        {
            cents -= 1;
            coins ++;
        }
    }
    
    printf("%i\n", coins);
    
}
