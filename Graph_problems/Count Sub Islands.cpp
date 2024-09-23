//      ﷽

//       وَأَنْ لَيْسَ لِلْإِنْسَانِ إِلَّا مَا سَعَى

// https://leetcode.com/problems/count-sub-islands/description/


#include <iostream>
#include <vector>
#include <cstring>

using namespace std;


// first approach -> if the grid1 == 0 && grid2 == 1 ,then it is not valid sub island

class Solution1 {
    bool vis[505][505];
    int r1 , c1 , r2 , c2;
    bool is_Sub_island;
    const int dx[4] = {1,-1,0,0};
    const int dy[4] = {0,0,1,-1};

    bool isValid(int x,int y , vector<vector<int>>& grid) {
        return x >= 0 && x < r2 && y >= 0 && y < c2 && !vis[x][y] && grid[x][y];
    }
    void dfs(int x,int y, vector<vector<int>>& grid1,vector<vector<int>>& grid2) {
        if(grid2[x][y] && !grid1[x][y]) {
            is_Sub_island = false;
            return;
        }
        vis[x][y] = true;
        for(int i = 0 ; i < 4 ; ++i) {
            int nx = dx[i] + x;
            int ny = dy[i] + y;
            if(isValid(nx,ny,grid2))
                dfs(nx,ny,grid1,grid2);
        }
    }
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        r1 = (int)grid1.size();
        c1 = (int)grid1[0].size();
        r2 = (int)grid2.size();
        c2 = (int)grid2[0].size();

        int sub_islands = 0;
        for(int r = 0 ; r < r2 ; ++r)
            for(int c = 0 ; c < c2 ; ++c)
                if(grid2[r][c] && !vis[r][c]) {
                    is_Sub_island = true;
                    dfs(r,c,grid1,grid2);
                    sub_islands += is_Sub_island;
                }
        return sub_islands;
    }
};


// second approach -> mark all invalid sub islands -> vis[x][y] = true, then count valid sub islands

class Solution2 {
    bool vis[505][505];
    int r1 , c1 , r2 , c2;
    const int dx[4] = {1,-1,0,0};
    const int dy[4] = {0,0,1,-1};

    bool isValid(int x,int y , vector<vector<int>>& grid) {
        return x >= 0 && x < r2 && y >= 0 && y < c2 && !vis[x][y] && grid[x][y];
    }
    void dfs(int x,int y, vector<vector<int>> &grid) {
        vis[x][y] = true;
        for(int i = 0 ; i < 4 ; ++i) {
            int nx = dx[i] + x;
            int ny = dy[i] + y;
            if(isValid(nx,ny,grid))
                dfs(nx,ny,grid);
        }
    }
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        r1 = (int)grid1.size();
        c1 = (int)grid1[0].size();
        r2 = (int)grid2.size();
        c2 = (int)grid2[0].size();

        for(int r = 0 ; r < r1 ; ++r)
            for(int c = 0 ; c < c1 ; ++c)
                if(!grid1[r][c] && grid2[r][c])
                    dfs(r,c,grid2);
        int sub_islands = 0;
        for(int r = 0 ; r < r2 ; ++r)
            for(int c = 0 ; c < c2 ; ++c)
                if(grid2[r][c] && !vis[r][c])
                    sub_islands++ , dfs(r,c,grid2);
        return sub_islands;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
