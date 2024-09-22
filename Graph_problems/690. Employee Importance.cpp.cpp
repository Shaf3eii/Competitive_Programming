//      ﷽

//       وَأَنْ لَيْسَ لِلْإِنْسَانِ إِلَّا مَا سَعَى

// https://leetcode.com/problems/employee-importance/description/

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

template<typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
    for (const auto &i: v) os << i << ' ';
    return os;
}

template<typename T>
istream &operator>>(istream &is, vector<T> &v) {
    for (auto &i: v) is >> i;
    return is;
}

class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};

class Solution {
    unordered_map<int, bool> vis;
    int cost = 0;

    void dfs(vector<Employee *> &employees, int idx) {
        vis[employees[idx]->id] = true;
        cost += employees[idx]->importance;
        for (auto &i: employees[idx]->subordinates) {
            if (!vis[i])
                for (int j = 0; j < employees.size(); ++j) {
                    if (employees[j]->id == i) {
                        dfs(employees, j);
                    }
                }
        }
    }

public:
    int getImportance(vector<Employee *> employees, int id) {
        for (int i = 0; i < (int) employees.size(); ++i)
            if (id == employees[i]->id) {
                dfs(employees, i);
            }
        return cost;
    }
};


void solve() {
    int n, id;
    cin >> n >> id;
    vector<Employee *> employees(n);
    int x;
    for (int i = 0; i < n; ++i) {
        employees[i] = new Employee();
        cin >> employees[i]->id >> employees[i]->importance >> x;
        vi sub(x);
        cin >> sub;
        employees[i]->subordinates = sub;
    }

    // For Debugging
    for(int i = 0 ; i < n ; ++i) {
        cout << i << " : "<< sp << employees[i]->id << sp << employees[i]->importance << sp << employees[i]->subordinates << '\n';
    }

    Solution s;
    cout << s.getImportance(employees, id);

    for(int i = 0; i < n; ++i)
        delete employees[i];
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