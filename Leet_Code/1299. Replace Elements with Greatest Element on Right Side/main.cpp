// problem link : https://leetcode.com/problems/replace-elements-with-greatest-element-on-right-side/

// problem sol : https://leetcode.com/problems/replace-elements-with-greatest-element-on-right-side/submissions/1340000553/

//# Intuition
//  iterate over the array from the back
//
//# Approach
//  catch the last element as the max_element and iterate from the last and keep track ur max
//
//# Complexity
//- Time complexity:
//O(n)
//
//- Space complexity:
//O(1)

#include <bits/stdc++.h>
using namespace std;

// # codev
class Solution {
public:
    static vector<int> replaceElements(vector<int>& arr) {
        int n = (int)arr.size();
        int max_next = arr[n - 1];
        arr[n - 1] = -1;
        for(int i = n - 2 ; i >= 0 ; --i)
        {
            if(arr[i] > max_next)
            {
                int cur = arr[i];
                arr[i] = max_next;
                max_next = cur;
            }
            else
                arr[i] = max_next;
        }
        return arr;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(auto &i : arr)
        cin >> i;
    arr = Solution::replaceElements(arr);
    for(int i = 0 ; i < n ; ++i)
        cout << arr[i] << " \n"[i == n - 1];
    return 0;
}
