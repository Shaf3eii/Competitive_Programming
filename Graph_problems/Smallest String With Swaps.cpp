//      ﷽

//       وَأَنْ لَيْسَ لِلْإِنْسَانِ إِلَّا مَا سَعَى

// https://leetcode.com/problems/smallest-string-with-swaps/description/

#include <bits/stdc++.h>

using namespace std;

class Solution {
    vector<vector<int>> adj;
    string res;
    vector<int> ind;
    unordered_set<int> vis;
    void dfs(int x,string &s) {
        if(vis.count(x))
            return;
        vis.insert(x);
        ind.push_back(x);
        res += s[x];
        for(auto &i : adj[x]) {
            if(!vis.count(i))
                dfs(i,s);
        }
    }
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        adj.resize((int)pairs.size());
        for(auto&i : pairs) {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        for(int i = 0 ; i < (int)s.size() ; ++i) {
            if(!vis.count(i)) {
                ind.clear();
                res = "";
                dfs(i,s);
                sort(ind.begin(),ind.end());
                sort(res.begin(),res.end());
                for(int d = 0 ; d < (int)ind.size() ; ++d)
                    s[ind[d]] = res[d];
            }
        }
        return s;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
