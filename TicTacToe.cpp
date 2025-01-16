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
void drawGuide();
void drawBoard(char *spaces);
void playerMove(char *spaces);
void computerMove(char *spaces);
bool checkWinner(char *spaces);
bool checkTie(char *spaces);

int main() {
    
    char spaces[9] = { ' ', ' ', ' ', ' ', ' ',' ', ' ', ' ', ' '};
    bool running = true;

    drawGuide();

    while(running) {
        playerMove(spaces);
        drawBoard(spaces);
        running = !checkWinner(spaces);
        std::cout << "\n\nComputer's Turn:\n";
        computerMove(spaces);
        drawBoard(spaces);
        running = !checkWinner(spaces);
        
    }
    std::cout << "\nThanks for playing!";
    return 0;
}
void drawGuide() {
    std::cout << "     |     |     " << '\n'; //print statement and new line
    std::cout << "  1  |  2  |  3  " << '\n';
    std::cout << "_____|_____|_____" << '\n';
    std::cout << "     |     |     " << '\n'; 
    std::cout << "  4  |  5  |  6  " << '\n';
    std::cout << "_____|_____|_____" << '\n';
    std::cout << "     |     |     " << '\n';
    std::cout << "  7  |  8  |  9  " << '\n';
    std::cout << "     |     |     " << '\n';
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
    
}void computerMove(char *spaces) {
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
bool checkWinner(char *spaces) {
    if(spaces[0] != ' ' && spaces[0] == spaces[1] && spaces[0] == spaces[2]) {
        spaces[0] == 'X' ? std::cout << "YOU WIN!" : std::cout << "YOU LOSE!"; //if else statement
    } else if(spaces[3] != ' ' && spaces[3] == spaces[4] && spaces[3] == spaces[5]) {
        spaces[3] == 'X' ? std::cout << "YOU WIN!" : std::cout << "YOU LOSE!"; 
    } else if(spaces[6] != ' ' && spaces[6] == spaces[7] && spaces[6] == spaces[8]) {
        spaces[6] == 'X' ? std::cout << "YOU WIN!" : std::cout << "YOU LOSE!";
    } else if(spaces[0] != ' ' && spaces[0] == spaces[3] && spaces[0] == spaces[6]) {
        spaces[0] == 'X' ? std::cout << "YOU WIN!" : std::cout << "YOU LOSE!"; 
    } else if(spaces[1] != ' ' && spaces[1] == spaces[4] && spaces[1] == spaces[7]) {
        spaces[1] == 'X' ? std::cout << "YOU WIN!" : std::cout << "YOU LOSE!"; 
    } else if(spaces[2] != ' ' &&  spaces[2] == spaces[5] && spaces[2] == spaces[8]) {
        spaces[2] == 'X' ? std::cout << "YOU WIN!" : std::cout << "YOU LOSE!"; 
    } else if(spaces[0] != ' ' && spaces[0] == spaces[4] && spaces[4] == spaces[8]) {
        spaces[0] == 'X' ? std::cout << "YOU WIN!" : std::cout << "YOU LOSE!"; 
    } else if(spaces[2] != ' ' && spaces[2] == spaces[4] && spaces[2] == spaces[6]) {
        spaces[2] == 'X' ? std::cout << "YOU WIN!" : std::cout << "YOU LOSE!"; 
    } else if(checkTie(spaces)) {
        std::cout << "IT'S A TIE!";
        return false;
    } else {
        return false;
    }
    return true;

}
bool checkTie(char *spaces){
    for(int i = 0; i < 9; i++) {
        if(spaces[i] == ' ') {
            return false;
        }
    }
    return true;

}
