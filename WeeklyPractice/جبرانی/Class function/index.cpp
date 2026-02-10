#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

enum class SortMode
{
    NORMAL,
    SPECIAL
};
enum class SortKey
{
    SPEED,
    HEIGHT,
    TORQUE
};
enum class Order
{
    ASCENDING,
    DESCENDING
};

class Plane
{
protected:
    string name;
    double speed;
    double height;
    double torque;

public:
    Plane(string n, double s, double h, double t)
        : name(n), speed(s), height(h), torque(t) {}

    virtual ~Plane() {}

    string getName() const { return name; }
    virtual int categoryRank() const = 0;
    virtual double maxSpeed() const = 0;
    virtual double maxHeight() const = 0;
    virtual double maxTorque() const = 0;
};

class Fighter : public Plane
{
public:
    using Plane::Plane;
    int categoryRank() const override { return 1; }
    double maxSpeed() const override { return speed; }
    double maxHeight() const override { return height; }
    double maxTorque() const override { return torque; }
};

class Cargo : public Plane
{
public:
    using Plane::Plane;
    int categoryRank() const override { return 2; }
    double maxSpeed() const override { return speed; }
    double maxHeight() const override { return height; }
    double maxTorque() const override { return torque; }
};

class Carrier : public Plane
{
public:
    using Plane::Plane;
    int categoryRank() const override { return 3; }
    double maxSpeed() const override { return speed; }
    double maxHeight() const override { return height; }
    double maxTorque() const override { return torque; }
};

class Compare
{
public:
    bool operator()(SortMode mode, SortKey key, Order order, const Plane *a, const Plane *b) const
    {
        if (a->categoryRank() != b->categoryRank())
        {
            return a->categoryRank() < b->categoryRank();
        }

        double valA = 0, valB = 0;
        switch (key)
        {
        case SortKey::SPEED:
            valA = a->maxSpeed();
            valB = b->maxSpeed();
            break;
        case SortKey::HEIGHT:
            valA = a->maxHeight();
            valB = b->maxHeight();
            break;
        case SortKey::TORQUE:
            valA = a->maxTorque();
            valB = b->maxTorque();
            break;
        }

        if (order == Order::ASCENDING)
            return valA < valB;
        return valA > valB;
    }
};

int main()
{
    vector<Plane *> planes;
    planes.push_back(new Cargo("C-130", 540, 10000, 4600));
    planes.push_back(new Fighter("F-22", 2410, 20000, 1500));
    planes.push_back(new Carrier("Nimitz", 56, 0, 50000));
    planes.push_back(new Fighter("F-35", 1930, 18000, 1200));

    Compare cmp;
    SortMode mode = SortMode::NORMAL;
    SortKey key = SortKey::SPEED;
    Order order = Order::DESCENDING;

    auto boundCmp = bind(cmp, mode, key, order, placeholders::_1, placeholders::_2);

    sort(planes.begin(), planes.end(), boundCmp);

    for (const auto *p : planes)
    {
        cout << "[" << p->categoryRank() << "] " << p->getName()
             << " - Speed: " << p->maxSpeed() << endl;
    }

    for (auto *p : planes)
        delete p;
    return 0;
}