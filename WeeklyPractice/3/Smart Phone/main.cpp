#include <iostream>
#include "SmartPhone.h"
using namespace std;

int main()
{
    SmartPhone myPhone("Iphone Xs");

    myPhone.showInfo();

    myPhone.useBattery(25);

    myPhone.chargeBattery(15);

    cout << "\nCPU Info:\n";
    myPhone.getCPU().showInfo();

    cout << "\nFront Camera Info:\n";
    myPhone.getFrontCamera().showInfo();

    cout << "\nScreen Info:\n";
    myPhone.getScreen().showInfo();

    myPhone.setModel("Iphone X");
    cout << "Model after update: " << myPhone.getModel() << endl;

    return 0;
}
