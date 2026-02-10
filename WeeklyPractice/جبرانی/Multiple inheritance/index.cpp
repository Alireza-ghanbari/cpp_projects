#include <iostream>
#include <string>

using namespace std;

class Capability
{
protected:
    int _cost;

public:
    Capability(int cost) : _cost(cost) {}
    virtual ~Capability() {}
    virtual string name() const = 0;
    int cost() const { return _cost; }
};

class Flyable : public virtual Capability
{
public:
    Flyable(int cost) : Capability(cost) {}
    string name() const override { return "Flyable"; }
};

class Shootable : public virtual Capability
{
public:
    Shootable(int cost) : Capability(cost) {}
    string name() const override { return "Shootable"; }
};

class Dragon : public Flyable, public Shootable
{
public:
    Dragon(int cost) : Capability(cost), Flyable(cost), Shootable(cost) {}

    string name() const override
    {
        return Flyable::name() + " & " + Shootable::name();
    }
};

void printCapabilities(const Capability &c)
{
    cout << "Capability Name: " << c.name() << endl;
    cout << "Cost: " << c.cost() << endl;
}

int main()
{
    Dragon d(100);

    cout << "Dragon capabilities:" << endl;
    cout << "- " << d.Flyable::name() << endl;
    cout << "- " << d.Shootable::name() << endl;
    cout << "Cost: " << d.cost() << endl;

    return 0;
}