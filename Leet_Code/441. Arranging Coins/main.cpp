#include <iostream>
using namespace std;

class Solution {
    static long long can(long long n) {
        return 1LL * n * (n + 1) / 2;
    }
public:
     static long long arrangeCoins(int n) {
        long long st = 0 , nd = INT_MAX , mid , ans = 0;
        while(st <= nd)
        {
            mid = st + (nd - st) / 2;
            if(can(mid) <= n)
            {
                ans = mid;
                st = mid + 1;
            }
            else
                nd = mid - 1;
        }
        return ans;
    }
};

int main() {
    int n;
    cin >> n;
    cout << Solution::arrangeCoins(n);
    return 0;
}
