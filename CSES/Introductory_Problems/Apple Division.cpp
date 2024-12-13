//      ﷽

//       وَأَنْ لَيْسَ لِلْإِنْسَانِ إِلَّا مَا سَعَى

#include <bits/stdc++.h>

using namespace std;

// 48-57 -> 0-9  65-90 -> A-Z 97-122 -> a-z
#define Free_Palestine  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define i64             long long
#define all(a)   a.begin(),a.end()
#define all_r(a)   a.rbegin(),a.rend()
#define vi         vector<int>

//  وَلَسَوْفَ يُعْطِيكَ رَبُّكَ فَتَرْضَى

//const int dx[] = {0,0,1,-1};
//const int dy[] = {1,-1,0,0};
//const int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
//const int dy[] = {1, 1, 0, -1, -1, -1, 0, 1};
//const i64 mod = 1e9 + 7;


// recursive solution
int n;
vector<int> nums;

int getMinDifference(int curIdx, int curDif) {
    if (curIdx == n) return abs(curDif);

    int rightGroup = getMinDifference(curIdx + 1, nums[curIdx] + curDif);
    int leftGroup = getMinDifference(curIdx + 1, nums[curIdx] - curDif);

    return min(rightGroup, leftGroup);
}

void Erz3() {
    cin >> n;
    nums.resize(n);
    for (auto& i : nums) cin >> i;

    cout << getMinDifference(0, 0);
}


// bitmasks solution
void solve() {
    int n;
    cin >> n;
    vi apples(n);
    for(auto &i : apples)
        cin >> i;
    i64 Min_dif = INT_MAX;
    for(int mask = 0 ; mask < (1 << n) ; ++mask)
    {
        i64 cur = 0;
        for(int i = 0 ; i < n ; ++i)
        {
            if(mask & (1 << i))
                cur += apples[i];
            else
                cur -= apples[i];
        }
        if(cur < 0)
            continue;
        Min_dif = min(Min_dif,cur);
    }
    cout << Min_dif;
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

    return 0;
}
