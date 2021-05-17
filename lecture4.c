#include <stdio.h>

int main(void)
{
    /*
    addresses are in hexadecimal
    address of a variable is a pointer
    we can go to a pointer with *
    we can get the address of a variable with &
    */
    int n = 32;
    printf("Address of %i is %p\n", n, &n);
    printf("n is %i\n", *&n);

    int *p = &n;
    printf("Address of %i is %p\n", n, p);

    char *s = "Big Mike";
    printf("%s\n", s);

    printf("Address of first character is %p\n", &s[0]);
    printf("Address of second character is %p\n", &s[1]);
    printf("Third character is %c\n", *(s + 2));


    /*
    scanf
    */
    int x;
    printf("x: ");
    scanf("%i", &x);
    printf("x: %i\n", x);
}
