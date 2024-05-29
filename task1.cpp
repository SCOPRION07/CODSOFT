#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    int randomNo, inputNo;
    srand(time(0));

    randomNo = rand() % 100 + 1;

    cout << "Guess the number between 1 to 100" << endl;
    cin >> inputNo;

    while (1)
     {
        if (randomNo == inputNo) {
            cout << "Your guess is correct :)" << endl;
            cout << "The guessed number is " << inputNo;
            break;
        } else if (randomNo > inputNo) {
            cout << "Oops! Your guess is lower than the number" << endl;
        } else if (randomNo < inputNo) {
            cout << "Oh! Your guess is higher than the number" << endl;
        }
        cout << "Try to guess the number again" << endl;
        cin >> inputNo;
    }
    return 0;
}