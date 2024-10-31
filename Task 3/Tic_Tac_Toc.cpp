#include <iostream>
#include <vector>
using namespace std;

void board(vector<string> arr) {
    cout << endl;
    cout << "  " << arr[1] << "   |  " << arr[2] << "   |   " << arr[3] << "  " << endl;
    cout << "     |     |     " << endl;
    cout << "  " << arr[4] << "  |  " << arr[5] << "  |   " << arr[6] << "  " << endl;
    cout << "     |     |     " << endl;
    cout << "  " << arr[7] << "  |  " << arr[8] << "  |   " << arr[9] << "  " << endl;
    cout << endl;
}

bool checkmove(int m, vector<string> arr) {
    if (m <= 0 || m >= 10) {
        return false;
    }
    if (arr[m] == "x" || arr[m] == "0") {
        return false;
    }
    return true;
}

void validmove(int move, string s, vector<string>& arr) {
    arr[move] = s;
}

string wincheck(string s, vector<string> arr) {
    if ((arr[1] == s && arr[2] == s && arr[3] == s) ||
        (arr[4] == s && arr[5] == s && arr[6] == s) ||
        (arr[7] == s && arr[8] == s && arr[9] == s)) {
        return s;
    }
    return "0";
}

int main() {
    vector<string> arr(10);
    for (int i = 1; i < 10; i++) {
        arr[i] = to_string(i);  // Use assignment operator
    }

    char game;
    cout << "Press any key to start the game or 'q' to quit: " << endl;
    cin >> game;

    while (game != 'q') {
        board(arr);

        int turnCount = 0, p1 = 0, p2 = 0;
        while (turnCount < 9) {
            int move;
            cout << "Player 1 turn..." << endl;
            cout << "Enter move: "; cin >> move;

            while (!checkmove(move, arr)) {
                cout << "Invalid move Player 1, try again..." << endl;
                cin >> move;
            }

            validmove(move, "x", arr);

            if (wincheck("x", arr) == "x") {
                p1 = 1;
                break;
            }

            turnCount += 1;
            if (turnCount == 9) {
                break;
            }

            board(arr);

            cout << "Player 2 turn..." << endl;
            cout << "Enter move: "; cin >> move;

            while (!checkmove(move, arr)) {
                cout << "Invalid move Player 2, try again..." << endl;
                cin >> move;
            }

            validmove(move, "O", arr);

            if (wincheck("O", arr) == "O") {
                p2 = 1;
                break;
            }

            turnCount += 1;
            board(arr);
        }

        board(arr);
        if (p1 == 1) {
            cout << "Player 1 won!" << endl;
        } else if (p2 == 1) {
            cout << "Player 2 won!" << endl;
        } else {
            cout << "It's a draw!" << endl;
        }

        for (int i = 1; i < 10; i++) {
            arr[i] = to_string(i);  // Reset the board
        }
        cout << "Press any key to play again or 'q' to quit: " << endl;
        cin >> game;
    }

    return 0;
}