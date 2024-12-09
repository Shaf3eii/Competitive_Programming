//      ﷽

//       وَأَنْ لَيْسَ لِلْإِنْسَانِ إِلَّا مَا سَعَى

//       فَالجُهدُ يُثمِرُ إنْ تَضافَرَ صَفوُهُ، والعَزمُ يَرفعُ صَرحَ كُلِّ بُنيانِ.

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

const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};
//const int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
//const int dy[] = {1, 1, 0, -1, -1, -1, 0, 1};
//const int N = 1e5+ 5;

void Erz3() {
    int rows, cols;
    cin >> rows >> cols;

    vector<vector<char>> grid(rows, vector<char> (cols));
    vector<vector<bool>> vis(rows + 2, vector<bool> (cols + 2, false));

    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            cin >> grid[r][c];
            if (grid[r][c] == '#')
                vis[r][c] = true;
        }
    }

    auto isValidToMove = [&](int r, int c) {
        return (r >= 0 and r < rows and c >= 0 and c < cols and !vis[r][c]);
    };

    auto BFS = [&](int r, int c) {
        queue<pair<int,int>> nodes;
        nodes.push({r, c});
        vis[r][c] = true;

        for (int sizeOfCurrentLevel = (int)nodes.size(); !nodes.empty(); sizeOfCurrentLevel = (int)nodes.size()) {
            while (sizeOfCurrentLevel--) {
                auto [currentRow, currentCol] = nodes.front();
                nodes.pop();

                for (int d = 0; d < 4; ++d) {
                    int newRowCell = dx[d] + currentRow; // dx is an array defined as a constant to describe the four directions
                    int newColCell = dy[d] + currentCol; // dy is an array defined as a constant to describe the four directions

                    if (isValidToMove(newRowCell, newColCell)) {
                        nodes.push({newRowCell, newColCell});
                        vis[newRowCell][newColCell] = true;
                    }
                }
            }
        }
    };

    int rooms = 0;

    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            if (isValidToMove(r, c)) {
                BFS(r, c);
                rooms++;
            }
        }
    }

    cout << rooms;
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