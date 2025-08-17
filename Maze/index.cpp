#include <iostream>
using namespace std;

const int SIZE = 10;
int maze[SIZE][SIZE];
bool visited[SIZE][SIZE];
pair<int, int> parent[SIZE][SIZE];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool isValid(int x, int y)
{
    return (x >= 0 && x < SIZE && y >= 0 && y < SIZE &&
            maze[x][y] == 0 && !visited[x][y]);
}

bool bfs()
{
    int queueX[SIZE * SIZE];
    int queueY[SIZE * SIZE];
    int front = 0, rear = 0;

    queueX[rear] = 0;
    queueY[rear] = 0;
    rear++;
    visited[0][0] = true;

    while (front < rear)
    {
        int x = queueX[front];
        int y = queueY[front];
        front++;

        if (x == SIZE - 1 && y == SIZE - 1)
        {
            return true;
        }

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (isValid(nx, ny))
            {
                visited[nx][ny] = true;
                parent[nx][ny] = make_pair(x, y);
                queueX[rear] = nx;
                queueY[rear] = ny;
                rear++;
            }
        }
    }

    return false;
}

void printPath()
{
    int pathX[SIZE * SIZE];
    int pathY[SIZE * SIZE];
    int length = 0;

    int x = SIZE - 1, y = SIZE - 1;
    while (!(x == 0 && y == 0))
    {
        pathX[length] = x;
        pathY[length] = y;
        length++;
        int px = parent[x][y].first;
        int py = parent[x][y].second;
        x = px;
        y = py;
    }

    pathX[length] = 0;
    pathY[length] = 0;
    length++;

    cout << "The path is:\n";
    for (int i = length - 1; i >= 0; i--)
    {
        cout << "(" << pathX[i] << "," << pathY[i] << ")";
        if (i != 0)
            cout << " -> ";
    }
    cout << endl;
}

int main()
{
    cout << "Enter the maze (10x10) with 0 for path and 1 for wall:\n";
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            cin >> maze[i][j];
            visited[i][j] = false;
            parent[i][j] = make_pair(-1, -1);
        }
    }

    if (maze[0][0] == 1 || maze[SIZE - 1][SIZE - 1] == 1)
    {
        cout << "Start or end is blocked.\n";
        return 0;
    }

    if (bfs())
    {
        printPath();
    }
    else
    {
        cout << "No path found.\n";
    }

    return 0;
}

// with way

// 0 1 0 0 0 0 0 0 0 0
// 0 1 0 1 1 1 1 1 1 0
// 0 0 0 0 0 0 0 0 1 0
// 1 1 1 1 1 1 1 0 1 0
// 0 0 0 0 0 0 1 0 1 0
// 0 1 1 1 1 0 1 0 1 0
// 0 0 0 0 1 0 1 0 1 0
// 1 1 1 0 1 0 1 0 1 0
// 0 0 0 0 1 0 0 0 1 0
// 0 1 1 1 1 1 1 1 1 0

// sec with way

// 0 1 0 0 0 0 0 0 0 0
// 0 1 0 1 1 1 1 1 1 0
// 0 0 0 0 0 0 0 0 1 0
// 0 1 1 1 1 1 1 0 1 0
// 0 0 0 0 0 0 1 1 1 0
// 0 1 1 1 1 0 1 0 1 0
// 0 0 0 0 1 0 1 0 1 0
// 1 1 1 0 1 0 1 0 1 1
// 0 0 1 0 0 0 0 0 0 0
// 0 1 1 1 1 1 1 1 1 0

// none way

// 0 1 0 0 0 0 0 0 0 0
// 0 1 0 1 1 1 1 1 1 0
// 0 0 0 0 0 0 0 0 1 0
// 1 1 1 1 1 1 1 0 1 0
// 0 0 0 0 0 0 1 0 1 1
// 0 1 1 1 1 0 1 0 1 0
// 0 0 0 0 1 0 1 0 1 0
// 1 1 1 0 1 0 1 0 1 0
// 0 0 0 0 1 0 0 0 1 0
// 0 1 1 1 1 1 1 1 1 0
