#include <iostream>   // for input/output
#include <string>     // for strings
#include <cstdlib>    // for rand()
#include <ctime>      // for time()
#include <fstream>    // for file handling
using namespace std;

// Base class
class Player {
protected:
    string name;     // player name
    int score = 0;   // player score

public:
    // virtual function for polymorphism
    virtual void displayDetails() {
        cout << "Name: " << name << "\nScore: " << score << endl;
    }

    // virtual destructor
    virtual ~Player() {}
};

// Derived class
class GamePlayer : public Player {
    string choice;   // player's choice

public:
    // input player's name
    void inputDetails() {
        cin.ignore(); 
        cout << "Enter your name: ";
        getline(cin, name);
    }

    // input player's choice
    void makeChoice() {
        cout << "Choose (rock/paper/scissors): ";
        cin >> choice;
    }

    // get choice
    string getChoice() {
        return choice;
    }

    // function overloading - update score by 1
    void updateScore() {
        score++;
    }

    // function overloading - update score by given value
    void updateScore(int p) {
        score += p;
    }

    // function overriding - display player details
    void displayDetails() override {
        cout << "\n--- Player Details ---\n";
        Player::displayDetails();
    }

    // operator overloading - sum of scores
    int operator + (GamePlayer &p) {
        return score + p.score;
    }

    // save game result to file with exception handling
    void saveToFile(const string& result) {
        try {
            ofstream file("game_results.txt", ios::app);
            if (!file.is_open()) throw runtime_error("Cannot open file!");
            file << "----\n";
            file << "Player: " << name << endl;
            file << "Score: " << score << endl;
            file << "Result: " << result << endl;
            file.close();
        } catch (const exception& e) {
            cout << "Error saving file: " << e.what() << endl;
        }
    }
};

// computer random choice
string getComputerChoice() {
    string arr[3] = {"rock", "paper", "scissors"};
    return arr[rand() % 3];
}

// decide winner
int decideWinner(const string& p, const string& c) {
    if (p == c) return 0; // tie
    if ((p == "rock" && c == "scissors") ||
        (p == "paper" && c == "rock") ||
        (p == "scissors" && c == "paper"))
        return 1; // player wins
    return -1;    // computer wins
}

// show saved game history with exception handling
void showHistory() {
    try {
        ifstream file("game_results.txt");
        if (!file.is_open()) throw runtime_error("No history found.");
        string line;
        cout << "\n--- Game History ---\n";
        while (getline(file, line))
            cout << line << endl;
        file.close();
    } catch (const exception& e) {
        cout << e.what() << endl;
    }
}

int main() {
    srand(time(0)); // seed for random
    int choice;

    do {
        system("cls"); // clear screen
        cout << "\nRock Paper Scissors Game\n";
        cout << "1. Start Game\n";
        cout << "2. View History\n";
        cout << "3. Exit\n";
        cout << "Choice: ";
        cin >> choice;

        if (choice == 1) {
            Player* p;        // polymorphism
            GamePlayer g;
            p = &g;

            g.inputDetails(); // get name
            g.makeChoice();   // get choice

            string comp = getComputerChoice();
            cout << "Computer chose: " << comp << endl;

            int result = decideWinner(g.getChoice(), comp);
            string resultText;

            if (result == 1) {
                cout << "You Won!\n";
                g.updateScore();
                resultText = "Player Won";
            }
            else if (result == -1) {
                cout << "Computer Won!\n";
                resultText = "Computer Won";
            }
            else {
                cout << "It's a Tie!\n";
                resultText = "Tie";
            }

            p->displayDetails();       // show player info
            g.saveToFile(resultText);  // save result with exception handling
        }
        else if (choice == 2) {
            showHistory(); // show all results with exception handling
        }

        if (choice != 3) {
            cout << "\nPress Enter to continue...";
            cin.ignore();
            cin.get();
        }

    } while (choice != 3);

    return 0;
}
