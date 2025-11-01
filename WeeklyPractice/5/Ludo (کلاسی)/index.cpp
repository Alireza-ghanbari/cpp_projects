#include <iostream>
#include <string>

using namespace std;

class Player
{
private:
    string name;
    int position;

public:
    Player(string n)
    {
        name = n;
        position = 0;
    }

    void move(int steps)
    {
        position += steps;
    }

    void getInfo() const
    {
        cout << "Player: " << name << ". In posotion: " << position << endl;
    }
    string getName() const
    {
        return name;
    }
    int getPosition() const
    {
        return position;
    }
    void resetPosition()
    {
        position = 0;
    }
    void setPosition(int pos)
    {
        position = pos;
    }
};

class Ludo
{
private:
    Player *players[4];
    int safeCells[10];
    int safeCount;
    int currentCount;

public:
    static int totalPlayers;
    const static int TARGET = 30;

    Ludo(int safeCellsInput[], int count)
    {
        safeCount = count;
        for (int i = 0; i < count; i++)
            safeCells[i] = safeCellsInput[i];

        currentCount = 0;
        totalPlayers++;
    }

    void addPlayer(Player *p)
    {
        if (currentCount < 4)
        {
            players[currentCount++] = p;
            cout << "New player join: " << p->getName() << endl;
        }
        else
            cout << "Can't join. Maximum is 4" << endl;
    }

    bool isSafeCell(int cell)
    {
        for (int i = 0; i < safeCount; i++)
        {
            if (safeCells[i] == cell)
                return true;
        }
        return false;
    }

    void playerTurn(int index, int steps)
    {
        if (index < 0 || index >= currentCount)
        {
            cout << "Invalid player index" << endl;
            return;
        }
        Player *p = players[index];
        int currentPos = p->getPosition();
        int newPos = currentPos += steps;

        if (newPos > TARGET)
        {
            cout << p->getName() << " Can't move beyond TARGET (" << TARGET << ")." << endl;
            return;
        }

        if (newPos == TARGET)
        {
            p->setPosition(30);
            cout << p->getName() << " reached the TARGET and won!" << endl;
            return;
        }

        bool safe = isSafeCell(newPos);
        bool collision = false;

        for (int i = 0; i < currentCount; i++)
        {
            if (i != index && players[i]->getPosition() == newPos)
            {
                if (!safe)
                {
                    cout << "Collision! " << p->getName() << " hit " << players[i]->getName() << endl;
                    players[i]->resetPosition();
                }
                collision = true;
            }
        }

        p->move(steps);
        cout << p->getName() << " Move to: " << p->getPosition() << endl;
    }

    void showPlayers()
    {
        cout << "\nPlayers Info:\n";
        for (int i = 0; i < currentCount; i++)
        {
            players[i]->getInfo();
        }
    }

    void getCurrentPlayers()
    {
        cout << "\nTotal Players Created: " << currentCount << endl;
    }

    // static void getTotalPlayers()
    // {
    //     cout << "\nTotal Players Created (All Games): " << totalPlayers << endl;
    // }
};

int Ludo::totalPlayers = 0;

int main()
{
    int safeCells[] = {3, 6, 9, 15, 21};
    Ludo game(safeCells, 5);

    Player *p1 = new Player("Ali");
    Player *p2 = new Player("Mehdi");
    Player *p3 = new Player("Sara");

    game.addPlayer(p1);
    game.addPlayer(p2);
    game.addPlayer(p3);

    game.playerTurn(0, 3);
    game.playerTurn(1, 3);
    game.playerTurn(2, 4);
    game.playerTurn(0, 1);
    game.playerTurn(2, 6);
    game.playerTurn(1, 9);
    game.playerTurn(0, 22);
    game.playerTurn(0, 4);

    game.showPlayers();
    // Ludo::getTotalPlayers();
    game.getCurrentPlayers();

    return 0;
}