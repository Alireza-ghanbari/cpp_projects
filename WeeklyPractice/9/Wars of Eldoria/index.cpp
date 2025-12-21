#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Creature {
protected:
    string name;
    int powerLevel;
    int clanID;

public:
    Creature(string n, int p, int c)
        : name(n), powerLevel(p), clanID(c) {}

    virtual ~Creature() {}

    int getClanID() const { return clanID; }
    string getName() const { return name; }

    bool isAlive() const { return powerLevel > 0; }

    virtual void displayInfo() const = 0;
    virtual void receiveMessage(const string& msg, const Creature* sender) = 0;

    void sendMessage(const string& msg, Creature* receiver) {
        if (!receiver) return;

        bool friendly = clanID == receiver->clanID;

        cout << "\n[" << name << " -> " << receiver->name << "] ";
        cout << (friendly ? "(Friendly) " : "(Enemy) ");
        cout << msg << endl;

        receiver->receiveMessage(msg, this);
    }
};

class Wizard : public Creature {
    int mana;

public:
    Wizard(string n)
        : Creature(n, 100, 2), mana(50) {}

    void castSpell() {
        if (mana >= 10) {
            mana -= 10;
            powerLevel -= 5;
            cout << name << " casts a spell! Mana: " << mana << endl;
        } else {
            cout << name << " has no mana!" << endl;
        }
    }

    void displayInfo() const override {
        cout << "Wizard | " << name << " | Power: "
             << powerLevel << " | Mana: " << mana << endl;
    }

    void receiveMessage(const string& msg, const Creature* sender) override {
        mana -= 5;
        powerLevel -= 5;
        cout << "Wizard reacts: " << msg << endl;
    }
};

class Elf : public Creature {
    int agility;

public:
    Elf(string n)
        : Creature(n, 80, 1), agility(30) {}

    void dodge() {
        cout << name << " dodges quickly!" << endl;
    }

    void displayInfo() const override {
        cout << "Elf | " << name << " | Power: "
             << powerLevel << " | Agility: " << agility << endl;
    }

    void receiveMessage(const string& msg, const Creature* sender) override {
        if (sender->getClanID() == clanID)
            cout << "Elf smiles: " << msg << endl;
        else {
            cout << "Elf warns: " << msg << endl;
            powerLevel -= 10;
        }
    }
};

class Giant : public Creature {
    int stamina;

public:
    Giant(string n)
        : Creature(n, 150, 2), stamina(100) {}

    void roar() {
        cout << name << " roars!" << endl;
    }

    void displayInfo() const override {
        cout << "Giant | " << name << " | Power: "
             << powerLevel << " | Stamina: " << stamina << endl;
    }

    void receiveMessage(const string& msg, const Creature* sender) override {
        stamina -= 10;
        powerLevel -= 5;
        cout << "Giant responds slowly: " << msg << endl;
    }
};

class Dwarf : public Creature {
    int strength;
    int defense;

public:
    Dwarf(string n)
        : Creature(n, 90, 1), strength(40), defense(60) {}

    void shieldBlock() {
        cout << name << " blocks with shield!" << endl;
    }

    void displayInfo() const override {
        cout << "Dwarf | " << name << " | Power: "
             << powerLevel << " | Strength: "
             << strength << " | Defense: " << defense << endl;
    }

    void receiveMessage(const string& msg, const Creature* sender) override {
        if (sender->getClanID() == clanID)
            cout << "Dwarf cheers: " << msg << endl;
        else {
            shieldBlock();
            powerLevel -= 5;
            cout << "Dwarf defends: " << msg << endl;
        }
    }
};

int main() {
    vector<Creature*> creatures;

    creatures.push_back(new Elf("Elandor"));
    creatures.push_back(new Dwarf("Thorin"));
    creatures.push_back(new Wizard("Merlin"));
    creatures.push_back(new Giant("Grom"));

    for (auto c : creatures)
        c->displayInfo();

    creatures[0]->sendMessage("Together we fight!", creatures[1]);
    creatures[2]->sendMessage("Feel my curse!", creatures[0]);
    creatures[0]->sendMessage("Leave this land!", creatures[3]);
    creatures[3]->sendMessage("Crush them!", creatures[2]);

    dynamic_cast<Wizard*>(creatures[2])->castSpell();

    for (auto c : creatures)
        cout << c->getName()
             << (c->isAlive() ? " is alive\n" : " is defeated\n");

    for (auto c : creatures)
        delete c;

    return 0;
}
