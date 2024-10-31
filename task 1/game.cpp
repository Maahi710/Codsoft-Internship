#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int main() {
    cout<< "\n\t\t_Welcome to the Number Guessing Game_________________ \n"<< endl;
    cout<< "\n\t\t_>You will have to guess a number between 1 to 100.";
    cout<< "\n\t\t_>Let's start playing and Best of Luck."<<endl;

    srand(time(0));
    int randNumber = ( rand() % 100 ) + 1;

    cout<< "\n^^You will have a total of 5 chances to guess the correct number.^^\n";
    int chancesLeft = 5;
    int playerInput;

    for (int i = 1; i <= 5; i++)
    {
        cout << "\n__>Enter the Number: ";
        cin >> playerInput;

        if(playerInput == randNumber)
        {
            cout<< "\nCongrats! You have successfully guessed the right number!\n";
            cout<< "\nThanks for playing. Have a nice day!";
            break;
        }
        else
        {
            if(playerInput > randNumber)
            {
                cout<< "\nInsert a Smaller Number. Try Again!"<<endl;
            }
            else
            {
                cout<< "\nInsert a Larger Number. Try Again!"<<endl;
            }
        }
        chancesLeft--;
        cout<< "\n( Chances Left to guess the Random Number: " << chancesLeft << " )"<<endl;

        if (chancesLeft == 0)
        {
            cout<< "\nSorry! You've used all your chances to guess the random number.\n";
            cout<< "The random number was: " << randNumber << endl;
            cout<< "Thanks for playing. Have a nice day!";
        }
    }
    cout<< "\n";
    return 0;
}