//      ﷽

//       وَأَنْ لَيْسَ لِلْإِنْسَانِ إِلَّا مَا سَعَى

//   "From the river to the sea, Palestine is Free"

// Seek knowledge from the Cradle to the Grave.

// Never Give up -- Life is too short to make mistakes and learn from them -- Learn from other's mistakes

// Remember you were always a novice when you started so never be rude to some one

// Aim Big and strive hard to get it

// One has his own set of talents and anyone can do anything so never compare yourself to anybody

//#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, less<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> ordered_set;

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

//const int dx[] = {0, 0, 1, -1};
//const int dy[] = {1, -1, 0, 0};
//const int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
//const int dy[] = {1, 1, 0, -1, -1, -1, 0, 1};
//const double pi = 3.14159265358979323846264338327950;
//const double EPS = -1e9;

template<typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
    for (const auto &i: v) os << i << ' ';
    return os;
}

template<typename T>
istream &operator>>(istream &is, vector<T> &v) {
    for (auto &i: v) is >> i;
    return is;
}

void solve() {
    int n, q;
    cin >> n >> q;
    vi arr(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> arr[i];
    vector<vector<int>> pre(n + 1, vector<int>(4)); // id -> 1 2 3
    for (int i = 1; i <= n; ++i) {
        pre[i] = pre[i - 1];
        pre[i][arr[i]]++;
    }
//    for(int i = 1 ; i <= n ; ++i) {
//        for(int j = 1 ; j <= 3 ; ++j)
//            cout << pre[i][j] << sp;
//        cout << '\n';
//    }
    while (q--) {
        int a, b;
        cin >> a >> b;
        for (int i = 1; i <= 3; ++i) {
            cout << pre[b][i] - pre[a - 1][i];
            if (i < 3)
                cout << sp;
        }
        cout << '\n';
    }
}

signed main() {
    Free_Palestine
#ifndef ONLINE_JUDGE
    freopen("bcount.in", "r", stdin);
    freopen("bcount.out", "w", stdout);
#endif
    int t = 1;
//    cin >> t;
    while (t--)
        solve();

    Time
    return 0;
}