#include "OS.h"
#include <iostream>
using namespace std;

int main()
{
    OS myOS("Android", "12.0");
    myOS.showInfo();

    myOS.setName("IOS");
    myOS.setVersion("14.1");
    myOS.showInfo();

    myOS.updateOS("15.0");

    cout << "\nCurrent OS details:\n";
    cout << "Name: " << myOS.getName() << endl;
    cout << "Version: " << myOS.getVersion() << endl;

    return 0;
}
