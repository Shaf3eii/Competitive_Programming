#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    static int triangleNumber(vector<int>& nums) {
        int n = (int)nums.size();
        sort(nums.begin(),nums.end());
        int valid = 0;
        for(int i = 0 ; i < n - 2; ++i)
        {
            for(int j = i + 1 ; j < n - 1; ++j)
            {
                int st = j + 1 , nd = n - 1 , mid , cnt = 0;
                while(st <= nd && nd < n)
                {
                    mid = st + (nd - st) / 2;
                    if(nums[i] + nums[j]  > nums[mid])
                    {
                        st = mid + 1;
                    }
                    else
                        nd = mid - 1;
                }
//            cout << cnt << sp << j << '\n';
                valid += st - j - 1;
            }
        }
        return valid;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for(auto& i : nums)
        cin >> i;
    sort(nums.begin(),nums.end());
    cout << Solution::triangleNumber(nums);
    return 0;
}
