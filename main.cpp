#include <iostream>
#include <string>
#include <limits>

using namespace std;

//tictactoe

int i;

class Pitch{
private:
    //the game fields
    string topLeft = "1";
    string topCenter = "2";
    string topRight = "3";
    string middleLeft = "4";
    string middleCenter = "5";
    string middleRight = "6";
    string bottomLeft = "7";
    string bottomCenter = "8";
    string bottomRight = "9";

    //change the game fields to the player input
    void pitch_change(int feld, string player) {
        switch(feld) {
            case 1:
                topLeft = player;
                break;
            case 2:
                topCenter = player;
                break;
            case 3:
                topRight = player;
                break;
            case 4:
                middleLeft = player;
                break;
            case 5:
                middleCenter = player;
                break;
            case 6:
                middleRight = player;
                break;
            case 7:
                bottomLeft = player;
                break;
            case 8:
                bottomCenter = player;
                break;
            case 9:
                bottomRight = player;
                break;
            default:
                cout << "error" << endl;
                exit(-1);
        }
    }

    //checks if a player has won after every move
    int win_check(string player) {
        if(topCenter == player && middleCenter == player && bottomCenter == player || topRight == player && middleRight == player && bottomRight == player || topLeft == player && middleLeft == player && bottomLeft == player || topLeft == player && topCenter == player && topRight == player || middleLeft == player && middleCenter == player && middleRight == player || bottomLeft == player && bottomCenter == player && bottomRight == player || topLeft == player && middleCenter == player && bottomRight == player || topRight == player && middleCenter == player && bottomLeft == player) {
            string winner = "the player who is winning is: ";
            winner += player;
            cout << winner << endl;
            topLeft = "1";
            topCenter = "2";
            topRight = "3";
            middleLeft = "4";
            middleCenter = "5";
            middleRight = "6";
            bottomLeft = "7";
            bottomCenter = "8";
            bottomRight = "9";
            return 0;
        }
        else {
            return -1;
        }
    }

    //the gamepitch
    string pitch =
            " " + topLeft + " | " + topCenter + " | " + topRight + " \n""---|---|---\n"" " + middleLeft + " | " +
            middleCenter + " | " + middleRight + " \n""---|---|---\n"" " + bottomLeft + " | " + bottomCenter + " | " +
            bottomRight + " \n";

public:
    //checks if the move was already done and is avaiable, and if it is avaiable it moves to the function, who changes the game field and after that it moves to the function who checks if there is a win
    void zug(int feld, string player) {
        switch (feld) {
            case 1:
                if(topLeft != "1") {
                    cout << "error" << endl;
                    i--;
                }
                else {
                    pitch_change(1, player);
                    if(win_check(player) == 0) {
                        break;
                    }
                }
                break;
            case 2:
                if(topCenter != "2") {
                    cout << "error" << endl;
                    i--;
                }
                else {
                    pitch_change(2, player);
                    if(win_check(player) == 0) {
                        break;
                    }
                }
                break;
            case 3:
                if(topRight != "3") {
                    cout << "error" << endl;
                    i--;
                }
                else {
                    pitch_change(3, player);
                    if(win_check(player) == 0) {
                        break;
                    }
                }
                break;
            case 4:
                if(middleLeft != "4") {
                    cout << "error" << endl;
                    i--;
                }
                else {
                    pitch_change(4, player);
                    if(win_check(player) == 0) {
                        break;
                    }
                }
                break;
            case 5:
                if(middleCenter != "5") {
                    cout << "error" << endl;
                    i--;
                }
                else {
                    pitch_change(5, player);
                    if(win_check(player) == 0) {
                        break;
                    }
                }
                break;
            case 6:
                if(middleRight != "6") {
                    cout << "error" << endl;
                    i--;
                }
                else {
                    pitch_change(6, player);
                    if(win_check(player) == 0) {
                        break;
                    }
                }
                break;
            case 7:
                if(bottomLeft != "7") {
                    cout << "error" << endl;
                    i--;
                }
                else {
                    pitch_change(7, player);
                    if(win_check(player) == 0) {
                        break;
                    }
                }
                break;
            case 8:
                if(bottomCenter != "8") {
                    cout << "error" << endl;
                    i--;
                }
                else {
                    pitch_change(8, player);
                    if(win_check(player) == 0) {
                        break;
                    }
                }
                break;
            case 9:
                if(bottomRight != "9") {
                    cout << "error" << endl;
                    i--;
                }
                else {
                    pitch_change(9, player);
                    if(win_check(player) == 0) {
                        break;
                    }
                }
                break;
            default:
                cout << "wrong move" << endl;
        }
    }

    string pitch_output() {
        return pitch;
    }

    //a function to refresh the game pitch after every change
    void pitch_refresh() {
        pitch =
                " " + topLeft + " | " + topCenter + " | " + topRight + " \n""---|---|---\n"" " + middleLeft + " | " +
                middleCenter + " | " + middleRight + " \n""---|---|---\n"" " + bottomLeft + " | " + bottomCenter + " | " +
                bottomRight + " \n";
    }
};

void go() {
    i = 1;
    int input = 10;
    string player;
    Pitch game;
    while(true) {
        //a solution to switch player after every move
        if(i % 2 == 0) {
            player = "o";
        }
        else {
            player = "x";
        }

        game.pitch_refresh();
        cout << game.pitch_output() << endl;
        cout << "player " << player << " has turn:\n>";
        cin >> input;
        if(cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "wrong input" << endl;
        }
        else {
            game.zug(input, player);
            i++;
        }
    }
}

int main() {
    while(true) {
        go();
    }
}
