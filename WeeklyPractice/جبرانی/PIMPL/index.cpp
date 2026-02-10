#include <iostream>
#include <string>

using namespace std;

class BankAccount
{
public:
    BankAccount(double initialBalance);
    ~BankAccount();

    void deposit(double amount);
    void withdraw(double amount);
    double balance() const;

private:
    class Impl;
    Impl *impl;
};

class BankAccount::Impl
{
public:
    double currentBalance;
    Impl(double b) : currentBalance(b) {}
};

BankAccount::BankAccount(double initialBalance)
{
    impl = new Impl(initialBalance);
}

BankAccount::~BankAccount()
{
    delete impl;
}

void BankAccount::deposit(double amount)
{
    if (amount > 0)
    {
        impl->currentBalance += amount;
    }
}

void BankAccount::withdraw(double amount)
{
    if (amount > 0 && amount <= impl->currentBalance)
    {
        impl->currentBalance -= amount;
    }
}

double BankAccount::balance() const
{
    return impl->currentBalance;
}

int main()
{
    BankAccount myAccount(1000.0);

    myAccount.deposit(500.0);
    myAccount.withdraw(250.0);

    cout << "Final Balance: " << myAccount.balance() << endl;

    return 0;
}