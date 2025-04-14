#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Game {
public:
    string title;
    int totalCopies;
    int availableCopies;

    Game(string t, int copies) {
        title = t;
        totalCopies = copies;
        availableCopies = copies;
    }

    void checkOutCopy() {
        if (availableCopies > 0) {
            availableCopies--;
            cout << "Checked out 1 copy of " << title << endl;
        } else {
            cout << "No copies of " << title << " are available.\n";
        }
    }

    void returnCopy() {
        if (availableCopies < totalCopies) {
            availableCopies++;
            cout << "Returned 1 copy of " << title << endl;
        }
    }

    void display() const {
        cout << title << " | Available: " << availableCopies << "/" << totalCopies << endl;
    }
};

int main() {
    vector<Game> games;
    games.push_back(Game("Catan", 3));
    games.push_back(Game("Ticket to Ride", 2));
    games.push_back(Game("Carcassonne", 1));

    cout << "Board Game List:\n";
    for (Game& g : games) {
        g.display();
    }

    cout << "\nChecking out 'Catan'...\n";
    games[0].checkOutCopy();

    cout << "\nAfter checkout:\n";
    games[0].display();

    cout << "\nReturning 'Catan'...\n";
    games[0].returnCopy();

    cout << "\nAfter return:\n";
    games[0].display();

    return 0;
}
