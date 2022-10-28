#include <iostream> 
#include <random>

using namespace std;

int main() {

    bool playerWon;
    int num, sticks = 22;
    char whoseTurn;
    const char yourTurn = 'Y', compTurn = 'N';

    default_random_engine r(random_device{}());
    uniform_int_distribution<> d(1, 4);

    cout << "welcome to the game of N I M. would you like to go first? Y/N" << endl;
    cin >> whoseTurn;

    if (whoseTurn == yourTurn) cout << "you go first!" << endl;
    else if (whoseTurn == compTurn) cout << "the computer goes first!" << endl;
    cout << endl;

    while (sticks > 0) {

        // if the player chooses to go first... 
        if (whoseTurn == yourTurn) {

            cout << "There are " << sticks << " sticks in the pile.\n"
                << "\n enter the amount (between 1 and 4) of sticks that you will remove from this pile." << endl;
            cin >> num;

            // if number is 1-4, amount of sticks taken/left will be displayed 
            if ((num >= 1) && (num <= 4)) {
                if (num >= sticks) {
                    cout << "You have won!\n";
                    playerWon = true;
                    break;
                }
                cout << "you have removed " << num << " sticks from the pile." << endl;
                sticks -= num;
                cout << "there are now " << sticks << " sticks left in the pile." << endl;
                whoseTurn = compTurn;
                continue;

            }
            // if number is less than 1 or greater than 4, user will be repeatedly prompted until done so 
            if ((num < 1) || (num > 4)) {

                cout << "unacceptable answer >:( enter an amount between *1* and *4*" << endl;
                //    cin >> num; 
                continue;

            }
        }

        // computer enters value 
        else {
            if (sticks <= 4) {
                cout << "\nThe computer took " << sticks << " sticks, it won\n";
                playerWon = false;
                break;
            }

            int comp_choice = d(r); // gtting a random number
            sticks -= comp_choice;
            cout << "\n the computer has taken away " << comp_choice << " sticks from the pile.\n";

            whoseTurn = yourTurn;
        }
    }
    cout << (playerWon ? "Congratulations, you won the game." : "Sorry, you lost.") << '\n';
}
