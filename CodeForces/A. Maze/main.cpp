//      ﷽

//       وَأَنْ لَيْسَ لِلْإِنْسَانِ إِلَّا مَا سَعَى

// https://codeforces.com/contest/377/problem/A    --> Div.1

//   "From the river to the sea, Palestine is Free"

// Seek knowledge from the Cradle to the Grave.

// Never Give up -- Life is too short to make mistakes and learn from them -- Learn from other's mistakes

// Remember you were always a novice when you started so never be rude to some one

// Aim Big and strive hard to get it

// One has his own set of talents and anyone can do anything so never compare yourself to anybody

//#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

// 48-57 -> 0-9  65-90 -> A-Z 97-122 -> a-z
#define Free_Palestine  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define i64             long long
#define all(a)          a.begin(),a.end()
#define all_r(a)        a.rbegin(),a.rend()
#define vi              vector<int>
#define ef              else if
#define retv(x)         return void(cout << (x) << '\n')
#define sp              " "
#define SetPre(n, x)    cout << fixed << setprecision(n) << x << '\n'
#define Mod  1'000'000'007
#define INF 2'000'000'000
#define Time cerr << "Time Taken: " << (float)clock() / CLOCKS_PER_SEC << " Secs" << "\n";
#define sz(s) (int)(s).size()


//  وَلَسَوْفَ يُعْطِيكَ رَبُّكَ فَتَرْضَى

const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};
//const int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
//const int dy[] = {1, 1, 0, -1, -1, -1, 0, 1};
//const double pi = 3.14159265358979323846264338327950;
//const double EPS = -1e9;

void solve() {
    int rows,cols,k;
    cin >> rows >> cols >> k;
    vector<vector<char>> grid(rows, vector<char>(cols));
    vector<vector<bool>> vis(rows, vector<bool>(cols, false));
    for(int r = 0 ; r < rows ; ++r)
        for(int c = 0 ; c < cols ; ++c)
            cin >> grid[r][c];
    auto isValid = [&](int x,int y) {
        return x >= 0 && x < rows && y >= 0 && y < cols && grid[x][y] != '#' && !vis[x][y] && grid[x][y] != 'X' && k;
    };
    auto dfs = [&](auto&self,int x,int y) ->void{
        vis[x][y] = true;
        for(int i = 0 ; i < 4 ; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(isValid(nx,ny)) {
                    self(self,nx,ny);
            }
        }
        if(grid[x][y] == '.' && k)
            grid[x][y] = 'X' , k--;
    };

    for(int r = 0 ; r < rows ; r++)
        for(int c = 0 ; c < cols ; c++)
            if(grid[r][c] == '.' && k)
                dfs(dfs,r,c);

    for(int r = 0 ; r < rows ; ++r) {
        for (int c = 0; c < cols; ++c)
            cout << grid[r][c];

        cout << '\n';
    }
}

signed main() {
    Free_Palestine
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t = 1;
//    cin >> t;
    while (t--)
        solve();

    Time
    return 0;
}