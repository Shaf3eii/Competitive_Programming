//      ﷽

//       وَأَنْ لَيْسَ لِلْإِنْسَانِ إِلَّا مَا سَعَى

//  https://codeforces.com/contest/520/problem/B

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
    int n , m;
    cin >> n >> m;
    int clicks = 0;
    queue<int> q;
    q.push(n);
    int N = 4e4 + 5;
    bool vis[N];
    memset(vis,false,sizeof vis);
    while(!q.empty()) {
        int sz = sz(q);
        for(int i = 0 ; i < sz ; ++i) {
            int node = q.front();
            q.pop();
            if (node == m)
                retv(clicks);
            vis[node] = true;
            int red = node * 2;
            int blue = node - 1;
//            cout << clicks << " : " << red << sp << blue << '\n';
            if (red <= 2e4 && !vis[red])
                q.push(red);
            if (blue > 0 && !vis[blue])
                q.push(blue);
        }
        clicks++;
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