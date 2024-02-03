#include <climits>
#include <cctype>
#include <iostream>
#include <iomanip>

using namespace std;

void clearCIN ();

struct board {
    private: 
        char oneA = ' ';
        char twoA = ' ';
        char threeA = ' ';
        char oneB = ' ';
        char twoB = ' ';
        char threeB = ' ';
        char oneC = ' ';
        char twoC = ' ';
        char threeC = ' ';
    public:
        char getOneA() const {
            return oneA;
        }
        char getTwoA() const {
            return twoA;
        }
        char getThreeA() const {
            return threeA;
        }
        char getOneB() const {
            return oneB;
        }
        char getTwoB() const {
            return twoB;
        }
        char getThreeB() const {
            return threeB;
        }
        char getOneC() const {
            return oneC;
        }
        char getTwoC() const {
            return twoC;
        }
        char getThreeC() const {
            return threeC;
        }
        bool setOneA(char value) {
            if (this->oneA != ' ') {
                return false;
            }
            else {
                this->oneA = value;
                return true;
            }
                
        }
        bool setTwoA(char value) {
            if (this->twoA != ' ') {
                return false;
            }
            else {
                this->twoA = value;
                return true;
            }
        }
        bool setThreeA(char value) {
            if (this->threeA != ' ') {
                return false;
            }
            else {
                this->threeA = value;
                return true;
            }
        }
        bool setOneB(char value) {
            if (this->oneB != ' ') {
                return false;
            }
            else {
                this->oneB = value;
                return true;
            }
        }
        bool setTwoB(char value) {
            if (this->twoB != ' ') {
                return false;
            }
            else {
                this->twoB = value;
                return true;
            }
        }
        bool setThreeB(char value) {
            if (this->threeB != ' ') {
                return false;
            }
            else {
                this->threeB = value;
                return true;
            }
        }
        bool setOneC(char value) {
            if (this->oneC != ' ') {
                return false;
            }
            else {
                this->oneC = value;
                return true;
            }
        }
        bool setTwoC(char value) {
            if (this->twoC != ' ') {
                return false;
            }
            else {
                this->twoC = value;
                return true;
            }
        }
        bool setThreeC(char value) {
            if (this->threeC != ' ') {
                return false;
            }
            else {
                this->threeC = value;
                return true;
            }
        } 
};

bool choosePosition (board *& playerBoard, const string &position, const char& pawn);
void drawBoard (board * drawnBoard);
bool checkWinner (board * playerBoard, const char player);