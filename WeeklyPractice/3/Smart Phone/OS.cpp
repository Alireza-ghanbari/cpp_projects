#include "OS.h"
#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

OS::OS(string n, string v)
    : name(n), version(v) {}

void OS::showInfo() const
{
    cout << "Operating System: " << name << " v" << version << endl;
}

// --- متد آپدیت سیستم عامل ---
void OS::updateOS(const string newVersion)
{
    cout << "Checking for updates..." << endl;
    version = newVersion;
    cout << "Update successful! Current version: v" << version << endl;
}

//  Getter
string OS::getName() const
{
    return name;
}

string OS::getVersion() const
{
    return version;
}

// Setter
void OS::setName(const string n)
{
    if (!n.empty())
        name = n;
    else
        cout << "OS name cannot be empty!" << endl;
}

void OS::setVersion(const string v)
{
    if (!v.empty())
        version = v;
    else
        cout << "Version cannot be empty!" << endl;
}
