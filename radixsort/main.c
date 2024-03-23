#include <stdio.h>
#include <stdlib.h>
typedef struct teamNode // Node for team
{
    Str name;
    Str code;
    int noOfWins;
    int noOfDraws;
    int noOfLoses;
    int goalsDifference;
    int points;
    struct teamNode *Next;
} Team;


void printTeamInfo(Team *L)// Print all information of the teams
{
    Team *P;
    P = L->Next;// To indicate to the next node
    if (L->Next == NULL)
        printf("Empty list\n");// There is no information
    else
        while (P != NULL)//To indicate to the next node until it's equal NULL
        {
            printf("Name: %s\tCode:%s\tnoOfWins:%d\t noOfDraws: %d\t noOfLoses: %d\t GoalsDiffrence:%d\t points:%d\n",
                   P->name, P->code, P->noOfWins, P->noOfDraws, P->noOfLoses, P->goalsDifference, P->points);// Printing all information
            P = P->Next;// Indicate to the next node
        }
}
void sort(Team *L)


{



}

int main()
{

    Team *L;
    L = (Team *)malloc(sizeof(Team));// Reserve a space
    L->Next = NULL;// The next of the header node is NULL

    printf("Hello world!\n");
    return 0;
}
