#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    static int arrayPairSum(vector<int>& nums) {
        int n = (int)nums.size();
        sort(nums.begin(),nums.end());
        int idx = 0;
        int sum = 0;
        while(idx < n)
        {
            sum += nums[idx];
            idx += 2;
        }
        return sum;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for(auto& i : nums)
        cin >> i;
    int sum = Solution::arrayPairSum(nums);
    cout << sum;
    return 0;
}
