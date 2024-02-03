#include "functions.hpp"

using namespace std;

int main (int argc, char* argv[]) {

    string playerOneName = "";
    string playerTwoName = "";
    string playerPosition = "";
    board *theBoard = new board;
    bool validInputUser1;
    bool validInputUser2;
    
    cout << "Welcome to tik tac toe" << endl;
    cout << "======================" << endl;

    cout << "Please enter Player 1 name: (ctrl + c to end) ";
    cin >> playerOneName;
    clearCIN();

    cout << "Please enter Player 2 name: (ctrl + c to end) ";
    cin >> playerTwoName;
    clearCIN();

    drawBoard(theBoard);

    while (playerPosition != "-999") {
        while (validInputUser1 == false) {
            cout << "Player: ('X') " << playerOneName << " enter a position (-999 to quit)" << endl;
            cin >> playerPosition;
            //clear cin buffer
            clearCIN();
            if (playerPosition == "-999") {
                validInputUser2 = 1;
                break;
            }
            else {}
            //convert to all caps
            for (long unsigned int i = 0; i < playerPosition.length(); i++) {
                playerPosition[i] = toupper(playerPosition[i]);
            }
            validInputUser1 = choosePosition(theBoard, playerPosition, 'X');
        }
        if (checkWinner (theBoard, 'X')) {
            cout << "Player: " << playerOneName << " wins!" << endl;
            drawBoard(theBoard);
            break;
        }
        while (validInputUser2 == false) {
            cout << "Player: ('0') " << playerTwoName << " enter a position (-999 to quit)" << endl;
            cin >> playerPosition;
            //clear cin buffer
            clearCIN();
            if (playerPosition == "-999") {
                break;
            }
            else {}
            //convert to all caps
            for (long unsigned int i = 0; i < playerPosition.length(); i++) {
                playerPosition[i] = toupper(playerPosition[i]);
            }
            validInputUser2 = choosePosition(theBoard, playerPosition, '0');
        }
        if (checkWinner (theBoard, '0')) {
            cout << "Player: " << playerTwoName << " wins!" << endl;
            drawBoard(theBoard);
            break;
        }

        //set both "validInput" to false so the loops trigger
        validInputUser1 = 0;
        validInputUser2 = 0;
        if (playerPosition != "-999") {
            drawBoard(theBoard);
        }
        
    }
    
    delete theBoard;
    theBoard = nullptr;

    return 0;
} 