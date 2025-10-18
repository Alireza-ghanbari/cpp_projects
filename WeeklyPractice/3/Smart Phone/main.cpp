#include "CPU.h"
#include <iostream>
using namespace std;

int main()
{
    CPU cpu(4, 2.4, "Intel");
    cpu.showInfo();

    cpu.setCores(8);
    cpu.setFrequencyGHz(3.2);
    cpu.setCreator("Razen");

    cout << "\nUpdated CPU Info:\n\n";
    cout << "Cores: " << cpu.getCores() << endl;
    cout << "Frequency: " << cpu.getFrequencyGHz() << " GHz" << endl;
    cout << "Creator: " << cpu.getCreator() << endl;

    return 0;
}
