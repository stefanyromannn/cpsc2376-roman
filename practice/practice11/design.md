classDiagram
    class Game {
        +string title
        +int totalCopies
        +int availableCopies
        +Game(string title, int copies)
        +void checkOutCopy()
        +void returnCopy()
        +string getTitle()
        +int getAvailableCopies()
    }

    class Customer {
        +string name
        +int customerID
        +Customer(string name, int id)
        +string getName()
        +int getID()
    }

    class Loan {
        +int loanID
        +Customer borrower
        +Game* game
        +string dueDate
        +Loan(int loanID, Customer borrower, Game* game, string dueDate)
        +string getLoanInfo()
    }

    Loan --> Game : borrows
    Loan --> Customer : belongs to
