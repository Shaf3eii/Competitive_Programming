//      ﷽

// submission : https://codeforces.com/gym/101498/submission/274181534

//       وَأَنْ لَيْسَ لِلْإِنْسَانِ إِلَّا مَا سَعَى

//   "From the river to the sea, Palestine is Free"

// Seek knowledge from the Cradle to the Grave.

// Never Give up -- Life is too short to make mistakes and learn from them -- Learn from other's mistakes

// Remember you were always a novice when you started so never be rude to some one

// Aim Big and strive hard to get it

// One has his own set of talents and anyone can do anything so never compare yourself to anybody

#include <bits/stdc++.h>

using namespace std;
// 48-57 -> 0-9  65-90 -> A-Z 97-122 -> a-z
#define Free_Palestine  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define i64             long long

void solve() {
    int n, k;
    cin >> n >> k;
    vector<i64> arr(n), next_element(n, INT_MAX);
    for (auto &i: arr)
        cin >> i;
    map<i64, i64> last_occur;
    for (int i = n - 1; i >= 0; --i) {
        if (last_occur[arr[i]])
            next_element[i] = last_occur[arr[i]];

        last_occur[arr[i]] = i;
    }
    auto comp = [&](int i, int j) {
        return next_element[i] < next_element[j];
    };
    i64 opens = 0;
    set<i64> out;
    priority_queue<i64, vector<i64>, decltype(comp)> pq(comp);
    for(int i = 0 ; i < n ; ++i)
    {
        if(out.count(arr[i]))
        {
            pq.push(i);
            continue;
        }
        opens++;
        if(out.size() == k)
        {
            i64 idx = pq.top();
            pq.pop();
            out.erase(arr[idx]);
        }
        pq.push(i);
        out.insert(arr[i]);
    }
    cout << opens << '\n';
}

signed main() {
    Free_Palestine
    int t = 1;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
