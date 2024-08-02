//      ﷽

//       وَأَنْ لَيْسَ لِلْإِنْسَانِ إِلَّا مَا سَعَى

//   "From the river to the sea, Palestine is Free"

// Seek knowledge from the Cradle to the Grave.

// Never Give up -- Life is too short to make mistakes and learn from them -- Learn from other's mistakes

// Remember you were always a novice when you started so never be rude to some one

// Aim Big and strive hard to get it

// One has his own set of talents and anyone can do anything so never compare yourself to anybody

#include <bits/stdc++.h>

using namespace std;
#define Free_Palestine  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define i64 long long

int main() {
    Free_Palestine
#ifndef ONLINE_JUDGE
    freopen("cowsignal.in", "r", stdin);
    freopen("cowsignal.out", "w", stdout);
#endif
    int r, c , k;
    cin >> r >> c >> k;
    vector<vector<char>> grid(r, vector<char> (c));
    for(int i = 0 ; i < r ; ++i)
        for(int j = 0 ; j < c ; ++j)
            cin >> grid[i][j];
    for(int i = 0 ; i < r * k ; ++i)
    {
        for(int j = 0 ; j < c * k ; ++j)
            cout << grid[i / k][j / k];

        cout << '\n';
    }


    return 0;
}
