//      ﷽

//       وَأَنْ لَيْسَ لِلْإِنْسَانِ إِلَّا مَا سَعَى

// https://leetcode.com/problems/open-the-lock/description/

//#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

// 48-57 -> 0-9  65-90 -> A-Z 97-122 -> a-z
#define Free_Palestine  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define i64             long long
#define all(a)          a.begin(),a.end()
#define all_r(a)        a.rbegin(),a.rend()
#define vi              vector<int>
#define ef              else if
#define retv(x)         return void(cout << (x) << '\n')
#define sp              " "
#define SetPre(n, x)    cout << fixed << setprecision(n) << x << '\n'
#define Mod  1'000'000'007
#define INF 2'000'000'000
#define Time cerr << "Time Taken: " << (float)clock() / CLOCKS_PER_SEC << " Secs" << "\n";
#define sz(s) (int)(s).size()

class Solution {
public:
    static int openLock(vector<string>& deadends, string target) {
        unordered_map<string,bool> vis;
        for(auto & s : deadends)
            vis[s] = true;
        if(vis["0000"]) return -1;
        auto get_next_char = [&](char c) -> char{
            if(c == '9')
                return '0';
            return char(int(c) + 1);
        };
        auto get_prev_char = [&](char c) -> char{
            if(c == '0')
                return '9';
            return char(int(c) - 1);
        };
        queue<string> q;
        q.push("0000");
        vis["0000"] = true;
        for(int level = 0 , sz = 1 ; !q.empty() ; ++level , sz = (int)q.size()) {
            while(sz--) {
                string node = q.front();
                q.pop();
                if(node == target)
                    return level;
                for(int i = 0 ; i < 4 ; ++i) {
                    string s = node;
                    string p = node;
                    s[i] = char(get_next_char(s[i]));
                    p[i] = char(get_prev_char(p[i]));
                    if(s == target || p == target)
                        return ++level;
                    if(!vis[s])
                        q.push(s) , vis[s] = true;
                    if(!vis[p])
                        q.push(p) , vis[p] = true;
                }
            }
        }
        return -1;
    }
};

void solve() {
    int n;
    cin >> n;
    vector<string> dead(n);
    for(auto &s : dead)
        cin >> s;
    string target;
    cin >> target;
    cout << Solution::openLock(dead,target) << '\n';
}

signed main() {
    Free_Palestine
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t = 1;
//    cin >> t;
    while (t--)
        solve();

    Time
    return 0;
}