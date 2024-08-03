//      ﷽

// submission : https://codeforces.com/contest/583/submission/274094822

//       وَأَنْ لَيْسَ لِلْإِنْسَانِ إِلَّا مَا سَعَى

//   "From the river to the sea, Palestine is Free"

// Seek knowledge from the Cradle to the Grave.

// Never Give up -- Life is too short to make mistakes and learn from them -- Learn from other's mistakes

// Remember you were always a novice when you started so never be rude to some one

// Aim Big and strive hard to get it

// One has his own set of talents and anyone can do anything so never compare yourself to anybody

#include <bits/stdc++.h>

using namespace std;

// 48-57 -> 0-9  65-90 -> A-Z 97-122 -> a-z
#define Free_Palestine  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define i64             long long

void solve() {
    int n , h , v;
    cin >> n;
    bool first[55] = {false} , second[55] = {false};
    for(int i = 1 ; i <= n * n ; ++i)
    {
        cin >> h >> v;
        if(!first[h] && !second[v])
        {
            first[h] = second[v] = true;
            cout << i << ' ';
        }
    }
}

signed main() {
    Free_Palestine
    int t = 1;
//    cin >> t;
    while (t--)
        solve();

    return 0;
}
