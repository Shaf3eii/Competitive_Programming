//      ﷽

//       وَأَنْ لَيْسَ لِلْإِنْسَانِ إِلَّا مَا سَعَى

// vjudge : https://vjudge.net/contest/561509#problem/N

// Spoj : https://www.spoj.com/problems/PT07Y/

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

//const int dx[] = {0, 0, 1, -1};
//const int dy[] = {1, -1, 0, 0};
//const int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
//const int dy[] = {1, 1, 0, -1, -1, -1, 0, 1};
//const double pi = 3.14159265358979323846264338327950;
//const double EPS = -1e9;

void solve() {
    int nodes , edges;
    cin >> nodes >> edges;
    vector<vector<int>> adj_list(nodes + 1);
    vector<bool> vis(nodes + 1, false);
    for(int i = 0 ; i < edges ; ++i) {
        int u,v;
        cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
    if (edges != nodes - 1)
        retv("NO\n");

    auto dfs = [&](auto&self ,int node) -> void {
        vis[node] = true;
         for(auto& neighbour : adj_list[node]) {
             if(!vis[neighbour])
                 self(self,neighbour);
         }
    };
    dfs(dfs,1);
//    cout << vis << '\n';
    for(int i = 1 ; i <= nodes ; ++i)
        if(!vis[i])
            retv("NO\n");
    cout << "YES\n";
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