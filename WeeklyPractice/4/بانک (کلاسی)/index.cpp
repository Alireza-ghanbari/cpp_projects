#include <iostream>
#include <string>
using namespace std;

class BankAccount
{
private:
    string owner;
    int accountNumber;
    double balance;
    static int totalAccounts;

public:
    BankAccount(string name = "Unknown", double initBalance = 0.0)
    {
        owner = name;
        balance = initBalance;
        accountNumber = ++totalAccounts;
    }

    ~BankAccount()
    {
        cout << "Account of " << owner << " (Acc#" << accountNumber << ") deleted." << endl;
    }

    void deposit(double amount)
    {
        if (amount > 0)
        {
            balance += amount;
            cout << owner << " deposited " << amount << ". New balance: " << balance << endl;
        }
        else
        {
            cout << "Invalid deposit amount for " << owner << "." << endl;
        }
    }

    bool withdraw(double amount)
    {
        if (amount <= 0)
        {
            cout << "Invalid withdraw amount for " << owner << "." << endl;
            return false;
        }
        else if (amount > balance)
        {
            cout << owner << " has insufficient funds." << endl;
            return false;
        }
        else
        {
            balance -= amount;
            cout << owner << " withdrew " << amount << "." << endl;
            return true;
        }
    }

    void display() const
    {
        cout << "#" << accountNumber << " " << owner << ": " << balance << endl;
    }

    friend void transfer(BankAccount &from, BankAccount &to, double amount);

    int getAccountNumber() const { return accountNumber; }
    static int getTotalAccounts() { return totalAccounts; }
};

int BankAccount::totalAccounts = 0;

void transfer(BankAccount &from, BankAccount &to, double amount)
{
    if (from.withdraw(amount))
    {
        to.deposit(amount);
        cout << "Transferred " << amount << " from " << from.owner << " to " << to.owner << "." << endl;
    }
}

class BankSystem
{
private:
    BankAccount *accounts;
    int count;

public:
    BankSystem(int n)
    {
        count = n;
        string *names = new string[count];
        double *balances = new double[count];

        for (int i = 0; i < count; ++i)
        {
            cin >> names[i] >> balances[i];
        }

        accounts = new BankAccount[count];
        for (int i = 0; i < count; ++i)
        {
            accounts[i] = BankAccount(names[i], balances[i]);
        }
    }

    ~BankSystem()
    {
        delete[] accounts;
        cout << "BankSystem destroyed." << endl;
    }

    BankAccount *findAccount(int num)
    {
        for (int i = 0; i < count; ++i)
        {
            if (accounts[i].getAccountNumber() == num)
                return &accounts[i];
        }
        return nullptr;
    }

    void showAll() const
    {
        cout << "---- Accounts ----" << endl;
        for (int i = 0; i < count; ++i)
        {
            accounts[i].display();
        }
        cout << "Total accounts: " << BankAccount::getTotalAccounts() << endl;
    }
};

int main()
{
    int n;
    cin >> n;
    BankSystem bank(n);

    string command;
    while (cin >> command)
    {
        if (command == "transfer")
        {
            int from, to;
            double amount;
            cin >> from >> to >> amount;
            BankAccount *accFrom = bank.findAccount(from);
            BankAccount *accTo = bank.findAccount(to);
            if (accFrom && accTo)
                transfer(*accFrom, *accTo, amount);
            else
                cout << "Invalid account number." << endl;
        }
        else if (command == "withdraw")
        {
            int accNum;
            double amount;
            cin >> accNum >> amount;
            BankAccount *acc = bank.findAccount(accNum);
            if (acc)
                acc->withdraw(amount);
            else
                cout << "Account not found." << endl;
        }
        else if (command == "show")
        {
            bank.showAll();
        }
    }

    return 0;
}
