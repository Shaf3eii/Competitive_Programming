//      ﷽

//       وَأَنْ لَيْسَ لِلْإِنْسَانِ إِلَّا مَا سَعَى

//   "From the river to the sea, Palestine is Free"

// Never Give up -- Life is too short to make mistakes and learn from them -- Learn from other's mistakes

// Remember you were always a novice when you started so never be rude to some one

// Aim Big and strive hard to get it

// One has his own set of talents and anyone can do anything so never compare yourself to anybody

#include <bits/stdc++.h>

using namespace std;

// 48-57 -> 0-9  65-90 -> A-Z 97-122 -> a-z
#define Free_Palestine  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);


//  وَلَسَوْفَ يُعْطِيكَ رَبُّكَ فَتَرْضَى

//const int dx[] = {0,0,1,-1};
//const int dy[] = {1,-1,0,0};
//const int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
//const int dy[] = {1, 1, 0, -1, -1, -1, 0, 1};


void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(auto& i : arr)cin >> i;
    long long increases = 0;
    for(int i = 1 ; i < n ; i++)
    {
        if(arr[i - 1] > arr[i])
        {
            int dif = arr[i - 1] - arr[i];
            increases += dif;
            arr[i] += dif;
        }
    }
    cout << increases;
}

signed main() {
    Free_Palestine
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t = 1;
    //cin >> t;
    while (t--)
        solve();

    return 0;
}