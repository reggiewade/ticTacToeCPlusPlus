#include "functions.hpp"


void clearCIN(void) {
	cin.clear();                        // Clears the error flags (if any) on cin
	cin.ignore(INT_MAX, '\n');          // Ignores characters until a newline is encountered
}

void drawBoard(board * drawnBoard) {
    const int columnWidth = 3;

    cout << endl << setw(3) << "1" << setw(6) << "2" << setw(6) << "3" << endl;
    cout << setw(columnWidth) << drawnBoard->getOneA() << setw(columnWidth) << "|" << setw(columnWidth) << drawnBoard->getTwoA() << setw(columnWidth) << "|" << setw(columnWidth) << drawnBoard->getThreeA() << setw(columnWidth + 1) << " A" << endl;
    cout << "-----------------" << endl;
    cout << setw(columnWidth) << drawnBoard->getOneB() << setw(columnWidth) << "|" << setw(columnWidth) << drawnBoard->getTwoB() << setw(columnWidth) << "|" << setw(columnWidth) << drawnBoard->getThreeB() << setw(columnWidth + 1) << " B" << endl;
    cout << "-----------------" << endl;
    cout << setw(columnWidth) << drawnBoard->getOneC() << setw(columnWidth) << "|" << setw(columnWidth) << drawnBoard->getTwoC() << setw(columnWidth) << "|" << setw(columnWidth) << drawnBoard->getThreeC() << setw(columnWidth + 1) << " C" << endl;
}

bool choosePosition (board *& playerBoard, const string &position, const char& pawn) {
    bool validInput;
    if (!playerBoard) {
        playerBoard = new board;
    }

    if (position == "1A" || position == "A1") {
        validInput = playerBoard->setOneA(pawn);
    }
    else if (position == "2A" || position == "A2") {
        validInput = playerBoard->setTwoA(pawn);
    }
    else if (position == "3A" || position == "A3") {
        validInput = playerBoard->setThreeA(pawn);
    }
    else if (position == "1B" || position == "B1") {
        validInput = playerBoard->setOneB(pawn);
    }
    else if (position == "2B" || position == "B2") {
        validInput = playerBoard->setTwoB(pawn);
    }
    else if (position == "3B" || position == "B3") {
        validInput = playerBoard->setThreeB(pawn);
    }
    else if (position == "1C" || position == "C1") {
        validInput = playerBoard->setOneC(pawn);
    }
    else if (position == "2C" || position == "C2") {
        validInput = playerBoard->setTwoC(pawn);
    }
    else if (position == "3C" || position == "C3") {
        validInput = playerBoard->setThreeC(pawn);
    }
    else {
        validInput = false;
    }
    if (!validInput) {
        cout << "Invalid input, please try again." << endl;
    }
    
    return validInput;
}

bool checkWinner (board * playerBoard, const char player) {
    if ((playerBoard->getOneA() == player && playerBoard->getOneB() == player && playerBoard->getOneC() == player) ||
            (playerBoard->getTwoA() == player && playerBoard->getTwoB() == player && playerBoard->getTwoC() == player) ||
            (playerBoard->getThreeA() == player && playerBoard->getThreeB() == player && playerBoard->getThreeC() == player)) {
                return true; // Vertical win
            }
    else if ((playerBoard->getOneA() == player && playerBoard->getTwoA() == player && playerBoard->getThreeA() == player) ||
                (playerBoard->getOneB() == player && playerBoard->getTwoB() == player && playerBoard->getThreeB() == player) ||
                (playerBoard->getOneC() == player && playerBoard->getTwoC() == player && playerBoard->getThreeC() == player)) {
                    return true; // Horizontal win
                }
    else if ((playerBoard->getOneA() == player && playerBoard->getTwoB() == player && playerBoard->getThreeC() == player) ||
                (playerBoard->getOneC() == player && playerBoard->getTwoB() == player && playerBoard->getThreeA() == player)) {
                    return true; // Diagonal win
                }
    else {
        return false;
    }
}