//      ﷽

//       وَأَنْ لَيْسَ لِلْإِنْسَانِ إِلَّا مَا سَعَى

///     However long the night ,the dawn will break.
///     ACPC Next Year, ISA

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
//const int N = 2e5+ 5;

void Erz3() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    for (int i = 'a' ; i <= 'z' ; i++) {
        for (int j = 0 ; j < n ; ++j) {
            if (s[j] == i && k > 0) {
                s[j] = -1;
                k--;
            }
        }
    }
    for (int i = 0 ; i < n ; ++i) {
        if (s[i] != -1)
            cout << s[i];
    }
}



// Another Solution 
void Erz3() {
    int freq[26] { };
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    for (int i = 0 ; i < n ; ++i) {
        freq[s[i] - 'a']++;
    }
    for (int i = 0 ; i < k ; ++i) {
        for (int j = 0 ; j < 26 ; ++j) {
            if (freq[j]) {
                freq[j]--;
                break;
            }
        }
    }
    string res;
    for (int i = n - 1 ; i >= 0 ; i--) {
        if (freq[s[i] - 'a']) {
            res += s[i];
            freq[s[i] - 'a']--;
        }
    }
    reverse(all(res));
    cout << res;
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
