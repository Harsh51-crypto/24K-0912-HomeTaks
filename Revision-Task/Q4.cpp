#include <iostream>
using namespace std;

bool isSafe(int maze[4][4], int x, int y, bool visited[4][4]) {
    
    if (x >= 0 && x < 4 && y >= 0 && y < 4 && maze[x][y] == 1 && !visited[x][y])
        return true;
    return false;
}

bool solveMaze(int maze[4][4], int x, int y, bool visited[4][4]) {
   
    if (x == 3 && y == 3) {
        cout << "(" << x << "," << y << ") ";
        return true;
    }

    if (isSafe(maze, x, y, visited)) {
        visited[x][y] = true; 

        cout << "(" << x << "," << y << ") -> ";

       
        if (solveMaze(maze, x, y + 1, visited))
            return true;

       
        if (solveMaze(maze, x + 1, y, visited))
            return true;

       
        if (solveMaze(maze, x, y - 1, visited))
            return true;

        if (solveMaze(maze, x - 1, y, visited))
            return true;

        
        visited[x][y] = false;
        return false;
    }

    return false;
}

int main() {
    int maze[4][4] = {
        {1, 1, 0, 1},
        {0, 1, 1, 0},
        {1, 1, 0, 1},
        {0, 1, 1, 1}
    };

    bool visited[4][4] = {false};

    cout << "Safe path: ";
    if (!solveMaze(maze, 0, 0, visited))
        cout << "No safe path exists!" << endl;

    return 0;
}
