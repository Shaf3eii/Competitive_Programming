//      ﷽

//       وَأَنْ لَيْسَ لِلْإِنْسَانِ إِلَّا مَا سَعَى

// CSES : https://cses.fi/problemset/task/1192/

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


const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};
//const int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
//const int dy[] = {1, 1, 0, -1, -1, -1, 0, 1};
//const double pi = 3.14159265358979323846264338327950;
//const double EPS = -1e9;

int rows,cols;
const int N = 1e3 +5;
char grid[N][N];
bool vis[N][N];

bool isValid(int x,int y){
    return x >= 0 && x < rows && y >= 0 && y < cols && !vis[x][y];
}

void dfs(int x,int y) {
    vis[x][y] = true;
    for(int d = 0 ; d < 4 ; d++) {
        int nx = dx[d] + x;
        int ny = dy[d] + y;
        if(isValid(nx,ny))
            dfs(nx,ny);
    }
}

void solve() {
    cin >> rows >> cols;
    memset(vis,false,sizeof vis);
    for(int r = 0 ; r < rows ; ++r) {
        for(int c = 0 ; c < cols; ++c) {
            cin >> grid[r][c];
            if(grid[r][c] == '#')
                vis[r][c] = true;
        }
    }
    int no_of_rooms = 0;
    for(int r = 0 ; r < rows ; ++r) {
        for(int c = 0 ; c < cols; ++c) {
            if(!vis[r][c]) {
                no_of_rooms++;
                dfs(r,c);
            }
        }
    }
    cout << no_of_rooms;
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