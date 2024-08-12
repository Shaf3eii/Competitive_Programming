#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    static vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int min_abs = INT_MAX;
        int n = (int)arr.size();
        sort(arr.begin(),arr.end());
        for(int i = 0 ; i < n - 1 ; ++i)
            min_abs = min(arr[i + 1] - arr[i],min_abs);
        vector<vector<int>> ans;
        for(int i = 0 ; i < n - 1 ; ++i)
        {
            if(arr[i + 1] - arr[i] == min_abs)
                ans.push_back({arr[i],arr[i + 1]});
        }
        return ans;
    }
};


int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for(auto& i : arr)
        cin >> i;
    vector<vector<int>> ans;
    ans = Solution::minimumAbsDifference(arr);
    for(const auto& i : ans)
    {
        for(auto j : i) {
            cout << j << " ";
        }
        cout << '\n';
    }

    return 0;
}
