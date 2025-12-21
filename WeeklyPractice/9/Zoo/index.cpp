#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Animal {
protected:
    string name;
    int age;
    double weight;

public:
    Animal(string n, int a, double w)
        : name(n), age(a), weight(w) {}

    virtual ~Animal() {}

    virtual void makeSound() const = 0;
    virtual void print() const = 0;

    string getName() const { return name; }
};

class FlyingAnimal : virtual public Animal {
protected:
    double wingSpan;
    bool canFly;

public:
    FlyingAnimal(string n, int a, double w, double ws, bool cf)
        : Animal(n, a, w), wingSpan(ws), canFly(cf) {}

    bool getCanFly() const { return canFly; }

    void print() const override {
        cout << "FlyingAnimal | Wingspan: " << wingSpan
             << " | Can Fly: " << (canFly ? "Yes" : "No") << endl;
    }
};

class WalkingAnimal : virtual public Animal {
protected:
    int legs;
    double runSpeed;

public:
    WalkingAnimal(string n, int a, double w, int l, double rs)
        : Animal(n, a, w), legs(l), runSpeed(rs) {}

    double getRunSpeed() const { return runSpeed; }

    void print() const override {
        cout << "WalkingAnimal | Legs: " << legs
             << " | Run Speed: " << runSpeed << endl;
    }
};

class SwimmingAnimal : virtual public Animal {
protected:
    double swimSpeed;
    bool freshWater;

public:
    SwimmingAnimal(string n, int a, double w, double ss, bool fw)
        : Animal(n, a, w), swimSpeed(ss), freshWater(fw) {}

    double getSwimSpeed() const { return swimSpeed; }
    bool needsFreshWater() const { return freshWater; }

    void print() const override {
        cout << "SwimmingAnimal | Swim Speed: " << swimSpeed
             << " | Fresh Water: " << (freshWater ? "Yes" : "No") << endl;
    }
};

class Eagle : public FlyingAnimal {
public:
    Eagle() : Animal("Eagle", 5, 6), FlyingAnimal(name, age, weight, 2.1, true) {}
    void makeSound() const override { cout << "Eagle: Screech!" << endl; }
};

class Parrot : public FlyingAnimal {
public:
    Parrot() : Animal("Parrot", 2, 1), FlyingAnimal(name, age, weight, 0.5, true) {}
    void makeSound() const override { cout << "Parrot: Hello!" << endl; }
};

class Penguin : public SwimmingAnimal {
public:
    Penguin() : Animal("Penguin", 4, 12), SwimmingAnimal(name, age, weight, 15, true) {}
    void makeSound() const override { cout << "Penguin: Honk!" << endl; }
};

class Shark : public SwimmingAnimal {
public:
    Shark() : Animal("Shark", 8, 500), SwimmingAnimal(name, age, weight, 40, false) {}
    void makeSound() const override { cout << "Shark: (silent)" << endl; }
};

class Lion : public WalkingAnimal {
public:
    Lion() : Animal("Lion", 6, 190), WalkingAnimal(name, age, weight, 4, 80) {}
    void makeSound() const override { cout << "Lion: Roar!" << endl; }
};

class Monkey : public WalkingAnimal {
public:
    Monkey() : Animal("Monkey", 3, 35), WalkingAnimal(name, age, weight, 2, 30) {}
    void makeSound() const override { cout << "Monkey: Ooh ooh!" << endl; }
};

class Duck : public FlyingAnimal, public WalkingAnimal, public SwimmingAnimal {
public:
    Duck()
        : Animal("Duck", 2, 4),
          FlyingAnimal(name, age, weight, 0.8, true),
          WalkingAnimal(name, age, weight, 2, 10),
          SwimmingAnimal(name, age, weight, 8, true) {}

    void makeSound() const override {
        cout << "Duck: Quack!" << endl;
    }

    void print() const override {
        cout << "Duck (Fly + Walk + Swim)" << endl;
    }
};


class Zoo {
    vector<Animal*> animals;

public:
    Zoo() {
        for (int i = 0; i < 3; i++) {
            animals.push_back(new Eagle());
            animals.push_back(new Parrot());
            animals.push_back(new Lion());
            animals.push_back(new Monkey());
            animals.push_back(new Shark());
            animals.push_back(new Penguin());
        }
        animals.push_back(new Duck()); // 19+
        animals.push_back(new Duck());
    }

    ~Zoo() {
        for (auto a : animals)
            delete a;
    }

    void printAll() const {
        for (auto a : animals) {
            cout << a->getName() << " -> ";
            a->print();
        }
    }

    void makeAllSounds() const {
        for (auto a : animals)
            a->makeSound();
    }

    void findFlyingAnimals() const {
        cout << "\nFlying Animals:\n";
        for (auto a : animals)
            if (dynamic_cast<FlyingAnimal*>(a))
                cout << a->getName() << endl;
    }

    void freshwaterSwimmers() const {
        cout << "\nFreshwater Swimmers:\n";
        for (auto a : animals)
            if (auto s = dynamic_cast<SwimmingAnimal*>(a))
                if (s->needsFreshWater())
                    cout << a->getName() << endl;
    }
};

int main() {
    Zoo zoo;

    zoo.printAll();
    zoo.makeAllSounds();

    zoo.findFlyingAnimals();
    zoo.freshwaterSwimmers();

    return 0;
}
