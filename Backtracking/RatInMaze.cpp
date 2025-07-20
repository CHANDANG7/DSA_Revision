// Backtracking: Rat in a Maze
#include <vector>
using namespace std;

bool solveMaze(vector<vector<int>>& maze, int x, int y, vector<vector<int>>& sol) {
    int n = maze.size();
    if (x == n - 1 && y == n - 1 && maze[x][y] == 1) {
        sol[x][y] = 1;
        return true;
    }
    if (x >= 0 && y >= 0 && x < n && y < n && maze[x][y] == 1) {
        sol[x][y] = 1;
        if (solveMaze(maze, x + 1, y, sol)) return true;
        if (solveMaze(maze, x, y + 1, sol)) return true;
        sol[x][y] = 0;
        return false;
    }
    return false;
}
