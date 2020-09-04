#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // prompt user for a name
    string name = get_string("What's your name?\n");
    
    // print user's name after being joined with hello
    printf("hello, %s\n", name);
}
