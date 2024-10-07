//      ﷽

//       وَأَنْ لَيْسَ لِلْإِنْسَانِ إِلَّا مَا سَعَى

//  https://leetcode.com/problems/longest-increasing-subsequence/description/

//#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

// 48-57 -> 0-9  65-90 -> A-Z 97-122 -> a-z
#define Free_Palestine  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define i64             long long
#define int             long long
#define all(a)          a.begin(),a.end()
#define all_r(a)        a.rbegin(),a.rend()
#define vi              vector<int>
#define ef              else if
#define retv(x)         return void(cout << (x) << '\n')
#define sp              " "
#define SetPre(n, x)    cout << fixed << setprecision(n) << x << '\n'
#define Mod  1'000'000'007
#define INF 2'000'000'000
#define sz(s) (int)(s).size()

// DP pick or leave approach
class Solution {
    static const int N = 2500 + 5;
    int dp[N][N];
    int n;
    vector<int> arr;
    int LIS(int cur_idx, int Max_val_idx_sofar) {
        if(cur_idx >= n) return 0;
        auto& ret = dp[cur_idx][Max_val_idx_sofar];
        if(ret != -1) return ret;
        int leave = LIS(cur_idx + 1, Max_val_idx_sofar);
        int pick = 0;
        if(Max_val_idx_sofar >= n || arr[Max_val_idx_sofar] < arr[cur_idx])
            pick = LIS(cur_idx + 1, cur_idx) + 1;
        return ret = max(pick,leave);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        n = (int)nums.size();
        arr = nums;
        return LIS(0,n);
    }
};

// binary search ----------> beats 100%
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> lis;
        for(auto& num : nums) {
            auto it = lower_bound(lis.begin(),lis.end(),num);
            if(it == lis.end())
                lis.push_back(num);
            else
                *it = num;
        }
        return (int)lis.size();
    }
};

void solve() {

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