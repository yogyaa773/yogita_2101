#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Player {
    int jerseyNumber;
    char name[50];
    int runs;
    int wickets;
    int matches;
};

struct Player *Players = NULL;  // dynamic array
int PlayerCount = 0;

void initializePlayers();
void addPlayer();
void removePlayer();
void searchPlayer();
void updatePlayer();
void displayALLPlayers();
void displaysortedPlayers();
void displayTopPlayersByRuns();
void displayTopPlayersByWickets();
void sortByRunsDescending();
void sortByWicketsDescending();

int main() {
    int choice;
    initializePlayers();

    do {
        printf("\n........Player Management System........");
        printf("\n1. Add Player");
        printf("\n2. Remove Player");
        printf("\n3. Search Player (by jersey or name)");
        printf("\n4. Update Player");
        printf("\n5. Display All Players");
        printf("\n6. Display Sorted Players (Top 3 by Runs & Wickets)");
        printf("\n7. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addPlayer(); break;
            case 2: removePlayer(); break;
            case 3: searchPlayer(); break;
            case 4: updatePlayer(); break;
            case 5: displayALLPlayers(); break;
            case 6: displaysortedPlayers(); break;
            case 7:
                printf("\nExiting program...");
                free(Players); // free allocated memory
                break;
            default:
                printf("\nInvalid choice! Try again.");
        }
    } while (choice != 7);

    return 0;
}

void initializePlayers() {
    struct Player initial[] = {
        {7,"MS Dhoni",5243,1,264},
        {31,"Ruturaj Gaikwad",2502,0,71},
        {8,"Ravindra Jadeja",4876,1,535},
        {88,"Devon Conway",1080,0,29},
        {25,"Shivam Dube",1859,5,79},
        {17,"Rachin Ravindra",413,0,18},
        {90,"Deepak Chahar",117,88,95},
        {81,"Matheesha Pathirana",0,47,32},
        {15,"Noor Ahmad",20,48,37},
        {58,"Sam Curran",997,59,64},
        {59,"Vijay Shankar",1233,9,78}
    };
    int count = sizeof(initial)/sizeof(initial[0]);

    Players = (struct Player *)malloc(count * sizeof(struct Player));
    if (Players == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
     int i;
    for ( i = 0; i < count; i++) {
        Players[i] = initial[i];
        PlayerCount++;
    }
}

void addPlayer() {
    struct Player P;

    printf("\nEnter jersey number: ");
    scanf("%d", &P.jerseyNumber);
    printf("Enter name: ");
    scanf("%s", P.name);
    printf("Enter runs: ");
    scanf("%d", &P.runs);
    printf("Enter wickets: ");
    scanf("%d", &P.wickets);
    printf("Enter matches: ");
    scanf("%d", &P.matches);

    Players = (struct Player *)realloc(Players, (PlayerCount + 1) * sizeof(struct Player));
    if (Players == NULL) {
        printf("Memory reallocation failed!\n");
        exit(1);
    }

    Players[PlayerCount++] = P;
    printf("\nPlayer added successfully!\n");
}

void removePlayer() {
    int jersey, found = 0;
    printf("\nEnter jersey number to remove: ");
    scanf("%d", &jersey);
     int i;
     int j;
    for ( i = 0; i < PlayerCount; i++) {
        if (Players[i].jerseyNumber == jersey) {
            for ( j = i; j < PlayerCount - 1; j++) {
                Players[j] = Players[j + 1];
            }
            PlayerCount--;
            found = 1;
            Players = realloc(Players, PlayerCount * sizeof(struct Player));
            printf("\nPlayer removed successfully!\n");
            break;
        }
    }

    if (!found)
        printf("\nPlayer not found!\n");
}

void searchPlayer() {
    int option, found = 0;
    int i;
    printf("\nSearch by: 1. Jersey Number  2. Name\nEnter choice: ");
    scanf("%d", &option);

    if (option == 1) {
        int jersey;
        printf("Enter jersey number: ");
        scanf("%d", &jersey);
        for (i = 0; i < PlayerCount; i++) {
            if (Players[i].jerseyNumber == jersey) {
                printf("\nFound: %s | Runs: %d | Wickets: %d | Matches: %d\n",
                       Players[i].name, Players[i].runs, Players[i].wickets, Players[i].matches);
                found = 1;
                break;
            }
        }
    } else if (option == 2) {
        char name[50];
        printf("Enter name: ");
        scanf("%s", name);
        for ( i = 0; i < PlayerCount; i++) {
            if (strcmp(Players[i].name, name) == 0) {
                printf("\nFound: %s | Runs: %d | Wickets: %d | Matches: %d\n",
                       Players[i].name, Players[i].runs, Players[i].wickets, Players[i].matches);
                found = 1;
                break;
            }
        }
    }

    if (!found)
        printf("\nPlayer not found!\n");
}

void updatePlayer() {
    int jersey, found = 0;
    int i;
    printf("\nEnter jersey number to update: ");
    scanf("%d", &jersey);

    for ( i = 0; i < PlayerCount; i++) {
        if (Players[i].jerseyNumber == jersey) {
            printf("Enter new runs: ");
            scanf("%d", &Players[i].runs);
            printf("Enter new wickets: ");
            scanf("%d", &Players[i].wickets);
            printf("Enter new matches: ");
            scanf("%d", &Players[i].matches);
            printf("\nPlayer data updated successfully!\n");
            found = 1;
            break;
        }
    }

    if (!found)
        printf("\nPlayer not found!\n");
}

void displayALLPlayers() 
  {int i;
    if (PlayerCount == 0) {
        printf("\nNo players to display!\n");
        return;
    }

    printf("\nAll Players:\n");
    for (i = 0; i < PlayerCount; i++) {
        printf("Jersey: %d | Name: %s | Runs: %d | Wickets: %d | Matches: %d\n",
               Players[i].jerseyNumber, Players[i].name, Players[i].runs,
               Players[i].wickets, Players[i].matches);
    }
}

void displaysortedPlayers() {
    displayTopPlayersByRuns();
    displayTopPlayersByWickets();
}

void displayTopPlayersByRuns() {
     int i;
    sortByRunsDescending();
    printf("\nTop 3 Players by Runs:\n");
    for (i = 0; i < PlayerCount && i < 3; i++) {
        printf("%s : %d runs\n", Players[i].name, Players[i].runs);
    }
}

void displayTopPlayersByWickets() {
     int i;
    sortByWicketsDescending();
    printf("\nTop 3 Players by Wickets:\n");
    for ( i = 0; i < PlayerCount && i < 3; i++) {
        printf("%s : %d wickets\n", Players[i].name, Players[i].wickets);
    }
}

void sortByRunsDescending() {
     int i,j;
    for (i = 0; i < PlayerCount - 1; i++) {
        for ( j = i + 1; j < PlayerCount; j++) {
            if (Players[j].runs > Players[i].runs) {
                struct Player temp = Players[i];
                Players[i] = Players[j];
                Players[j] = temp;
            }
        }
    }
}

void sortByWicketsDescending() {
     int i,j;
    for ( i = 0; i < PlayerCount - 1; i++) {
        for ( j = i + 1; j < PlayerCount; j++) {
            if (Players[j].wickets > Players[i].wickets) {
                struct Player temp = Players[i];
                Players[i] = Players[j];
                Players[j] = temp;
            }
        }
    }
}
