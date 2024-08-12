#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    static int largestPerimeter(vector<int>& nums) {
    int n = (int)nums.size();
    sort(nums.begin(),nums.end(),greater<>());
    for(int i = 0 ; i < n - 2 ; ++i)
    {
        if(nums[i + 2] + nums[i + 1] > nums[i])
            return nums[i]+nums[i + 1]+ nums[i + 2];
    }
    return 0;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for(auto& i : nums)
        cin >> i;
    int largest = Solution::largestPerimeter(nums);
    cout << largest;
    return 0;
}
