//      ﷽

//       وَأَنْ لَيْسَ لِلْإِنْسَانِ إِلَّا مَا سَعَى

// https://leetcode.com/problems/number-of-closed-islands/description/


#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

class Solution {
    bool vis[105][105];
    int rows , cols;
    const int dx[4] = {0,0,1,-1};
    const int dy[4] = {1,-1,0,0};

    bool isValid(int x,int y , vector<vector<int>> &grid) {
        return x >= 0 && x < rows && y >= 0 && y < cols && !vis[x][y] && !grid[x][y];
    }

    void dfs(int x, int y, vector<vector<int>>& grid) {
        vis[x][y] = true;
        for(int d = 0 ; d < 4 ; ++d) {
            int nx = dx[d] + x;
            int ny = dy[d] + y;
            if(isValid(nx,ny,grid))
                dfs(nx,ny,grid);
        }
    }

public:
    int closedIsland(vector<vector<int>>& grid) {
        rows = (int)grid.size();
        cols = (int)grid[0].size();
        memset(vis,false,sizeof vis);
        for(int c = 0 ; c < cols ; ++c)
            if(!grid[0][c])
                dfs(0,c,grid);

        for(int c = 0 ; c < cols ; ++c)
            if(!grid[rows - 1][c])
                dfs(rows -1 , c , grid);
        for(int r = 0 ; r < rows ; ++r)
            if(!grid[r][0])
                dfs(r,0,grid);
        for(int r = 0 ; r < rows ; ++r)
            if(!grid[r][cols-1])
              dfs(r,cols-1,grid);

        int number_of_islands = 0;
        for(int r = 0 ; r < rows ; ++r)
            for(int c = 0 ; c < cols ; ++c)
                if(!grid[r][c] && !vis[r][c])
                    number_of_islands++ , dfs(r,c,grid);

        return number_of_islands;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
