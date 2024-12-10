//      ﷽

//       وَأَنْ لَيْسَ لِلْإِنْسَانِ إِلَّا مَا سَعَى

//       فَالجُهدُ يُثمِرُ إنْ تَضافَرَ صَفوُهُ، والعَزمُ يَرفعُ صَرحَ كُلِّ بُنيانِ.

///     However long the night ,the dawn will break.
///     ACPC Next Year, ISA

// problem link:   https://www.spoj.com/problems/NAKANJ/en/

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

const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};
//const int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
//const int dy[] = {1, 1, 0, -1, -1, -1, 0, 1};
//const int N = 2e5+ 5;

void Erz3() {
    int NoOfMoves;
    cin >> NoOfMoves;

    vector<pair<int, int>> possibleMoves_L = {{2, 1}, {2, -1}, {1, -2},{1, 2},
                                            {-1, 2}, {-1, -2},{-2,1}, {-2, -1}};
    vector<vector<bool>> vis(8, vector<bool> (8, false));

    auto isValidToMove = [&](int r, int c) {
        return (r >= 0 and r < 8 and c >= 0 and c < 8);
    };

    auto BFS = [&](string &from, string& to)-> int {
        if (from == to) return 0;

        int character1 = from[0] - 'a';
        int index1 = from[1] - '1';
        int character2 = to[0] - 'a';
        int index2 = to[1] - '1';

        queue<pair<int, int>> nodes;
        nodes.emplace(character1, index1);
        vis[character1][index1] = true;

        for (int level = 1, currentSize = (int)nodes.size(); !nodes.empty(); currentSize = (int)nodes.size(), ++level) {
            while (currentSize--) {
                auto [row, col] = nodes.front();
                nodes.pop();

                for (auto & d : possibleMoves_L) {
                    int newRow = d.first + row;
                    int newCol = d.second + col;

                    if (isValidToMove(newRow, newCol)) {
                        if (newRow == character2 and newCol == index2) {
                            return level;
                        }

                        nodes.emplace(newRow, newCol);
                        vis[newRow][newCol] = true;
                    }
                }
            }
        }
    };


    for (int i = 0; i < NoOfMoves; ++i) {
        string from, to;
        cin >> from >> to;
        cout << BFS(from, to) << '\n';

        { // initialize visited array with false values
            for (int r = 0; r < 8; r++)
                for (int c = 0; c < 8; c++)
                    vis[r][c] = false;
        }

    }
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