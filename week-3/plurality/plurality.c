#include <cs50.h>
#include <stdio.h>
#include <string.h>

#define Max 9

typedef struct
{
    string name;
    int votes;
} candidate;

candidate candidates[Max];
int candidate_count;

bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{ // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality[candidate ...]\n");
        return 1;
    }
    candidate_count = argc - 1;
    if (candidate_count > Max)
    {
        printf("maximum number of candidates is %i\n", Max);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }
    int voter_count = get_int("number of voters: ");

    if (voter_count <= 0)
    {
        printf("No voters registered.\n");
        return 0;
    }

    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        if (!vote(name))
        {
            printf("Invalid vote. Valid candidates are: ");
            for (int j = 0; j < candidate_count; j++)
            {
                printf("%s ", candidates[j].name);
            }
            printf("\n");
        }
    }

    print_winner();
}
// Check if the candidate exists and update votes
bool vote(string name)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i].name, name) == 0)
        {
            candidates[i].votes++;
            return true;
        }
    }

    return false;
}

void print_winner(void)
{
    int maxvotes = 0;

    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes > maxvotes)
        {
            maxvotes = candidates[i].votes;
        }
    }
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == maxvotes)
        {
            printf("%s\n", candidates[i].name);
        }
    }
}
