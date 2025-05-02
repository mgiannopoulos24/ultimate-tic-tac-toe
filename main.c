#include <stdio.h>
#include <stdlib.h>
#include "state.h"


// set it as global
big_board bb;

void print_game() {
    printf("\r");
    printf("                   _ _   _                 _                  \n");
    printf("             _   _| | |_(_)_ __ ___   __ _| |_ ___            \n");
    printf("            | | | | | __| | '_ ` _ \\ / _` | __/ _ \\           \n");
    printf("            | |_| | | |_| | | | | | | (_| | ||  __/           \n");
    printf("  _   _      \\__,_|_|\\__|_|_| |_| |_|\\__,_|\\__\\___|           \n");
    printf(" | |_(_) ___          | |_ __ _  ___          | |_ ___   ___  \n");
    printf(" | __| |/ __|  _____  | __/ _` |/ __|  _____  | __/ _ \\ / _ \\ \n");
    printf(" | |_| | (__  |_____| | || (_| | (__  |_____| | || (_) |  __/ \n");
    printf("  \\__|_|\\___|          \\__\\__,_|\\___|          \\__\\___/ \\___| \n");
    printf("\n");
    printf("---------------------------------------------------------------\n");
    printf("       0              1              2       \n");

    print_big_board(bb);


    printf("---------------------------------------------------------------\n");
    printf("Current Player: %s\n", (bb->currentPlayer == PLAYER_X) ? "X" : "O");

    if (bb->status == START) {
        printf("Choose board to start playing: <x> <y>\n");
        int x, y;
        scanf("%d %d", &x, &y);

        if (x < 0 || x > 2 || y < 0 || y > 2) {
            fprintf(stderr, "Invalid coordinate(s).\n");
            return;
        }
    } else {
        int x = bb->smallBoards[bb->last_played->x][bb->last_played->y]->last_played->x, y = bb->smallBoards[bb->last_played->x][bb->last_played->y]->last_played->y;

        if (x == -1 && y == -1) {
            printf("Current Board: Whichever (in progress) board you want! \n");
            printf("Give board you want to play at: <x> <y> \n");
            scanf("%d %d", &x, &y);

            if (x < 0 || x > 2 || y < 0 || y > 2) {
                fprintf(stderr, "Invalid coordinate(s).\n");
                return;
            }

            if (bb->smallBoards[x][y]->status != IN_PROGRESS) {
                fprintf(stderr, "Board is already finished.\n");
                return;
            }

        } else {
            printf("Current Board: (%d, %d)\n", bb->smallBoards[bb->last_played->x][bb->last_played->y]->last_played->x, bb->smallBoards[bb->last_played->x][bb->last_played->y]->last_played->y);
            printf("Insert your move: <x> <y> \n");

            scanf("%d %d", &x, &y);
            
            if (x < 0 || x > 2 || y < 0 || y > 2) {
                fprintf(stderr, "Invalid coordinate(s).\n");
                return;
            }
        }

    }

}

int main() {
    bb = create_big_board();
    print_game();
    return 0;
}