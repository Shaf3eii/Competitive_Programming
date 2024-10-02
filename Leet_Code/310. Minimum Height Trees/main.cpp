//      ﷽

//       وَأَنْ لَيْسَ لِلْإِنْسَانِ إِلَّا مَا سَعَى

//   https://leetcode.com/problems/minimum-height-trees/


#include <bits/stdc++.h>

using namespace std;


// observation : try to cut the graph from the leaves till reach the last one or two centered nodes

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1)
            return {0};
        vector<vector<int>> adj(n);
        for(auto & v : edges) {
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }

        vector<int> indegree(n);
        for(auto & v : adj)
            for(auto& u : v)
                indegree[u]++;

        queue<int> ready;
        for(int i = 0 ; i < n ; ++i)
            if(indegree[i] == 1)
                ready.push(i);

        while(n > 2) {
            int sz = (int)ready.size();
            n -= sz;
            while(sz--) {
                int node = ready.front();
                ready.pop();
                for(auto & neighbour : adj[node])
                    if(--indegree[neighbour] == 1)
                        ready.push(neighbour);
            }
        }
        vector<int> centerize;
        while(!ready.empty()) {
            centerize.push_back(ready.front());
            ready.pop();
        }

        return centerize;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
