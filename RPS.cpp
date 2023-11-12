#include <iostream>
#include "vector"
#include <random>
#include "util/LinkedList.hpp"

using namespace std;

void RPS2();

int main() {
    RPS2();
    return 0;
}

void RPS2() {
    LinkedList<string> list;
    list.add("Rock");
    list.add("Paper");
    list.add("Scissors");

    cout << "[" << list.get(2) << "]";

    cout << "\nprinting list contents:\n";
    list.printContents();
}

void RPS1() {
    cout << "\n\nInit\n";

    vector<string> options = {"r", "p", "s"};
    string input;
    bool valid;

    srand(time(nullptr));

    int randomNum = (rand() % 3);
    string comp = options[randomNum];

    do {
        cin >> input;

        for (int i = 0; i < options.size(); i++) {
            if (options[i] == input) {
                valid = true;
            }
        }
    } while (!valid);

    string winner = "";
    if (input == "r") {

        if (comp == "p") winner = "comp";
        else if (comp == "s") winner = "user";

    } else if (input == "p") {

        if (comp == "s") winner = "comp";
        else if (comp == "r") winner = "user";

    } else if (input == "s") {

        if (comp == "r") winner = "comp";
        else if (comp == "p") winner = "user";

    }

    if (winner == "") {
        winner = "tie";
    }

    cout << "winner = " + winner + "\n";
    cout << "comp had " + comp;
}