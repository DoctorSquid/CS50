#include <stdio.h>
#include <cs50.h>

int get_height(void);
void draw_tower(int height);

int main(void)
{
    int height = get_height();
    draw_tower(height);
}

int get_height(void)
{
    int height;
    do
    {
        height = get_int ("How tall should the tower be?");
    }
    while (height < 1 | height > 8);
    return(height);
}

void draw_tower(int height)
{
    int spaces;
    int blocks = 1;
    while (blocks <= height)
    {
        spaces = height - blocks;
        for (int i=0;i<spaces;i++)
        {
            printf(" ");
        }
        for (int i=0;i<blocks;i++)
        {
            printf("#");
        }
        printf("  ");
        for (int i=0;i<blocks;i++)
        {
            printf("#");
        }
        printf("\n");
        blocks++;
    }
}
