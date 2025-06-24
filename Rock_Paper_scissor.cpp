#include <iostream>
#include <random>
using namespace std;

string getChoiceName(int n) {
    if (n == 1) return "🪨 Rock";
    if (n == 2) return "📜 Paper";
    if (n == 3) return "✂️ Scissors";
    return "Invalid";
}

int main() {
    int userChoice;
    char playAgain;

    cout << "######### 🎮 Welcome to Rock 🪨, Paper 📜, Scissors ✂️ Game #########\n";

    do {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> distr(1, 3);
        int aiChoice = distr(gen);

        cout << "\nChoose one:\n";
        cout << "1. 🪨 Rock\n";
        cout << "2. 📜 Paper\n";
        cout << "3. ✂️ Scissors\n";
        cout << "Enter your choice (1/2/3): ";
        cin >> userChoice;

        if (userChoice < 1 || userChoice > 3) {
            cout << "❌ Invalid input! Please enter 1, 2, or 3.\n";
            continue;
        }

        cout << "\nYou chose: " << getChoiceName(userChoice) << endl;
        cout << "AI chose: " << getChoiceName(aiChoice) << endl;

        if (aiChoice == userChoice) {
            cout << "😐 It's a draw! Try again.\n";
        }
        
        else if ((userChoice == 1 && aiChoice == 3) ||
                   (userChoice == 2 && aiChoice == 1) ||
                   (userChoice == 3 && aiChoice == 2)) {
            cout << "🎉 You win!\n";
        }
        
        else {
            cout << "🤖 AI wins!\n";
        }

        cout << "\nDo you want to play again? (y/n): ";
        cin >> playAgain;

    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "👋 Thanks for playing! See you next time!\n";
    return 0;
}