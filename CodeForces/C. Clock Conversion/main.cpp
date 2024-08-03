// problem link : https://codeforces.com/contest/1950/problem/C

// problem sol : https://codeforces.com/contest/1950/submission/273784335

//# Complexity
//- Time complexity:
//O (1)
//
//- Space complexity:
//O(1)

#include <iostream>
#include <string>
using namespace std;

int main() {
    int t = 1;
    cin >> t;
    while(t--) {
        int h , m;
        char c;
        cin >> h >> c >> m;
        string s = " AM\n";
        if(h >= 12)
        {
            h -= 12;
            s = " PM\n";
        }
        if(h == 0)
            h = 12;
        cout << (h < 10 ? "0" : "") << h << ":" << (m < 10 ? "0" : "") << m << s;
    }
    return 0;
}
