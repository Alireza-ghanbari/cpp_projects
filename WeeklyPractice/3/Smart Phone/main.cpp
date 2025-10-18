#include <iostream>
#include "Screen.h"

using namespace std;

int main()
{
    Screen screen(12, "560x1080", Screen::PanelType::OLED);
    screen.showInfo();

    screen.setSize(6.8);
    screen.setResolution("1440x3200");
    screen.setPanelType(Screen::PanelType::LCD);

    cout << "\nAfter updating screen properties:\n";
    screen.showInfo();

    cout << "\n--- Accessing individual properties ---\n";
    cout << "Screen size: " << screen.getSize() << " inches\n";
    cout << "Resolution: " << screen.getResolution() << "\n";
    cout << "Panel type: "
         << (screen.getPanelType() == Screen::PanelType::OLED ? "OLED" : "LCD")
         << endl;

    return 0;
}
