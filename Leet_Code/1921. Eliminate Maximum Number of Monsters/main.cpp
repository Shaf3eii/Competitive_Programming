#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    static int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = (int)dist.size();
        int cnt = 0;
        vector<double> arrived(n);
        for(int i = 0 ; i < n ; ++i)
            arrived[i] = ((double)dist[i] / speed[i]);
        sort(arrived.begin(),arrived.end());
        for(int i = 0 ; i < n; ++i)
        {
            if(arrived[i] <= i)
                break;
            ++cnt;
        }
        return cnt;
    }
};


int main() {
    int n;
    cin >> n;
    vector<int> dis(n),time(n);
    for(auto& i : dis)
        cin >> i;
    for(auto& i : time)
        cin >> i;
    int ans = Solution::eliminateMaximum(dis,time);
    cout << ans;
    return 0;
}
