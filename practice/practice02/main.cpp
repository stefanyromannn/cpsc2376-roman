#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <limits>

using namespace std;

void checkBalance(double balance);
void deposit(double &balance);
void withdraw(double &balance);
double readBalanceFromFile();
void writeBalanceToFile(double balance);
bool isValidAmount(double amount);
int getValidChoice();
double getValidAmount();

int main() {
    double balance;
    string filename = "account_balance.txt";

    balance = readBalanceFromFile();

    cout << "Welcome to Your Bank Account" << endl;
    if (balance == 100.00) {
        cout << "Initializing account: $100.00 " << endl;
    } else {
        cout << "Current balance is: $" << fixed << setprecision(2) << balance << endl;
    }

    int choice;

    while (true) {
        cout << "\nMenu:" << endl;
        cout << "1. Check Balance" << endl;
        cout << "2. Deposit Money" << endl;
        cout << "3. Withdraw Money" << endl;
        cout << "4. Exit" << endl;

        choice = getValidChoice();

        switch (choice) {
            case 1:
                checkBalance(balance);
                break;
            case 2:
                deposit(balance);
                break;
            case 3:
                withdraw(balance);
                break;
            case 4:
                cout << "Exiting program" << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}

void checkBalance(double balance) {
    cout << "Current balance is: $" << fixed << setprecision(2) << balance << endl;
}

void deposit(double &balance) {
    double amount = getValidAmount();

    if (amount <= 0) {
        cout << "Error: Deposit amount must be positive." << endl;
        return;
    }

    balance += amount;
    writeBalanceToFile(balance);
    cout << "Deposit successful. Your new balance is: $" << fixed << setprecision(2) << balance << endl;
}

void withdraw(double &balance) {
    double amount = getValidAmount();

    if (amount <= 0) {
        cout << "Error: Withdrawal amount must be positive." << endl;
        return;
    }

    if (amount > balance) {
        cout << "Error: Insufficient funds. Your balance is $" << fixed << setprecision(2) << balance << "." << endl;
        return;
    }

    balance -= amount;
    writeBalanceToFile(balance);
    cout << "Withdrawal successful. New balance is: $" << fixed << setprecision(2) << balance << endl;
}

double readBalanceFromFile() {
    double balance = 100.00;
    ifstream file("account_balance.txt");

    if (!file) {
        return balance;
    }

    file >> balance;
    if (!file) {
        cout << "Error reading balance from file. Exiting." << endl;
        exit(1);
    }

    file.close();
    return balance;
}

void writeBalanceToFile(double balance) {
    ofstream file("account_balance.txt");

    if (!file) {
        cout << "Error opening file to write balance. Exiting." << endl;
        exit(1);
    }

    file << fixed << setprecision(2) << balance;
    file.close();
}

bool isValidAmount(double amount) {
    return amount > 0;
}

int getValidChoice() {
    int choice;
    while (true) {
        cout << "Enter your choice: ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a valid number." << endl;
        } else {
            return choice;
        }
    }
}

double getValidAmount() {
    double amount;
    while (true) {
        cout << "Enter amount: ";
        cin >> amount;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a valid number." << endl;
        } else if (amount <= 0) {
            cout << "Amount must be positive. Please enter again." << endl;
        } else {
            return amount;
        }
    }
}
