//      ﷽

//       وَأَنْ لَيْسَ لِلْإِنْسَانِ إِلَّا مَا سَعَى

//  https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/description/

#include <bits/stdc++.h>
using namespace std;


class Solution {
    int dp[5005][3];
    int n;
    vector<int> arr;
    int Profit(int i, int s) {
        if(i >= n) return 0;
        auto& ret = dp[i][s];
        if (~ret) return ret;
        int leave = Profit(i + 1, s);
        int pick = 0;
        if (s == 0)
            pick = Profit(i + 1, 1) - arr[i];
        else if (s == 1)
           pick = Profit(i + 1, 2) + arr[i];
        else
            pick = Profit(i + 1, 0);
        return ret = max(leave, pick);
}
public:
    int maxProfit(vector<int>& prices) {
        n = (int)prices.size();
        arr = prices;
        memset(dp, -1, sizeof dp);
        return Profit(0, 0);
    }
};



int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
