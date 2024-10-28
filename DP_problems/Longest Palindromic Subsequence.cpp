//      ﷽

//       وَأَنْ لَيْسَ لِلْإِنْسَانِ إِلَّا مَا سَعَى

//  https://leetcode.com/problems/longest-palindromic-subsequence/description/


//#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

class Solution {
    int dp[1005][1005];
    string t;

    int LPS(int l, int r) {
        if(l > r) return 0;
        if(l == r) return 1;
        auto& ret = dp[l][r];
        if(~ret) return ret;
        ret = 0;
        if(t[l] == t[r]) return ret = 2 + LPS(l + 1, r - 1);
        int choice1 = LPS(l + 1, r);
        int choice2 = LPS(l, r - 1);
        return ret = max(choice1, choice2);
    }
public:
    int longestPalindromeSubseq(string s) {
        t = s;
        memset(dp, -1, sizeof dp);
        return LPS(0, (int)s.size() - 1);
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

    Time
    return 0;
}