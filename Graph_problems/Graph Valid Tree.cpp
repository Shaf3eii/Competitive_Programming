//      ﷽

//       وَأَنْ لَيْسَ لِلْإِنْسَانِ إِلَّا مَا سَعَى

// https://leetcode.com/problems/graph-valid-tree/description/


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

void solve() {
    int nodes , edges;
    cin >> nodes >> edges;
    if (edges != nodes - 1)
        retv("False\n");

    vector<vector<int>> graph(nodes);
    int vis[nodes];
    memset(vis,false,sizeof vis);
    for(int i = 0 ; i < edges ; ++i) {
        int from,to;
        cin >> from >> to;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }
    auto BFS = [&]() ->bool {
        queue<pair<int,int>> q;
        q.emplace(0,-1);
        vis[0] = true;
        while(!q.empty()) {
            int node = q.front().first , parent = q.front().second;
            q.pop();
            vis[node] = true;
            for(auto &i : graph[node]) {
                if (!vis[i])
                    q.emplace(i,node);
                else if(i != parent)
                    return false;
            }
        }
        return true;
    };
    if(!BFS())
        retv("False\n");
    for(auto& i : vis)
        if(!i)
            retv("False\n");
    cout << "True\n";
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