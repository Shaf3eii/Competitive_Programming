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

    vector<vector<char>> grid(rows, vector<char>(cols));
    vector<vector<pair<int, int>>> parent(rows + 2, vector<pair<int, int>>(cols + 2, {-1, -1}));
    char directions[] = {'R', 'L', 'D', 'U'}; // based on above dx and dy

    bool escaped = false;

    pair<int, int> startCell;
    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            cin >> grid[r][c];
            if (grid[r][c] == 'A') startCell = {r, c};
        }
    }

    auto checkBoundary = [&](int r, int c) {
        return ((r == 0 or r == rows - 1 or c == 0 or c == cols - 1)) ;
    };

    if (checkBoundary(startCell.first, startCell.second)) retv("YES\n0");  // Base Case if A is already on bounded cell

    auto isValidToMove = [&](int r, int c) {
        return (r >= 0 and r < rows and c >= 0 and c < cols and grid[r][c] == '.');
    };

    auto BFS = [&](int startRow, int startCol) {
        queue<tuple<int, int, char>> nodes;

        for (int r = 0; r < rows; ++r)
            for (int c = 0; c < cols; ++c)
                if (grid[r][c] == 'M')
                    nodes.push({r, c, 'M'});

        nodes.push({startRow, startCol, 'A'});

        while (!nodes.empty() and !escaped) {
            auto [currentRow, currentCol, charCell] = nodes.front();
            nodes.pop();
            if (charCell == 'M') {
                for (int d = 0; d < 4; d++) {
                    int newRowCell = dx[d] + currentRow;
                    int newColCell = dy[d] + currentCol;

                    if (isValidToMove(newRowCell,newColCell)) {
                        nodes.push({newRowCell, newColCell, 'M'});
                        grid[newRowCell][newColCell] = 'M';
                    }
                }
            }
            else {
                if (checkBoundary(currentRow, currentCol)) {
                    escaped = true;
                    string path;
                    pair<int, int> escapedCell = {currentRow, currentCol};

                    while (escapedCell != startCell) {
                        auto [prevRowCell, prevColCell] = parent[escapedCell.first][escapedCell.second];
                        for (int i = 0; i < 4; ++i) {
                            if (prevRowCell + dx[i] == escapedCell.first and prevColCell + dy[i] == escapedCell.second) {
                                path.push_back(directions[i]);
                                break;
                            }
                        }
                        escapedCell = {prevRowCell, prevColCell};
                    }
                    reverse(all(path));

                    cout << "YES\n"
                         << sz(path) << '\n'
                         << path << '\n';
                }

                for (int d = 0; d < 4; ++d) {
                    int newRowCell = dx[d] + currentRow;
                    int newColCell = dy[d] + currentCol;

                    if (isValidToMove(newRowCell, newColCell)) {
                        nodes.push({newRowCell, newColCell, 'A'});
                        grid[newRowCell][newColCell] = 'A';
                        parent[newRowCell][newColCell] = {currentRow, currentCol};
                    }
                }
            }
        }
    };
    BFS(startCell.first, startCell.second);

    if (!escaped) cout << "NO\n";
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