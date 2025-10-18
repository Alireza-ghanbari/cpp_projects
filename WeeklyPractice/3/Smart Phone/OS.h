#ifndef OS_H
#define OS_H

#include <string>
#include <iostream>
using namespace std;

class OS
{
private:
    string name;
    string version;

public:
    OS(string n = "iOS", string v = "14.0");

    void showInfo() const;
    void updateOS(const string &newVersion);

    //  Getters
    string getName() const;
    string getVersion() const;

    //  Setters
    void setName(const string &n);
    void setVersion(const string &v);
};

#endif
