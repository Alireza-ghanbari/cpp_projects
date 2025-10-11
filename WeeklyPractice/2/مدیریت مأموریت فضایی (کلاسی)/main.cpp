#include <iostream>
#include "MissionMember.h"

using namespace std;

int main()
{
    cout << "Mission has started" << endl << endl;

    MissionMember::showActiveMembers();
    cout << endl;

    MissionMember agent1("ali", "sarbaz", 70);
    MissionMember agent2("sina", "dastyar", 80);
    MissionMember agent3("hossein", "farmande", 100);
    MissionMember agent4("mohammad", "sarbaz", 70);
    MissionMember agent5("kazem", "researcher", 90);

    cout << endl;
    MissionMember::showActiveMembers();

    cout << endl;
    agent1.work(3);
    agent3.work(1);
    agent5.work(4);

    cout << endl;
    agent1.status();
    agent2.status();
    agent3.status();
    agent4.status();
    agent5.status();

    return 0;
}