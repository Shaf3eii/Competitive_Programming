//      ﷽

// submission : https://codeforces.com/contest/719/submission/274105212

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
    int n;
    cin >> n;
    vector<int> moon(n);
    for(auto &i : moon)
        cin >> i;
    if(moon[n - 1] == 0)
    {
        cout << "UP";
        return;
    }
    if(moon[n - 1] == 15)
    {
        cout << "DOWN";
        return;
    }
    if(n == 1)
    {
        cout << -1;
        return;
    }
    if(moon[n - 2] == 0 && moon[n - 1] == 1)
    {
        cout << "UP";
        return;
    }
    if(moon[n - 2] < moon[n - 1])
    {
        if(moon[n - 1] == 15)
            cout << "DOWN";
        else
            cout << "UP";
    }
    else
        cout << "DOWN";
}

signed main() {
    Free_Palestine
    int t = 1;
//    cin >> t;
    while (t--)
        solve();

    return 0;
}
