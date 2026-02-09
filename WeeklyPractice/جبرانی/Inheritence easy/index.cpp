#include <iostream>
#include <string>

using namespace std;

class Entity
{
protected:
    int id;
    string name;

public:
    Entity(int id, string name) : id(id), name(name) {}
    virtual ~Entity() {}
    virtual string type() const = 0;
};

class Player : public Entity
{
public:
    Player(int id, string name) : Entity(id, name) {}
    string type() const override
    {
        return "Player";
    }
};

class Enemy : public Entity
{
public:
    Enemy(int id, string name) : Entity(id, name) {}
    string type() const override
    {
        return "Enemy";
    }
};

class NPC : public Entity
{
public:
    NPC(int id, string name) : Entity(id, name) {}
    string type() const override
    {
        return "NPC";
    }
};

void printEntity(const Entity &e)
{
    cout << e.type() << endl;
}

int main()
{
    Player p(1, "Hero");
    Enemy e(2, "Orc");
    NPC n(3, "Villager");

    printEntity(p);
    printEntity(e);
    printEntity(n);

    return 0;
}