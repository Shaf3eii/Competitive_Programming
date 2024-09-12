//      ﷽

//       وَأَنْ لَيْسَ لِلْإِنْسَانِ إِلَّا مَا سَعَى

//  https://atcoder.jp/contests/abc370/tasks/abc370_d

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


#ifdef DEBUG
#include "debug\debug.hpp"
#else
#define debug(...)
#define debug_itr(...)
#define debug_bits(...)
#define debug_pq(...)
#endif


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
    int r, c, q;
    cin >> r >> c >> q;
    vector<set<int>> rows(r+1) ,cols(c+1);
    int remaining_walls = r * c;
    for(int i = 1 ; i <= r ; ++i) {
        for(int j = 1 ; j <= c ; ++j) {
            rows[i].insert(j);
            cols[j].insert(i);
        }
    }
    auto destroy = [&](int x, int y) {
        if(rows[x].count(y)) {
            remaining_walls--;
            rows[x].erase(y);
            cols[y].erase(x);
        }
    };
    while (q--) {
        int x, y;
        cin >> x >> y;
        if (rows[x].count(y)) {
            destroy(x, y);
        } else {
            auto it = rows[x].lower_bound(y);
            if (it != rows[x].begin())
                destroy(x, *prev(it));

            if (it != rows[x].end())
                destroy(x, *it);

            it = cols[y].lower_bound(x);
            if (it != cols[y].begin())
                destroy(*prev(it), y);

            if (it != cols[y].end())
                destroy(*it, y);
        }
    }
    cout << remaining_walls;
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