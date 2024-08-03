//      ﷽

// submission : https://codeforces.com/contest/330/submission/274093752

//       وَأَنْ لَيْسَ لِلْإِنْسَانِ إِلَّا مَا سَعَى

//   "From the river to the sea, Palestine is Free"

// Seek knowledge from the Cradle to the Grave.

// Never Give up -- Life is too short to make mistakes and learn from them -- Learn from other's mistakes

// Remember you were always a novice when you started so never be rude to some one

// Aim Big and strive hard to get it

// One has his own set of talents and anyone can do anything so never compare yourself to anybody

#include <bits/stdc++.h>

using namespace std;

// 48-57 -> 0-9  65-90 -> A-Z 97-122 -> a-z
#define Free_Palestine  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define i64             long long

void solve() {
    int r , c;
    cin >> r >> c;
    vector<vector<char>> grid(r , vector<char> (c));
    bool vis[10][10];
    int cakes = 0;
    memset(vis,false,sizeof vis);
    for(auto &i : grid)
        for(auto &j : i)
            cin >> j;

    // go horizontally;
    for(int i = 0 ; i < r ; ++i)
    {
        bool strawberry = false;
        for(int k = 0 ; k < c; ++k) {
            if (grid[i][k] == 'S') {
                strawberry = true;
                break;
            }
        }
        if(!strawberry) {
            int cnt = 0;
            for (int j = 0; j < c; ++j) {
                if (grid[i][j] == 'S') {
                    cnt = 0;
                    break;
                }
                if (!vis[i][j]) {
                    vis[i][j] = true;
                    cnt++;
                }
            }
            cakes += cnt;
        }
    }

    // go vertically;
    for(int i = 0 ; i < c ; ++i)
    {
        bool strawberry = false;
        for(int k = 0 ; k < r; ++k) {
            if (grid[k][i] == 'S') {
                strawberry = true;
                break;
            }
        }
        if(!strawberry) {
            int cnt = 0;
            for (int j = 0; j < r; ++j) {
                if (grid[j][i] == 'S') {
                    cnt = 0;
                    break;
                }
                if (!vis[j][i]) {
                    vis[j][i] = true;
                    cnt++;
                }
            }
            cakes += cnt;
        }
    }
    cout << cakes << '\n';
}

signed main() {
    Free_Palestine
    int t = 1;
//    cin >> t;
    while (t--)
        solve();

    return 0;
}
