#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
// function to calculate the score
int calculate_score(string word)
{
    int score = 0;
    // define the points values
    int points[26] = {1, 3, 3, 2,  1, 4, 2, 4, 1, 8, 5, 1, 3,
                      1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
    for (int i = 0; i < strlen(word); i++)
    {
        char letter = toupper(word[i]); // convert to uppercase
        if (letter >= 'A' && letter <= 'z')
        {
            score += points[letter - 'A'];
        }
    }
    return score;
}

int main(void)
{
    // prompt play 1
    string player1_word = get_string("Player 1: ");
    // prompt play 2
    string player2_word = get_string("player 2: ");

    // calculate scores
    int player1_score = calculate_score(player1_word);
    int player2_score = calculate_score(player2_word);

    // determine the winner
    if (player1_score > player2_score)
    {
        printf("player 1 wins");
    }
    else if (player2_score > player1_score)
    {
        printf("player 2 wins");
    }
    else
    {
        printf("Tie!\n");
    }
}
