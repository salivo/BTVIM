#include <stdio.h>
#include <stdbool.h> 
#include <string.h>
#include <ncurses.h>

bool verbose = false;


int main(int argc, char* argv[])
{
    printf("You have entered %d arguments:\n", argc-1);
 
    for (int i = 1; i < argc; i++) {
        printf("%s\n", argv[i]);
        if (strcmp(argv[i], "-v") == 0) {
            verbose = true;
        }
    }
    if (verbose){
        printf("Its verbose mode!\n");
    }
    initscr();

    // Get the size of the terminal
    int max_y, max_x;
    getmaxyx(stdscr, max_y, max_x);

    // Draw the top border
    for (int i = 0; i < max_x; i++) {
        mvprintw(0, i, "-");
    }

    // Draw the bottom border
    for (int i = 0; i < max_x; i++) {
        mvprintw(max_y - 1, i, "-");
    }

    // Draw the left border
    for (int i = 0; i < max_y; i++) {
        mvprintw(i, 0, "|");
    }

    // Draw the right border
    for (int i = 0; i < max_y; i++) {
        mvprintw(i, max_x - 1, "|");
    }

    // Refresh the screen to display changes
    refresh();

    // Wait for user input
    getch();

    // Clean up and close the library
    endwin();

    return 0;
}
// that intrasting but for first i try it in python ok