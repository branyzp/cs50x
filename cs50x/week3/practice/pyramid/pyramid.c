#include <stdio.h>
#include <cs50.h>

void draw(int n);

int main (void)
{
    int height = get_int("Height: ");
    draw(height);
}

void draw(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int k = 0; k < i+1; k++)
        {
            printf("#");
        }
        printf("\n");
    }
}
