// problem link : https://codeforces.com/contest/1950/problem/B

// problem sol : https://codeforces.com/contest/1950/submission/273783438

//# Complexity
//- Time complexity:
//O (n)
//
//- Space complexity:
//O(1)

#include <iostream>

using namespace std;

int main() {
    int t = 1;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        n <<= 1;
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                cout << ((((r >> 1) + (c >> 1)) & 1) ? "." : "#");
            }
            cout << '\n';
        }
    }
    return 0;
}
