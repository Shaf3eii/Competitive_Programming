//      ﷽

//       وَأَنْ لَيْسَ لِلْإِنْسَانِ إِلَّا مَا سَعَى

// https://leetcode.com/problems/flood-fill/description/


#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int dx[4] = {1,-1,0,0};
        int dy[4] = {0,0,1,-1};
        int r = image.size();
        int c = image[0].size();
        bool vis[55][55];
        int origin = image[sr][sc];
        memset(vis,false,sizeof vis);
        auto isValid = [&](int x,int y){
            return x < r && x >= 0 && y < c && y >= 0 && !vis[x][y] && image[x][y] == origin;
        };
        auto dfs = [&](auto& self , int x, int y)->void {
            vis[x][y] = true;
            image[x][y] = color;
            for(int i = 0 ; i < 4 ; ++i) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(isValid(nx,ny)) {
                    self(self,nx,ny);
                }
            }
        };
        dfs(dfs,sr,sc);
        return image;
    }
};

int main() {

    return 0;
}
