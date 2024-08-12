#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    static int largestSumAfterKNegations(vector<int>& nums, int k) {
        int pos = 0 , neg = 0;
        for(auto& i : nums)
        {
            if(i > 0)
                pos++;
            else if(i < 0)
                neg++;
        }
        sort(nums.begin(),nums.end());
        for(int i = 0 ; i < neg && k > 0; ++i , k--)
            nums[i] *=-1;
        sort(nums.begin(),nums.end());
        while(k--)
            nums[0] *= -1;
        long long sum = accumulate(nums.begin(),nums.end(),0LL);
        return sum;
    }
};

int main() {
    int n ,k ;
    cin >> n >> k;
    vector<int> nums(n);
    long long sum = Solution::largestSumAfterKNegations(nums,k);
    cout << sum;
    return 0;
}
