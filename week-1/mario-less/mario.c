#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    // prompt user for pyramid height
    do
    {
        height = get_int("height of the pyramid:");
    }
    while (height < 1 || height > 8); // ensure height (between 1 and 8)

    // create the pyramid
    for (int row = 0; row < height; row++)
    // print spaces
    {
        for (int space = 0; space < height - row - 1; space++)

        {
            printf(" ");
        }
        // print hashes
        for (int hash = 0; hash < row + 1; hash++)
        {
            printf("#");
        }
        // move to the next line after each row
        printf("\n");
    }
}
