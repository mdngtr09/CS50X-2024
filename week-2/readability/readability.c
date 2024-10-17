#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int main(void)
{ // get text
    string text = get_string("text: ");
    // start counter
    int letters = 0, words = 1, sentences = 0;

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isalpha(text[i]))
        {
            letters++;
        }
        else if (text[i] == ' ')
        {
            words++;
        }
        else if (text[i] == '.' || text[i] == '!' || text[i] == '?')

        {
            sentences++;
        }
    }

    // calculate l and s
    float L = (float) letters / words * 100;
    float S = (float) sentences / words * 100;
    // calculate
    float index = 0.0588 * L - 0.296 * S - 15.8;
    // level
    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", (int) round(index));
    }
}
