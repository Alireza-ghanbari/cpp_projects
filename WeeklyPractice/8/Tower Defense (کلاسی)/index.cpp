#include <iostream>
#include <string>

using namespace std;

class Agent
{
protected:
    string name;
    int health;
    int movementRange;
    string type;

public:
    Agent(string name, int health, int movementRange, string type)
        : name(name), health(health), movementRange(movementRange), type(type) {}

    void displayInfo()
    {
        cout << "\n---------- Agent Info ----------" << endl;
        cout << "Name: " << name << endl;
        cout << "Health: " << health << endl;
        cout << "MovementRange: " << movementRange << endl;
        cout << "Type: " << type << endl;
    }
};

class Infantry : public Agent
{
public:
    Infantry(string name, int health, int movementRange)
        : Agent(name, health, movementRange, "Infantry") {}

    void rushAttack()
    {
        cout << name << " Rushing Attack" << endl;
    }
};

class Sniper : public Agent
{
public:
    Sniper(string name, int health, int movementRange)
        : Agent(name, health, movementRange, "Sniper") {}

    void longShot()
    {
        cout << name << " Long Shot" << endl;
    }
};

class Tank : public Agent
{
public:
    Tank(string name, int health, int movementRange)
        : Agent(name, health, movementRange, "Tank") {}

    void shield()
    {
        cout << name << " Place Shield" << endl;
    }
};

int main()
{
    Infantry soldier("Alpha", 100, 3);
    Sniper sniper("EagleEye", 80, 4);
    Tank heavyTank("Titan", 200, 2);

    soldier.displayInfo();
    sniper.displayInfo();
    heavyTank.displayInfo();

    cout << "\n---------- Abilities ----------" << endl;

    soldier.rushAttack();
    sniper.longShot();
    heavyTank.shield();

    return 0;
}