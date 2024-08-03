// problem link : https://codeforces.com/contest/1915/problem/C

// problem sol : https://codeforces.com/contest/1915/submission/273784776

//# Complexity
//- Time complexity:
//O (n)
//
//- Space complexity:
//O(1)


#include <bits/stdc++.h>
using namespace std;
#define i64  long long

int main() {
    int t = 1;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for(auto &i : arr)
            cin >> i;
        i64 sum = accumulate(arr.begin() , arr.end() , 0LL);
        i64 x = long((sqrt(sum)));
        cout << (sum == x * x ? "YES\n" : "NO\n");
    }
    return 0;
}
