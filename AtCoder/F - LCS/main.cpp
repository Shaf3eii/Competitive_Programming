//      ﷽

//       وَأَنْ لَيْسَ لِلْإِنْسَانِ إِلَّا مَا سَعَى

//      ShaFeiii Here

//      "If you don't fight, You can't win!"

//#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, less<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> ordered_set;

// 48-57 -> 0-9  65-90 -> A-Z 97-122 -> a-z
#define Wl3_ElNor       ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define i64             long long
#define int             long long
#define all(a)          a.begin(),a.end()
#define all_r(a)        a.rbegin(),a.rend()
#define vi              vector<int>
#define ef              else if
#define retv(x)         return void(cout << (x) << '\n')
#define sp              " "
#define SetPre(n, x)    cout << fixed << setprecision(n) << x << '\n'
#define Mod             1'000'000'007
#define INF             2'000'000'000
#define sz(s)           (int)(s).size()

//const int dx[] = {0, 0, 1, -1};
//const int dy[] = {1, -1, 0, 0};
//const int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
//const int dy[] = {1, 1, 0, -1, -1, -1, 0, 1};
//const double pi = 3.14159265358979323846264338327950;
//const double EPS = -1e9;

string n, m, ans;
int dp[3005][3005];

int LCS(int i, int j) {
    if(i == sz(n) || j == sz(m))
        return 0;
    auto& ret = dp[i][j];
    if(ret != -1)
        return ret;
    if(n[i] == m[j])
        return ret = 1 + LCS(i + 1, j + 1);
    int choice1 = LCS(i + 1, j);
    int choice2 = LCS(i, j + 1);
    return ret = max(choice1, choice2);
}

void res(int i, int j) {
    if(i == sz(n) || j == sz(m))
        return;
    if(sz(ans) == dp[0][0]) return;
    if(n[i] == m[j])
        ans += n[i], res(i + 1, j + 1);
    (dp[i][j + 1] >= dp[i + 1][j] ? res(i, j + 1) : res(i + 1, j));
}

void Erz3() {
    cin >> n >> m;
    memset(dp, -1, sizeof dp);
    LCS(0, 0);
    res(0, 0);
    cout << ans;
}

signed main() {
    Wl3_ElNor
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t = 1;
//    cin >> t;
    while (t--)
        Erz3();

    return 0;
}