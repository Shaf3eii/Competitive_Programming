// problem link : https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/

// problem sol : https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/submissions/1340023863
// another sol : https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/submissions/1250223551

//# Intuition
//  get the lower bound of the target
//
//# Approach
//  binary search
//
//# Complexity
//- Time complexity:
//O (log(n))
//
//- Space complexity:
//O(1)

#include <bits/stdc++.h>
using namespace std;

// # code with builtin function
class Solution {
public:
    static vector<int> searchRange(vector<int>& nums, int target) {
        int first = lower_bound(nums.begin(),nums.end(),target) - nums.begin();
        int last = lower_bound(nums.begin(),nums.end(),target + 1) - nums.begin() - 1;
        if(first < (int)nums.size() && nums[first] == target)
            return {first,last};

        return {-1,-1};
    }
};

// code function implementation

//class Solution {
//public:
//    vector<int> searchRange(vector<int>& nums, int target) {
//        int start = 0 , end = int(nums.size()) - 1 , mid;
//        int fid = -1;
//        int lid = -1;
//        vector<int> indices(2,-1);
//        while(start <= end)
//        {
//            mid = (start + end) / 2;
//            if(nums[mid] < target)
//            {
//                start = mid + 1;
//            }
//            else
//            {
//                if(nums[mid] == target)
//                    fid = mid;
//                end = mid - 1;
//            }
//        }
//        start = 0 , end = int(nums.size()) - 1;
//        while(start <= end)
//        {
//            mid = (start + end) / 2;
//            if(nums[mid] <= target)
//            {
//                if(nums[mid] == target)
//                    lid = mid;
//                start = mid + 1;
//            }
//            else
//            {
//                end = mid - 1;
//            }
//        }
//        indices[0] = fid;
//        indices[1] = lid;
//        return indices;
//
//    }
//};

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(auto &i : arr)
        cin >> i;
    int target;
    cin >> target;
    vector<int> res = Solution::searchRange(arr , target);
    cout << res[0] << " " << res[1] << '\n';
    return 0;
}
