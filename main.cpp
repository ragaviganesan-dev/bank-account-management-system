#include <iostream>
#include <string>
using namespace std;

// Base Class
class BankAccount {
protected:
    int accountNumber;
    string accountHolder;
    double balance;

public:
    // Constructor
    BankAccount(int accNo, string name, double initialBalance) {
        accountNumber = accNo;
        accountHolder = name;
        balance = initialBalance;
    }

    // Deposit Function
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Amount Deposited Successfully!\n";
        } else {
            cout << "Invalid Deposit Amount!\n";
        }
    }

    // Withdraw Function
    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Amount Withdrawn Successfully!\n";
        } else {
            cout << "Insufficient Balance or Invalid Amount!\n";
        }
    }

    // Display Function
    void display() {
        cout << "\n----- Account Details -----\n";
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Holder: " << accountHolder << endl;
        cout << "Balance: " << balance << endl;
    }
};

// Derived Class (Inheritance)
class SavingsAccount : public BankAccount {
private:
    double interestRate;

public:
    // Constructor
    SavingsAccount(int accNo, string name, double initialBalance, double rate)
        : BankAccount(accNo, name, initialBalance) {
        interestRate = rate;
    }

    // Add Interest
    void addInterest() {
        double interest = balance * interestRate / 100;
        balance += interest;
        cout << "Interest Added Successfully!\n";
    }
};

// Main Function
int main() {
    int accNo;
    string name;
    double initialBalance;
    double interestRate;

    cout << "Enter Account Number: ";
    cin >> accNo;

    cout << "Enter Account Holder Name: ";
    cin.ignore();
    getline(cin, name);

    cout << "Enter Initial Balance: ";
    cin >> initialBalance;

    cout << "Enter Interest Rate (%): ";
    cin >> interestRate;

    SavingsAccount account(accNo, name, initialBalance, interestRate);

    int choice;
    double amount;

    do {
        cout << "\n===== BANK MENU =====\n";
        cout << "1. Deposit\n";
        cout << "2. Withdraw\n";
        cout << "3. Add Interest\n";
        cout << "4. Display Account Details\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter amount to deposit: ";
                cin >> amount;
                account.deposit(amount);
                break;

            case 2:
                cout << "Enter amount to withdraw: ";
                cin >> amount;
                account.withdraw(amount);
                break;

            case 3:
                account.addInterest();
                break;

            case 4:
                account.display();
                break;

            case 5:
                cout << "Thank you for using Bank System!\n";
                break;

            default:
                cout << "Invalid Choice! Try Again.\n";
        }

    } while (choice != 5);

    return 0;
}
