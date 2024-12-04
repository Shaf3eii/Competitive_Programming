//      ﷽

//       وَأَنْ لَيْسَ لِلْإِنْسَانِ إِلَّا مَا سَعَى

///     However long the night ,the dawn will break.
///     ACPC Next Year, ISA

// problem link: https://codeforces.com/gym/102942/problem/E

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
#define debug(x)        cout << #x << ": " << (x) << "\n";
#define EPS             1e-9
#define PI              acos(-1)

//const int dx[] = {0, 0, 1, -1};
//const int dy[] = {1, -1, 0, 0};
//const int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
//const int dy[] = {1, 1, 0, -1, -1, -1, 0, 1};
const int N = 1e5+ 5;

int n;
string s;
int dp[N][10];

int compute(int idx, int digit) {
    if (idx == n) return 1;
    auto& ret = dp[idx][digit];
    if (~ret) return ret;
    ret = 0;
    if (s[idx] == '-') {
        for (int nextDigit = digit ; nextDigit <= 9 ; ++nextDigit) {
            ret = (ret % Mod + compute(idx + 1, nextDigit) % Mod) % Mod;
        }
    } else {
        int curDigit = s[idx] - '0';
        if (curDigit >= digit)
            ret = (ret % Mod + compute(idx + 1, curDigit) % Mod) % Mod;
    }
    return ret;
}

void Erz3() {
    cin >> n;
    cin >> s;
    memset(dp, -1, sizeof dp);
    cout << compute(0, 1) % Mod << '\n';
}

signed main() {
    Wl3_ElNor
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t = 1;
    cin >> t;
    while (t--)
        Erz3();

    return 0;
}
