/*
compiling
1. preprocessing - takes header file code and replaces code 
2. compiling - takes C source code and converts into assembly code
3. assembling - takes assembly code and converts it into binary, or machine code
4. linking - different library code and files are linked ogether i nto one binary file
*/

/*
data types - have different sizes
bool - 1 byte
char - 1 byte
int - 4 bytes
float - 4 bytes
etc.
*/

/*
memory
RAM - random-access memory, short term use; small for temporary use, until electricity is powered off
hard drive - ssd, long term use
each "box" in memory has an address and size 
*/

#include <stdio.h>
// N should never be changed by program
const int N = 2;
int main(int argc, char* argv[])
{
    // array - list of variables sroted in a contiguous chunk of memory
    // age
    int ages[N];
    ages[0] = 72;
    ages[1] = 73;
    // print average
    printf("Average: %i\n", (ages[0] + ages[1]) / N);

    // string - array of characters, terminated by null character, \0, a 0 byte
    char name[] = "Ayanokoji";
    printf("%s", name);

    // command-line arguments
    // argc - argument count
    // argv - argument is array of strings
    if (argc == 2)
    {
        printf("Well, well, well, we have 2 arguments, all is well");
        // 0 indicates all is well
        return 0;
    }
    else
    {
        printf("Well, well, well, we have 1 argument, all is not well");
        // 1 indicates all is not well
        return 1;
    }
}

/*
encryption
message -> algorithm (encrypt) -> hidden message
*/


