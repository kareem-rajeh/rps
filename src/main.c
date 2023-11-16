#include <stdio.h>
#include <stdbool.h>

/*
 1. Get users input
 2. Make sure it is rock/paper/scissor (validate input)
 3. Generate random from computer (value between 1-3)
 4. Compare computer with user
    - rock beats scissor
    - paper beats rock
    - sissor beats paper
 */

enum moves {rock=1, paper=2, scissor=3};

bool valid_input(int move);
int get_input(void);

int get_input(void)
{
    int move = 0;
    char input;
    do {
        printf("Enter a move (r/p/s): ");
        scanf("%c", &input);
        
        if (input == 'r') {
            move = rock;
        }
        else if (input == 'p') {
            move = paper;
        }
        else if (input == 's') {
            move = scissor;
        }
        else move = 0;
    } while (!valid_input(move));
    
    
    return move;
}

bool valid_input(int move) {
    if (move == 0) {
        return false;
    }
    return true;
}



int main (int argc, char* argv[]) {
    printf("%s\n", argv[1]);
    
    return 0;
}
