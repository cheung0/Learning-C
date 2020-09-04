#include <stdio.h>
#include <cs50.h>

int main(void) 
{
    // initialize and declare height variable
    int height = 0;
    
    // keep prompting user for height between 1 through 8
    do
    {
        height = get_int("%s", "Height: ");
    } 
    while (height < 1 || height > 8);

    // create pyramind
    for (int i = 1; i <= height; i ++) 
    {
        // print left spaces
        int left_spaces = height - i;
        for (int j = 0; j < left_spaces; j ++) 
        {
            printf(" ");
        }
        
        // print left pyramind
        for (int k = 0; k < i; k ++) 
        {
            printf("#");
        }
        
        // print gap between left and right pyraminds
        printf("  ");
        
        // print right pyraamind
        for(int n = 0; n < i; n ++)
        {
            printf("#");
        }
        
        // go to next level 
        printf("\n");
    }
}
