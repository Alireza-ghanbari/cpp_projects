#ifndef MISSIONMEMBER_H
#define MISSIONMEMBER_H

#include <string>
using namespace std;

class MissionMember
{
private:
    string name;
    string role;
    int energy;
    static int activeMembers;

public:
    MissionMember(string n, string r, int e = 100);
    ~MissionMember();
    void work(int hours);
    void rest(int hours);
    void status() const;
    static void showActiveMembers();
};

#endif
