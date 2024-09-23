//      ﷽

//       وَأَنْ لَيْسَ لِلْإِنْسَانِ إِلَّا مَا سَعَى

// https://leetcode.com/problems/coloring-a-border/


#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
class Solution {
    bool vis[55][55];
    const int dx[4] = {0,0,1,-1};
    const int dy[4] = {1,-1,0,0};
    int r , c , old_cell , new_cell;
    vector<vector<int>> res;
    bool boundary(int x,int y ,vector<vector<int>>& grid) {
        if(x == r - 1 || x == 0)
            return true;
        if(y == c - 1 || y == 0)
            return true;
        if(grid[x][y + 1] != old_cell)
            return true;
        if(grid[x][y - 1] != old_cell)
            return true;
        if(grid[x + 1][y] != old_cell)
            return true;
        if(grid[x - 1][y] != old_cell)
            return true;
        return false;
    }
    bool isValid(int x,int y,vector<vector<int>>& grid) {
        return (x < r && x >= 0 && y < c && y >= 0 && grid[x][y] == old_cell && !vis[x][y]);
    }

    void dfs(int x , int y,vector<vector<int>>& grid) {
        vis[x][y] = true;
        if(boundary(x,y,grid))
            res[x][y] = new_cell;

        for(int i = 0 ; i < 4 ; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(isValid(nx,ny,grid)) {
                dfs(nx,ny,grid);
            }
        }
    }
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        memset(vis,false,sizeof vis);
        r = grid.size();
        c = grid[0].size();
        old_cell = grid[row][col];
        new_cell = color;
        res = grid;
        dfs(row,col,grid);
        return res;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
