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

typedef enum {lost=0, won=1, tie=2} result;
typedef enum {rock=1, paper=2, scissor=3} move;

bool valid_input(int);
move get_input(void);
move get_random(move);
result determine_winner(move, move);
char* determine_move_as_string(move);

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
    else if (user == computer) {
        return tie;
    }
  
    return lost;
}

move get_random(move player_move)
{
    // reset rand to the current time
    srand(time(0));
    return (rand() % 3) + 1;;
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

char* determine_move_as_string(move _move_) {
    if (_move_ == rock) {
        return "rock";
    }
    else if (_move_ == paper) {
        return "paper";
    }
    
    return "scissor";
}

int main (int argc, char* argv[]) {
    printf("Hello Player: %s\n", argv[1]);
    move player_move = get_input();
    move computer_move = get_random(player_move);
    result res = determine_winner(player_move, computer_move);
    
    if (res == tie) {
        printf("It was a tie!\n");
    }
    else if (res == won) {
        printf("%s won!\n", argv[1]);
    }
    else printf("Computer chose %s, %s beats %s. You lost :(\n",
                determine_move_as_string(computer_move),
                determine_move_as_string(computer_move),
                determine_move_as_string(player_move));
    
    return 0;
}
