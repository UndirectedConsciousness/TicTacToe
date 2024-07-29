#include <iostream>
#include <string>
using namespace std;

void gameLoop();
void restart();
void displayBoard(string game[3][3]);
void takeXinput(string game[3][3]);
void takeOinput(string game[3][3]);
int checkWinner(string game[3][3]);
bool checkTie(string game[3][3]);

int main()
{
    gameLoop();
    return 0;
}

void gameLoop()
{
    string game[3][3] = {
        {"-", "-", "-"},
        {"-", "-", "-"},
        {"-", "-", "-"}
    };

    displayBoard(game);

    while (true) { // Loops until a win or tie is detected
        takeXinput(game);
        if (checkWinner(game) == 1) {
            cout << "Player X wins.\n";
            restart();
            break;
        }
        if (checkTie(game)) {
            cout << "Game ends in a tie. All spaces filled.\n";
            restart();
            break;
        }

        takeOinput(game);
        if (checkWinner(game) == 2) {
            cout << "Player O wins.\n";
            restart();
            break;
        }
        if (checkTie(game)) {
            cout << "Game ends in a tie. All spaces filled.\n";
            restart();
            break;
        }
    }
}

void restart()
{
    string restart = "N";
    cout << "Would you like to restart? Y/N \n";
    cin >> restart;

    if (restart == "Y" || restart == "y") {
        gameLoop();
    }
}

void displayBoard(string game[3][3]) // Displays the game state
{
    cout << "  A B C\n";
    for (int i = 0; i < 3; i++) {
        cout << i + 1 << " ";
        for (int j = 0; j < 3; j++) {
            cout << game[i][j] << " ";
        }
    cout << "\n";
    } 
}

void takeXinput(string game[3][3])
{
    string xinput;
    int yinput;
    int final_xinput, final_yinput;

    while (true) {
        cout << "Player X: Enter your move's X coordinate (A, B, C): ";
        cin >> xinput;
        cout << "Player X: Enter your move's Y coordinate (1, 2, 3): ";
        cin >> yinput;

        // Validates and converts inputs
        bool validInput = true;
        if (xinput == "A" || xinput == "a") {
            final_xinput = 0;
        } else if (xinput == "B" || xinput == "b") {
            final_xinput = 1;
        } else if (xinput == "C" || xinput == "c") {
            final_xinput = 2;
        } else {
            cout << "Invalid input for X coordinate. Please enter A, B, or C.\n";
            validInput = false;
        }

        if (yinput < 1 || yinput > 3) {
            cout << "Invalid input for Y coordinate. Please enter 1, 2, or 3.\n";
            validInput = false;
        } else {
            final_yinput = yinput - 1;
        }

        if (validInput && game[final_yinput][final_xinput] == "-") { // Checks if cell is occupied
            game[final_yinput][final_xinput] = "X";
            displayBoard(game);
            break;
        } else if (validInput) {
            cout << "Invalid move. The cell is already occupied.\n";
        }
    }
}

void takeOinput(string game[3][3])
{
    string xinput;
    int yinput;
    int final_xinput, final_yinput;

    while (true) {
        cout << "Player O: Enter your move's X coordinate (A, B, C): ";
        cin >> xinput;
        cout << "Player O: Enter your move's Y coordinate (1, 2, 3): ";
        cin >> yinput;

        // Validates and converts inputs
        bool validInput = true;
        if (xinput == "A" || xinput == "a") {
            final_xinput = 0;
        } else if (xinput == "B" || xinput == "b") {
            final_xinput = 1;
        } else if (xinput == "C" || xinput == "c") {
            final_xinput = 2;
        } else {
            cout << "Invalid input for X coordinate. Please enter A, B, or C.\n";
            validInput = false;
        }

        if (yinput < 1 || yinput > 3) {
            cout << "Invalid input for Y coordinate. Please enter 1, 2, or 3.\n";
            validInput = false;
        } else {
            final_yinput = yinput - 1;
        }

        if (validInput && game[final_yinput][final_xinput] == "-") { // Checks if cell is unoccupied
            game[final_yinput][final_xinput] = "O";
            displayBoard(game);
            break;
        } else if (validInput) {
            cout << "Invalid move. The cell is already occupied.\n";
        }
    }
}

int checkWinner(string game[3][3]) // return 1 for X win, return 2 for O win, return 0 for win condition not met
{
    for (int i = 0; i < 3; i++) { // Horizontal win check
        if (game[i][0] == game[i][1] && game[i][1] == game[i][2] && game[i][1] == "X") {
            return 1;
        }
        if (game[i][0] == game[i][1] && game[i][1] == game[i][2] && game[i][1] == "O") {
            return 2;
        }
    }

    for (int j = 0; j < 3; j++) { // Vertical win check
        if (game[0][j] == game[1][j] && game[1][j] == game[2][j] && game[1][j] == "X") {
            return 1;
        }
        if (game[0][j] == game[1][j] && game[1][j] == game[2][j] && game[1][j] == "O") {
            return 2;
        }
    }

    // Diagonal win checks (descending)
    if (game[0][0] == game[1][1] && game[1][1] == game[2][2] && game[1][1] == "X") {
            return 1;
        }

    if (game[0][0] == game[1][1] && game[1][1] == game[2][2] && game[1][1] == "O") {
            return 2;
        }

    // Diagonal win checks (ascending)
    if (game[0][2] == game[1][1] && game[1][1] == game[2][0] && game[1][1] == "X") {
            return 1;
        }

    if (game[0][2] == game[1][1] && game[1][1] == game[2][0] && game[1][1] == "O") {
            return 2;
        }

    return 0; // If none of the conditions for winning are met, returns 0
}

bool checkTie(string game[3][3]) // Checks if any cells are still empty.
{
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (game[i][j] == "-") {
                return false; 
            }
        }
    }
    return true;
}