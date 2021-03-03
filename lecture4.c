#include <stdio.h>
#include <string.h>

void draw(int h);

typedef struct
{
    int age;
}
person;

int main(void)
{
    person people[2];
    people[0].age = 19;
    people[1].age = 12;

    draw(100);
}

void draw(int h)
{
    if (h == 0)
    {
        return;
    }

    draw(h - 1);

    for (int i = 0; i < h; i++)
    {
        printf("#");
    }
    printf("\n");
}
