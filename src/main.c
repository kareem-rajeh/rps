#include <stdio.h>      // for printf and scanf
#include <stdbool.h>    // for bool
#include <stdlib.h>     // includes rand
#include <time.h>       // includes current time

/*
 1. Get users input
 2. Make sure it is rock/paper/scissor (validate input)
 3. Generate random from computer (value between 1-3)
 4. Compare computer with user
    - rock beats scissor
    - paper beats rock
    - scissor beats paper
 */

typedef enum {lost=0, won=1} result;
typedef enum {rock=1, paper=2, scissor=3} move;

bool valid_input(int move);
move get_input(void);
move get_random(void);
result determine_winner(move user, move computer);

// returning won if user won else lost
result determine_winner(move user, move computer) {
    if (user == rock && computer == scissor)
    {
        return won;
    }
    else if (user == paper && computer == rock)
    {
        return won;
    }
    else if (user == scissor && computer == paper)
    {
        return won;
    }
  
    return lost;
}

move get_random(void)
{
    // reset rand to the current time
    srand(time(0));
    return (rand() % 3) + 1;
}


move get_input(void)
{
    int _move = 0;
    char input;
    do {
        printf("Enter a move (r/p/s): ");
        scanf("%c", &input);
        
        if (input == 'r') {
            _move = rock;
        }
        else if (input == 'p') {
            _move = paper;
        }
        else if (input == 's') {
            _move = scissor;
        }
        else _move = 0;
    } while (!valid_input(_move));
    
    
    return _move;
}


bool valid_input(int _move) {
    if (_move == 0) {
        return false;
    }
    return true;
}


int main (int argc, char* argv[]) {
    printf("Hello Player: %s\n", argv[1]);
    move player_move = get_input();
    move computer_move = get_random();
    result winner = determine_winner(player_move, computer_move);
    
    if (winner) {
        printf("%s won!\n", argv[1]);
    }
    else printf("You lost :(\n");
    
    return 0;
}
