#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
// Mohammad Abu Shams
// 1200549
typedef struct String
{
    char string[100];
} Str;

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

typedef struct playerNode // Node for player
{
    Str name;
    struct playerNode *Next;
} Player;

Team *findTeam(Team *, Str);
Player *findPreviousPlayer(Player *, Str);

int main()
{
    Team *L;
    L = (Team *)malloc(sizeof(Team)); // Reserve a space
    L->Next = NULL;                   // The next of the header node is NULL
    Player **P, **Q;

    int numberofteams;
    while (1)
    {
        printf("\n Please select an option\n"); // Printing all lists
        printf("1- Read the file teams.txt\n");
        printf("2- calculate the points\n");
        printf("3- sort the teams\n");
        printf("4- add a team\n");
        printf("5- delete a team\n");
        printf("6- modify a team\n");
        printf("7- printing all teams with their relevant information \n");
        printf("8- Save back the teams information (sorted) to the file teamsInfo.txt\n");
        printf("9- create a match\n");
        printf("10- Exit\n");

        int y;
        scanf("%d", &y); // Enter the number you want
        switch (y)
        {
        case 1:
        {
            numberofteams = readfromfile(L); // Called the function to find number of teams

            P = (Player **)malloc(sizeof(Player *) * numberofteams); // Create array of linked list, each team has linked list so we need array to all teams
            Q = (Player **)malloc(sizeof(Player *) * numberofteams); // Create array of queue, each team has queue so we need array to all teams
        }
        break;

        case 2:
        {
            calculatepoints(L); // Called the function to find the points
            printf("Done\n");
        }
        break;
        case 3:
        {
            calculatepoints(L); // Called the function calculate the poitns
            int n = 0;          // The number of digits of max number of the team's points
            Team *temp;
            temp = L->Next;      // The first team in the linked list
            int max = 0;         // max of the points has an initial value of 0
            while (temp != NULL) // If the linked list not empty and have a team
            {
                if (temp->points > max) // To find the max number of the points
                    max = temp->points;
                temp = temp->Next; // To indicate to the next team
            }
            while (max != 0)
            {              // If the linked list not empty and have a team
                n++;       // Increment the number of max digit
                max /= 10; // To find the reminder of the max digit
            }
            sort(L, n);             //  Called the function to sort the points using Raddix sort
            checkGoalDifference(L); // Called the function checkGoalDifference
        }

        break;
        case 4:
        {
            Str name;
            Str code;
            int noOfWins;
            int noOfDraws;
            int noOfLoses;
            int goalsDifference;
            printf("Enter Name:"); // Enter all informations about the teams
            scanf("%s", name.string);
            printf("Enter code:");
            scanf("%s", code.string);
            printf("Enter noOfWins:");
            scanf("%d", &noOfWins);
            printf("Enter noOfDraws:");
            scanf("%d", &noOfDraws);
            printf("Enter noOfLoses:");
            scanf("%d", &noOfLoses);
            printf("Enter goalsDifference:");
            scanf("%d", &goalsDifference);

            addteam(L, name, code, noOfWins, noOfDraws, noOfLoses, goalsDifference); // Called the function to add the team
            printf("Team Added\n");
        }
        break;
        case 5:
        {
            Str code;

            printf("Enter code:");
            scanf("%s", code.string);
            deleteteam(L, code); // Called the function to delete a team
        }
        break;
        case 6:
        {
            Str name;
            Str code;
            Str searchCode;
            int noOfWins;
            int noOfDraws;
            int noOfLoses;
            int goalsDifference;
            printf("Enter Code:");
            scanf("%s", searchCode.string);
            Team *t = findTeam(L, searchCode);
            if (t != NULL)
            {
                printf("Update:\n");
                printf("Enter Name:");
                scanf("%s", name.string);
                printf("Enter code:");
                scanf("%s", code.string);
                printf("Enter noOfWins:");
                scanf("%d", &noOfWins);
                printf("Enter noOfDraws:");
                scanf("%d", &noOfDraws);
                printf("Enter noOfLoses:");
                scanf("%d", &noOfLoses);
                printf("Enter goalsDifference:");
                scanf("%d", &goalsDifference);
            }

            modifyteam(L, searchCode, name, code, noOfWins, noOfDraws, noOfLoses, goalsDifference); // Called the function to modifyteam
        }
        break;

        case 7:
        {
            printTeamInfo(L); // Printing all information.
        }
        break;

        case 8:
        {
            int n = 0;
            Team *temp;
            temp = L->Next;
            int max = 0;
            while (temp != NULL)
            {
                if (temp->points > max) // To find the max number
                    max = temp->points;
                temp = temp->Next; // To indicate to the next node
            }
            while (max != 0)
            {
                n++;
                max /= 10; // To find the reminder
            }
            sort(L, n);        //  Called the function to sort the points using raddix sort
            saveteamtofile(L); // Save the information into the output file
            checkGoalDifference(L);
        }
        break;
        case 9:
        {
            Team *temp;
            Str firstTeam, secodeTeam;
            printf("Enter first team code:");
            scanf("%s", firstTeam.string);
            temp = findTeam(L, firstTeam);
            if (temp != NULL) // Check if the first team found
            {
                printf("First Team is %s\n", temp->name.string);
                printf("Enter second team code:");
                scanf("%s", secodeTeam.string);
                temp = findTeam(L, secodeTeam);
                if (temp != NULL) // Check if the second team found
                {
                    printf("Second Team is %s\n", temp->name.string);

                    while (1)
                    {
                        printf("\n Please select an option\n"); // Keep printing the list after each selection
                        printf("1- Read Players list\n");
                        printf("2- Change Player\n");
                        printf("3- Give a red card\n");
                        printf("4- Print all elementary players for a team\n");
                        printf("5- print information to file\n");
                        printf("6- end match\n");

                        int x;
                        scanf("%d", &x); // Enter the number you want
                        switch (x)
                        {
                        case 1:
                        {
                            readPlayers(P, Q); // Called the function to read player's information
                        }
                        break;
                        case 2:
                        {
                            Str playerName, team;
                            printf("Enter team code:");
                            scanf("%s", team.string);
                            printf("Enter Player name:");
                            scanf("%s", playerName.string);
                            changeplayers(P, Q, team, playerName, numberofteams); // Called the function to put players in the queue and linked list
                        }
                        break;
                        case 3:
                        {
                            Str playerName, team;
                            printf("Enter team code:");
                            scanf("%s", team.string);
                            printf("Enter Player name:");
                            scanf("%s", playerName.string);
                            deletePlayer(P, team, playerName, numberofteams); // Function to give player a red card
                            printf("Done\n");
                        }
                        break;
                        case 4:
                        {
                            Str code;
                            printf("Enter  team code:");
                            scanf("%s", code.string);
                            printElementaryPlayers(P, code, numberofteams); // Function to print the players
                        }
                        break;

                        case 5:
                        {
                            savePlayersToFile(P, Q, numberofteams); // Function to save the information to the file
                            printf("Done\n");
                        }
                        break;
                        case 6:
                        {
                            goto exitLoop; // Branch to the exitloop
                        }
                        break;

                        default:
                            break;
                        }
                    }
                exitLoop:;
                }
                else
                    printf("Team not Found!\n");
            }
            else
                printf("Team not Found!\n");
        }
        break;
        case 10:
        {
            exit(0); // Exit the program
        }
        break;

        default:
        {
            printf("Please enter the numbers between 1-10"); // When the user entered number not between 1-15
        }
        }
    }
    return 0;
}
void trim(char *str) // Remove all first and last spaces from the string
{
    int len = strlen(str);                           // The length of the string
    while (isspace(str[0]) || isspace(str[len - 1])) // While always there is a spaces in the first and in the last
    {
        if (isspace(str[0]))              // Check if the first character is space
            for (int j = 0; j < len; j++) // Delete the space and shift the string to the left
            {
                str[j] = str[j + 1];
            }
        if (isspace(str[len - 1])) // Check if last character is space
            str[len - 1] = '\0';
    }
}
int readfromfile(Team *L) // Read teams information and return number of teams
{
    FILE *team;
    team = fopen("teams.txt", "r");
    char *token, temp[300];
    int i;
    int countteams = 0;
    while (fgets(temp, 300, team)) // Read the data from the file line by line
    {

        trim(temp);
        token = strtok(temp, ","); // Split the line into tokens according to ,
        Str name;
        Str code;
        int noOfWins;
        int noOfDraws;
        int noOfLoses;
        int goalsDifference;
        int count = 0;
        while (token != NULL) // Assign each token to it's field
        {
            if (count == 0)
            {
                strcpy(name.string, token); // Assign name token to name
                trim(name.string);          // To delete spaces
            }
            else if (count == 1)
            {

                strcpy(code.string, token); // Assign code token to code
                trim(code.string);          // To delete spaces
            }

            else if (count == 2)
            {
                noOfWins = atoi(token); // Assign number of wins then convert it to integers
            }

            else if (count == 3)
            {
                noOfDraws = atoi(token); // Assign number of draws then convert it to integers
            }

            else if (count == 4)
            {
                noOfLoses = atoi(token); // Assign number of loses then convert it to integers
            }

            else if (count == 5)
            {
                goalsDifference = atoi(token); // Assign goals difference then convert it to integers
            }

            token = strtok(NULL, ","); // To separate the next token.
            count++;
        }
        countteams++;

        addteam(L, name, code, noOfWins, noOfDraws, noOfLoses, goalsDifference); // Called the function add
    }

    printf("Done\n");
    fclose(team);      // Closed the file
    return countteams; // Return number of teams
}

void addteam(Team *L, Str name, Str code, int noOfWins, int noOfDraws, int noOfLoses, int goalsDifference) // Add new team with it's information
{

    Team *newnode, *temp;
    newnode = (Team *)malloc(sizeof(Team));
    newnode->Next = NULL;

    strcpy(newnode->name.string, name.string); // Adding the informations of the team

    strcpy(newnode->code.string, code.string);

    newnode->noOfWins = noOfWins;
    newnode->noOfDraws = noOfDraws;
    newnode->noOfLoses = noOfLoses;
    newnode->goalsDifference = goalsDifference;
    newnode->points = -1;
    temp = L->Next;        // To indicate to the next node
    if (temp == NULL)      // If list is empty
        L->Next = newnode; // To add after first node
    else
    {
        while (temp->Next != NULL) // Find the last node
        {
            temp = temp->Next; // Indicate to the next node
        }
        temp->Next = newnode; // Insert at last
    }
}

void calculatepoints(Team *L) // Calculate the points for the teams
{

    Team *temp;
    temp = L->Next;                         // To indicate to the next node
    for (; temp != NULL; temp = temp->Next) // To indicate to the next node until it's equal NULL
    {
        temp->points = 3 * temp->noOfWins + 1 * temp->noOfDraws;
    }
}

void sort(Team *L, int n)
{ // Sorting the points decending using Raddix sort
    Team *s = L;
    Team *p;
    Team *w;
    Team *a[10]; // Array of linked list
    int x = 1;   // To divisor by 1 in the first
    for (int j = 0; j < n; j++)
    { // For loop start until the number of digits

        for (int i = 0; i < 10; i++)
        {                                        // Array of linked list
            a[i] = (Team *)malloc(sizeof(Team)); // Reserved a space in memory
            a[i]->Next = NULL;                   // The next of the array of linked list equal NULL
        }
        s = L->Next; // The first team in the linked list L
        while (s != NULL)
        {                                           // If there is a team
            p = (Team *)malloc(sizeof(Team));       // Reserved a space in memory
            strcpy(p->name.string, s->name.string); // Copy the information of the teams
            strcpy(p->code.string, s->code.string);
            p->noOfWins = s->noOfWins;
            p->noOfDraws = s->noOfDraws;
            p->noOfLoses = s->noOfLoses;
            p->goalsDifference = s->goalsDifference;
            p->points = s->points;
            p->Next = a[(p->points / x) % 10]->Next; // This TEAM indicate to the next team, and find the digit of the team's point
            // The first team of this element of array
            a[(p->points / x) % 10]->Next = p; // The next of the array of linked list indicate to the TEAM
            s = s->Next;                       // To indicate to the next team
        }

        L->Next = NULL; // Make the linked list empty (remove all items)
        for (int i = 0; i < 10; i++)
        {
            Team *d = a[i]->Next; // The first team of the element
            while (d != NULL)
            {                                           // If there is a team
                w = (Team *)malloc(sizeof(Team));       // Reserved a space in memory
                strcpy(w->name.string, d->name.string); // Copying the information of the teams
                strcpy(w->code.string, d->code.string);
                w->noOfWins = d->noOfWins;
                w->noOfDraws = d->noOfDraws;
                w->noOfLoses = d->noOfLoses;
                w->goalsDifference = d->goalsDifference;
                w->points = d->points;
                w->Next = L->Next; // Insert begin team to L
                L->Next = w;       // the next of the linked list is the team
                d = d->Next;       // To indidate to the next team
            }
        }

        x *= 10; // To divise the another digit
    }
}

void checkGoalDifference(Team *L)
{ // Sort the teams with the same points according to goal difference descending
    Team *temp1, *temp2;
    temp1 = L->Next; // Make the temp1 indicate to the first index

    while (temp1 != NULL)
    {
        temp2 = temp1->Next; // Make the temp2 indicate to the second index
        for (; temp2 != NULL; temp2 = temp2->Next)
        {
            if (temp1->points == temp2->points)
            { // Equal in points
                if (temp1->goalsDifference < temp2->goalsDifference)
                {
                    Team *T = (Team *)malloc(sizeof(Team)); // Reserved a space

                    strcpy(T->name.string, temp1->name.string); // Swapping
                    strcpy(T->code.string, temp1->code.string);
                    T->noOfWins = temp1->noOfWins;
                    T->noOfDraws = temp1->noOfDraws;
                    T->noOfLoses = temp1->noOfLoses;
                    T->goalsDifference = temp1->goalsDifference;
                    T->points = temp1->points;

                    strcpy(temp1->name.string, temp2->name.string);
                    strcpy(temp1->code.string, temp2->code.string);
                    temp1->noOfWins = temp2->noOfWins;
                    temp1->noOfDraws = temp2->noOfDraws;
                    temp1->noOfLoses = temp2->noOfLoses;
                    temp1->goalsDifference = temp2->goalsDifference;
                    temp1->points = temp2->points;

                    strcpy(temp2->name.string, T->name.string);
                    strcpy(temp2->code.string, T->code.string);
                    temp2->noOfWins = T->noOfWins;
                    temp2->noOfDraws = T->noOfDraws;
                    temp2->noOfLoses = T->noOfLoses;
                    temp2->goalsDifference = T->goalsDifference;
                    temp2->points = T->points;
                }
            }
        }
        temp1 = temp1->Next; // To indicate the next team
    }
}

void deleteteam(Team *L, Str code) // Delete a team according to it's code
{
    Team *temp;
    temp = L;
    while (temp->Next != NULL) // To indicate to the next list until it's equal NULL
    {
        if (strcasecmp(temp->Next->code.string, code.string) == 0) // If the code that the user entered equal the code is already exist
        {
            Team *d;
            d = temp->Next;
            temp->Next = d->Next;
            free(d); // Delete the node d
            return;  // Out
        }
        temp = temp->Next; // Indicate to the next node
    }
    printf("Team not Found!");
}

void modifyteam(Team *L, Str searchCode, Str name, Str code, int noOfWins, int noOfDraws, int noOfLoses, int goalsDifference) // Edit the information of the team according to it's code
{

    Team *temp;

    temp = L->Next;            // To indicate to the next node
    while (temp != NULL) // To indicate to the next node until it's equal NULL
    {
        if (strcasecmp(temp->code.string, searchCode.string) == 0) // If the code that the user entered equal the code is already exist
        {
            strcpy(temp->name.string, name.string); // Adding the edit information
            strcpy(temp->code.string, code.string);
            temp->noOfWins = noOfWins;
            temp->noOfDraws = noOfDraws;
            temp->noOfLoses = noOfLoses;
            temp->goalsDifference = goalsDifference;
            return; // Out
        }
        temp = temp->Next; // Indicate to the next node
    }
    printf("Team not found!\n");
}

void printTeamInfo(Team *L) // Print all information of the teams
{
    Team *P;
    P = L->Next; // To indicate to the next node
    if (L->Next == NULL)
        printf("Empty list\n"); // There is no information
    else
        while (P != NULL) // To indicate to the next node until it's equal NULL
        {
            printf("Name: %s\tCode:%s\tnoOfWins:%d\t noOfDraws: %d\t noOfLoses: %d\t GoalsDiffrence:%d\t points:%d\n",
                   P->name, P->code, P->noOfWins, P->noOfDraws, P->noOfLoses, P->goalsDifference, P->points); // Printing all information
            P = P->Next;                                                                                      // Indicate to the next node
        }
}

void saveteamtofile(Team *L) // Save the information to the output file
{
    FILE *output; // Create file
    output = fopen("teamsInfo.txt", "w");
    Team *P = L->Next; // To indicate to the next node
    while (P != NULL)  // To indicate to the next node until it's equal NULL
    {
        fprintf(output, "Name: %s\tCode:%s\tnoOfWins:%d\t noOfDraws: %d\t noOfLoses: %d\t GoalsDiffrence:%d\t points:%d\n",
                P->name, P->code, P->noOfWins, P->noOfDraws, P->noOfLoses, P->goalsDifference, P->points);
        P = P->Next; // Indicate to the next node
    }
    fclose(output); // Closed the file
}

Team *findTeam(Team *L, Str code) // Find the team according to the code
{
    Team *temp;
    temp = L->Next;      // To indicate to the next team
    while (temp != NULL) // There is a team
    {
        if (strcasecmp(temp->code.string, code.string) == 0) // The team that the user added is already exist
            return temp;                                     // Return the team
        temp = temp->Next;                                   // To indicate to the next node
    }
}

void readPlayers(Player **L, Player **Q) // Read players information from the file
{
    FILE *player;                       // Create file
    player = fopen("players.txt", "r"); // Read from the file
    if (player == NULL)                 // Empty file
        printf("File Not Found\n");
    char temp[300];

    int i = -1;
    while (fgets(temp, 300, player)) // Read the data from the file line by line
    {
        char *token;
        Str code;
        Str name;
        int count;
        trim(temp); // Delete spaces
        if (temp[0] == '*')
        {                              // If the first of the line is *
            token = strtok(temp, "*"); // split the line into tokens according to *
            count = 0;
            i++;
            L[i] = (Player *)malloc(sizeof(Player)); // Reseved a space in memory
            L[i]->Next = NULL;                       // The next of the array of linked list is NULL
            Q[i] = (Player *)malloc(sizeof(Player)); // Reseved a space in memory
            Q[i]->Next = NULL;                       // The next of the array of QUEUE is NULL

            strcpy((L[i]->name.string), token); // Saved the team code into the header of linked list
            strcpy((Q[i]->name.string), token); // Saved the team code into the header of queue
        }
        else if (count < 11)
        {                              // The elementary player ( 11 players )
            token = strtok(temp, "-"); // Split the line into tokens according to -
            token = strtok(NULL, "-");
            strcpy(name.string, token);
            addPlayer(L[i], name); // Add the 11 player to the array of linked list ( elementary player )
            count++;               // Increment the count
        }
        else // The spare player
        {
            token = strtok(temp, "-"); // split the line into tokens according to -
            token = strtok(NULL, "-");
            strcpy(name.string, token);
            enqueuePlayer(Q[i], name); // Add the spare players to the array of queue ( spare player )

            count++; // The spare player
        }
    }
    printf("DONE\n");
    fclose(player); // Close the file
}

void addPlayer(Player *L, Str name) // Add players to the linked list
{

    Player *newnode, *temp;
    newnode = (Player *)malloc(sizeof(Player)); // Reserved a space in memory
    newnode->Next = NULL;

    strcpy(newnode->name.string, name.string);

    temp = L;

    while (temp->Next != NULL)
    {
        temp = temp->Next; // Indicate to the next player
    }
    temp->Next = newnode; // Insert player at last
}

void enqueuePlayer(Player *Q, Str name)
{ // Add the players to the queue
    Player *newnode, *temp;
    newnode = (Player *)malloc(sizeof(Player));
    newnode->Next = NULL;

    strcpy(newnode->name.string, name.string);

    temp = Q;

    while (temp->Next != NULL)
    {
        temp = temp->Next; // Indicate to the next player
    }
    temp->Next = newnode; // Insert player at last
}

Str dequeuePlayer(Player *Q) // Remove players from queue
{

    Player *temp;
    temp = Q->Next; // To delete temp
    Q->Next = temp->Next;
    Str s;
    strcpy(s.string, temp->name.string);
    free(temp); // Delete player
    return s;
}

void changeplayers(Player **L, Player **Q, Str team, Str playername, int noOfteams) // Change the player between queue and linked list
{
    if ((L[0]->Next == NULL || Q[0]->Next == NULL))
    {
        printf("No Players Found\n");
        return; // Out of the function
    }
    Player *temp;
    for (int i = 0; i < noOfteams; i++)
    {
        if (strcasecmp((L[i]->name.string), team.string) == 0)
        {
            temp = findPreviousPlayer(L[i], playername); // Find the previous player that removed to become at the beginning of the queue
            if (temp != NULL)
            {
                Player *d;
                d = temp->Next;
                enqueuePlayer(Q[i], d->name);        // insert the player from linked list to queue
                Str name = dequeuePlayer(Q[i]);      // Remove from queue
                strcpy(d->name.string, name.string); // Add the spare player to linked list
                return;                              // Out of the function
            }
            else
            {
                printf("Player not found");
                return; // Out of the function
            }
        }
    }
    printf("Team not Found!\n");
}

Player *findPreviousPlayer(Player *L, Str name) // Find the previous player that removed to become at the beginning of the queue
{
    Player *temp;
    temp = L;
    while (temp->Next != NULL)
    {
        if (strcasecmp(temp->Next->name.string, name.string) == 0)
            return temp;
        temp = temp->Next; // To indicate to the next player
    }
    return NULL;
}

void printElementaryPlayers(Player **P, Str name, int noOfteams) // Print 11 players ( elementary player ) of the team
{
    if ((P[0]->Next == NULL))
    {
        printf("No Player Found\n");
        return; // Out from the function
    }
    Player *temp;
    for (int i = 0; i < noOfteams; i++)
    {
        if (strcasecmp((P[i]->name.string), name.string) == 0)
        {
            temp = (P[i]->Next); // Next player ( first player in the first )
            while (temp != NULL)
            {
                printf("%s\t", temp->name); // Print players
                temp = temp->Next;          // Indicate to the next player
            }
            printf("\n");
            return;
        }
    }
    printf("Team not Found!\n");
}

void deletePlayer(Player **L, Str team, Str playername, int noOfteams) // Delete players from linked list ( give the red card )
{
    if ((L[0]->Next == NULL))
    {
        printf("No Players Found\n");
        return;
    }
    Player *temp;
    for (int i = 0; i < noOfteams; i++)
    {
        if (strcasecmp((L[i]->name.string), team.string) == 0)
        {
            temp = findPreviousPlayer(L[i], playername); // To make the previous node of deleted indicate to the next
            if (temp != NULL)
            {
                Player *d;
                d = temp->Next;
                temp->Next = d->Next;
                free(d); // Delete the node d
                return;
            }
            else
            {
                printf("Player not found");
                return;
            }
        }
    }
    printf("Team not Found!\n");
}

void savePlayersToFile(Player **L, Player **Q, int noOfteams) // Save the information to the output file
{
    FILE *output; // Create output file
    output = fopen("playersInfo.txt", "w");

    if ((L[0]->Next == NULL || Q[0]->Next == NULL))
    {
        return; // Out of the function
    }
    for (int i = 0; i < noOfteams; i++)
    {
        int count = 1;
        fprintf(output, "*%s\n", L[i]->name.string); // Print to the file
        Player *P;
        P = L[i]->Next; // To indicate to the next node
        while (P != NULL)
        {
            fprintf(output, "%d-%s\n", count, P->name.string);
            P = P->Next; // Indicate to the next player
            count++;     // Increment the count
        }
        P = Q[i]->Next;
        while (P != NULL)
        {
            fprintf(output, "%d-%s\n", count, P->name.string);
            P = P->Next; // Indicate to the next player
            count++;     // Increment the count
        }
    }

    fclose(output); // Closed the file
}
