#include <iostream>
#include <string>

using namespace std;

class BankAccount
{
private:
    string ownerName;
    int accountNumber;
    double balance;

public:
    BankAccount(string name, int accNumber, double initBalance)
    {
        ownerName = name;
        accountNumber = accNumber;
        balance = initBalance;
    }

    void deposit(double amount)
    {
        if (amount > 0)
        {
            balance += amount;
            cout << "Deposit successfull. new balance: " << balance << "$" << endl;
        }
        else
        {
            cout << "Invalid amount. deposit failed" << endl;
        }
    }

    void withdraw(double amount)
    {
        if (amount <= 0)
        {
            cout << "Invalid amout. must be greater than 0." << endl;
        }
        else if (amount > balance)
        {
            cout << "Insufficient balance" << endl;
        }
        else
        {
            balance -= amount;
            cout << "withdraw successfull. new balance: " << balance << "$" << endl;
        }
    }

    void display() const
    {
        cout << endl
             << "********** Information ***********" << endl;
        cout << "Owner Name: " << ownerName << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: " << balance << "$" << endl;
        cout << "**********************************" << endl;
    }
};

int main()
{
    string name;
    int accNumber;
    double initBalance;

    cout << "Enter Owner Name: ";
    getline(cin, name);
    cout << "Enter Account Number: ";
    cin >> accNumber;
    cout << "Enter initinitial balance: ";
    cin >> initBalance;

    BankAccount account(name, accNumber, initBalance);

    double depositAmount, withdrawAmount;

    cout << "Enter deposit amount: ";
    cin >> depositAmount;
    account.deposit(depositAmount);

    cout << "Enter withdraw amount: ";
    cin >> withdrawAmount;
    account.withdraw(withdrawAmount);

    account.display();

    return 0;
}