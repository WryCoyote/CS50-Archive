#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
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

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    // TODO
    int i = 0;
    while (i < candidate_count)
    {
        //printf("testCandidate[%i]: %s, name: %s\n", i, candidates[i].name, name);
        if (candidates[i].name != 0)
        {
            if (strcmp(candidates[i].name, name) == 0)
            {
                //printf("namesTrue: %s \n", candidates[i].name);
                candidates[i].votes++;
                //printf("votes: %i \n", candidates[i].votes);
                return true;
            }
        }
        //printf("hello i:%i\n", i);
        i++;
    }
    //printf("bye\n");
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    // TODO
    int pos = 0;
    //int pos1 = 0;
    int voteCheck = 0;
    int voteCheck1 = 0;
    for (int i = 0; i < candidate_count; i++)
    {

        //if(candidates[i].name!=0){
        //printf("testCandidate[%i]: %s\n", i, candidates[i].name);
        //printf("testVote[%i]: %i\n", i, candidates[i].votes);

        if (candidates[i - 1].votes < candidates[i].votes)
        {
            pos = i;
            voteCheck = candidates[i].votes;
            //printf("pos>: %i\n", pos);
        }
        else if (candidates[i - 1].votes == candidates[i].votes)
        {
            //pos1 = i;
            voteCheck1 = candidates[i].votes;
            //printf("voteCheck1=: %i\n", voteCheck1);
        }
        //}
    }

    if (voteCheck > voteCheck1)
    {
        //printf("printing pos%i \n", pos);
        printf("%s\n", candidates[pos].name);
    }
    else
    {
        //printf("printing1 \n");
        for (int j = 0; j < candidate_count; j++)
        {
            //printf("printing pos2 \n");
            if (voteCheck1 == candidates[j].votes)
            {
                //printf("printing pos3 \n");
                printf("%s\n", candidates[j].name);
            }
        }
    }

    return;
}