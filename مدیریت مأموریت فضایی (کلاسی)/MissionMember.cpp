#include <iostream>
#include "MissionMember.h"

using namespace std;

int MissionMember::activeMembers = 0;

MissionMember::MissionMember(string n, string r, int e)
{
    name = n;
    role = r;
    energy = e;
    activeMembers++;
    cout << name << " (" << role << ") enter to mission" << endl;
}

MissionMember::~MissionMember()
{
    activeMembers--;
    cout << endl;
    cout << name << "exit from mission" << endl;
}

void MissionMember::work(int hours)
{
    int decrease = hours * 10;
    energy -= decrease;
    if (energy < 0)
        energy = 0;
    cout << name << " worked " << hours << " hours" << " --> " << "energy status: " << energy << endl;
}

void MissionMember::rest(int hours)
{
    int increase = hours * 20;
    energy += increase;
    if (energy > 100)
        energy = 100;
    cout << name << " rest " << hours << "hour" << "-->" << " energy status: " << energy << endl;
}

void MissionMember::status() const
{
    cout << "name: " << name << endl;
    cout << "role: " << role << endl;
    cout << "energy: " << energy << endl;
    cout << "active members: " << activeMembers << endl;
}

void MissionMember::showActiveMembers()
{
    cout << endl;
    cout << "active members is : " << activeMembers << endl;
}