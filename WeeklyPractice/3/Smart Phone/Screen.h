#ifndef SCREEN_H
#define SCREEN_H

#include <string>
#include <iostream>
using namespace std;

class Screen
{
public:
    enum class PanelType
    {
        LCD,
        OLED
    };

private:
    double sizeInches;
    string resolution;
    PanelType panel;

public:
    Screen(double size = 6.0, string res = "1080x2400", PanelType type = PanelType::LCD);

    void showInfo() const;

    // Getter
    double getSize() const;
    string getResolution() const;
    PanelType getPanelType() const;

    // Setter
    void setSize(double size);
    void setResolution(const string res);
    void setPanelType(PanelType type);
};

#endif
