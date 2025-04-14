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
            std::cout << "Checked out 1 copy: " << title << std::endl;
        } else {
            std::cout << "No copies for:  " << title << " are available.\n";
        }
    }

    void returnCopy() {
        if (availableCopies < totalCopies) {
            availableCopies++;
            std::cout << "Returned 1 copy of: " << title << std::endl;
        }
    }

    void display() const {
        std::cout << title << " | Available: " << availableCopies << "/" << totalCopies << std::endl;
    }
};

int main() {
    std::vector<Game> games;
    games.push_back(Game("Monopoly", 3));
    games.push_back(Game("Ticket to Ride", 2));
    games.push_back(Game("Carcassonne", 1));

    std::cout << "Board Game List:\n";
    for (Game& g : games) {
        g.display();
    }

    std::cout << "\nChecking out 'Monopoly'...\n";
    games[0].checkOutCopy();

    std::cout << "\nAfter checkout:\n";
    games[0].display();

    std::cout << "\nReturning 'Monopoly'...\n";
    games[0].returnCopy();

    std::cout << "\nAfter return:\n";
    games[0].display();

    return 0;
}
