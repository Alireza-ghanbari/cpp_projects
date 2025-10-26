#include <iostream>
#include <string>
#include <vector>
using namespace std;

class FootballPlayer
{
private:
    string name;
    int age;
    string team;
    int goals;

public:
    FootballPlayer(string n, int a, string t, int g)
        : name(n), age(a), team(t), goals(g) {}

    void scoreGoal()
    {
        goals++;
    }

    string getPlayerInfo() const
    {
        return "Name: " + name + ", Age: " + to_string(age) +
               ", Team: " + team + ", Goals: " + to_string(goals);
    }

    int getGoals() const
    {
        return goals;
    }

    string getName() const
    {
        return name;
    }
};

class Team
{
private:
    string teamName;
    vector<FootballPlayer> players;

public:
    Team(string tName) : teamName(tName) {}

    void addPlayer(const FootballPlayer &player)
    {
        players.push_back(player);
    }

    void getTeamInfo() const
    {
        cout << "******************************" << endl;
        cout << "Team " << teamName << " information:" << endl;
        for (const auto &player : players)
        {
            cout << player.getPlayerInfo() << endl;
        }
    }

    void getTopScorer() const
    {
        if (players.empty())
        {
            cout << "No players in the team!" << endl;
            return;
        }

        const FootballPlayer *topPlayer = &players[0];
        for (const auto &player : players)
        {
            if (player.getGoals() > topPlayer->getGoals())
            {
                topPlayer = &player;
            }
        }

        cout << "Top Player of team " << teamName << ": "
             << topPlayer->getName()
             << " with " << topPlayer->getGoals() << " goals." << endl;
    }
};

int main()
{
    Team team1("Blue");
    Team team2("Red");

    FootballPlayer p1("Ali", 28, "Blue", 10);
    FootballPlayer p2("Reza", 25, "Blue", 7);
    FootballPlayer p3("Hassan", 21, "Blue", 5);
    FootballPlayer p4("Mmd", 30, "Red", 12);

    team1.addPlayer(p1);
    team1.addPlayer(p2);
    team1.addPlayer(p3);
    team2.addPlayer(p4);

    team1.getTeamInfo();
    team2.getTeamInfo();

    cout << "******************************" << endl;

    team1.getTopScorer();
    team2.getTopScorer();

    cout << "******************************" << endl;

    return 0;
}
