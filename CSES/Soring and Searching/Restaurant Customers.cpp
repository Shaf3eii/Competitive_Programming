//      ﷽

//       وَأَنْ لَيْسَ لِلْإِنْسَانِ إِلَّا مَا سَعَى

///     However long the night ,the dawn will break.
///     ACPC Next Year, ISA

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
//const int N = 1e3 + 5;

struct coordinate_compression {
private:
    vector<int> comp;
    void compress() {
        sort(comp.begin(), comp.end());
        comp.erase(unique(comp.begin(), comp.end()), comp.end());
    }
public:
    coordinate_compression(vector<int> & v) {
        comp = v;
        compress();
    }
    int get_index(int val) {
        return lower_bound(comp.begin(), comp.end(), val) - comp.begin();
    }
    int get_origin(int idx) {
        return comp[idx];
    }
};


void Erz3() {
    int n;
    cin >> n;
    vi times;
    for(int i = 0 ; i < n ; ++i) {
        int x, y;
        cin >> x >> y;
        times.push_back(x);
        times.push_back(y);
    }
    coordinate_compression compressed(times);
    vi partial(n * 2 + 1, 0);
    for(int i = 0 ; i < n * 2 ; ++i) {
        if(i & 1)
            partial[compressed.get_index(times[i]) + 1]--;
        else
            partial[compressed.get_index(times[i])]++;
//        cout << compressed.get_index(times[i]) << sp << compressed.get_origin(times[i]) << '\n';
    }

    for(int i = 1 ; i < n * 2 ; ++i)
        partial[i] += partial[i - 1];

//    for(int i = 0 ; i < n * 2 ; ++i)
//        cout << partial[i] << " \n"[i == n * 2 - 1];

    int Max = -INF;
    for(int i = 0 ; i < n * 2 ; ++i)
        Max = max(Max, partial[i]);
    cout << Max;
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