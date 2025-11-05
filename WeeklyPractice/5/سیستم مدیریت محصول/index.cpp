#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Product
{
    string name;
    double price;
    static int totalProducts;

public:
    Product(string n = "", double p = 0) : name(n), price(p)
    {
        if (!n.empty())
            totalProducts++;
    }

    void setPrice(double p) { price = p; }

    double getPrice() const { return price; }

    string getName() const { return name; }

    void display() const { cout << name << " - " << fixed << setprecision(0) << price << endl; }

    static int getTotal() { return totalProducts; }

    friend bool isCheaper(const Product &a, const Product &b);
};

int Product::totalProducts = 0;

bool isCheaper(const Product &a, const Product &b)
{
    return a.price < b.price;
}

class Store
{
    Product *products;
    int count;

public:
    Store(int c) : count(c)
    {
        products = new Product[count];
    }

    ~Store()
    {
        delete[] products;
    }

    void setProduct(int index, string name, double price)
    {
        if (index >= 0 && index < count)
        {
            products[index] = Product(name, price);
        }
    }

    void showAll() const
    {
        for (int i = 0; i < count; i++)
            products[i].display();
    }

    double averagePrice() const
    {
        double sum = 0;
        for (int i = 0; i < count; i++)
            sum += products[i].getPrice();
        return (count > 0) ? sum / count : 0;
    }

    const Product &getProduct(int index) const
    {
        return products[index];
    }
};

int main()
{
    int n;
    cin >> n;

    Store s(n);
    string name;
    double price;

    for (int i = 0; i < n; i++)
    {
        cin >> name >> price;
        s.setProduct(i, name, price);
    }

    s.showAll();
    cout << "Average price: " << fixed << setprecision(0) << s.averagePrice() << endl;
    cout << "Total products: " << Product::getTotal() << endl;

    const Product &p1 = s.getProduct(0);
    const Product &p2 = s.getProduct(2);

    cout << "Cheaper between " << p1.getName() << " and " << p2.getName() << ": "
         << (isCheaper(p1, p2) ? p1.getName() : p2.getName()) << endl;

    return 0;
}
