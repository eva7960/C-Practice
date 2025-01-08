#include <iostream>
#include <ctime>
/**
 * A Tic-Tac-Toe program done in C++ created
 * to help me learn C++ syntax
 * 
 * @author Eva Howard
 * @version 1.0 1/7/25
 */
//function signatures
void drawBoard(char *spaces);
void playerMove(char *spaces, char player);
void computerMove(char *spaces, char computer);
bool checkWinner(char *spaces, char player, char computer);
bool checkTie(char *spaces);

int main() {
    
    char spaces[9] = { ' ', ' ', ' ', ' ', ' ',' ', ' ', ' ', ' '};
    char player = 'X';
    char computer = 'O';
    bool running = true;

    drawBoard(spaces);

    while(running) {
        playerMove(spaces, player);
        drawBoard(spaces);
        computerMove(spaces, computer);
        drawBoard(spaces);
    }
    return 0;
}

void drawBoard(char *spaces) {
    std::cout << "     |     |     " << '\n'; //print statement and new line
    std::cout << "  " << spaces[0] << "  |  " << spaces[1] << "  |   " << spaces[2] << "  " << '\n';
    std::cout << "_____|_____|_____" << '\n';
    std::cout << "     |     |     " << '\n'; 
    std::cout << "  " << spaces[3] << "  |  " << spaces[4] << "  |   " << spaces[5] << "  " << '\n';
    std::cout << "_____|_____|_____" << '\n';
    std::cout << "     |     |     " << '\n';
    std::cout << "  " << spaces[6] << "  |  " << spaces[7] << "  |   " << spaces[8] << "  " << '\n';
    std::cout << "     |     |     " << '\n';
}
void playerMove(char *spaces) {
    int number;
    do {
        std::cout << "Enter a spot to place a marker (1-9): ";
        std::cin >> number;
        number--;
        if(spaces[number] == ' ') {
            spaces[number] = 'X';
            break;
        }
    } while (!number > 0 || !number < 8);

}
void computerMove(char *spaces) {
    int number;
    srand(time(0)); // generate random number
    while(true) {
        number = rand() % 9;
        if(spaces[number] == ' ') {
            spaces[number] = 'O';
            break;
        }
    }

}
bool checkWinner(char *spaces, char player, char computer) {
    if(spaces[0] == spaces[1] && spaces[1] == spaces[2]) {

    }
    return true;

}
bool checkTie(char *spaces){

    return true;

}