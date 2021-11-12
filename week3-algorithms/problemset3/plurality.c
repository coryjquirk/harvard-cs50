#include <cs50.h>
#include <stdio.h>
#include <string.h>

#define MAX 9

typedef struct
{
    string name;
    int votes;
}
candidate;

//array of candidate structs
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }
    print_winner();
}

bool vote(string name)
{
    //if name matches a candidate in election, update count of that candidate's votes.
    //check candidates list for each cast vote to verify they're in the race.
    for (int i = 1; i < candidate_count + 1; i++)
    {
        //i starts at 1 due to argv[i+1] above where the candidates array is populated.
        //strcmp: 1 means different, 0 means same (?? dumb)
        bool namesEqual = (strcmp(name, candidates[i-1].name));
        if (!namesEqual){
            candidates[i-1].votes++;
            return true;
        }
    }
    return false;
}

void print_winner(void)
{
    //print winner(s) with highest # of votes on their own line.
    int highScore = 0;
    for (int i = 1; i < candidate_count + 1; i++)
    {
        //check for highest vote count
        if (candidates[i-1].votes > highScore)
        {
            highScore = candidates[i-1].votes;
        }
    }
    for (int i = 1; i < candidate_count + 1; i++)
    {
        //print candidates matching highest vote count
        if (candidates[i-1].votes == highScore)
        {
            printf("%s\n", candidates[i-1].name);
        }
    }
    return;
}