#include <cs50.h>
#include <stdio.h>

void print_pyramid(int height);

int main (void)
{
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);
    print_pyramid(height);
}


void print_pyramid(int height)
{
    for (int row = 1; row <= height; row++)
    {
       // Print left-aligned spaces
       for (int space = 0; space < height - row; space++)
       {
          printf(" ");
       }

       // Print left pyramid
       for(int hash = 0; hash < row; hash++)
       {
        printf("#");
       }

       // Print gap of two spaces
       {
        printf("  ");
       }

       // Print right pyramid
       for(int hash = 0; hash < row; hash++)
       {
        printf("#");
       }

       // move next line
       printf("\n");

    }
}


