#include <bits/stdc++.h>

using namespace std;

// problem : https://leetcode.com/problems/course-schedule/description/

// first approach : using dfs
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> state(numCourses,0);
        vector<vector<int>> adj_list(numCourses);

        for(auto & pre : prerequisites)
            adj_list[pre[1]].push_back(pre[0]);

        function<bool(int)> dfs = [&](int node) -> bool{
            if(state[node] == 1) return false; // Cycle detected
            if(state[node] == 2) return true;  // Already fully visited, no cycle
            state[node] = 1; // Mark as visiting
            for(auto& neighbour : adj_list[node]) {
                if(!dfs(neighbour)) {
                    return false;
                }
            }
            state[node] = 2; // Mark as visited
            return true;
        };
        for(int i = 0 ; i < numCourses ; ++i) {
            if(!dfs(i))
                return false;
        }
        return true;
    }
};


// second approach -> Topological sort with dfs
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses,0);
        vector<vector<int>> adj_list(numCourses);
        vector<bool> vis(numCourses,false);

        for(int i = 0 ; i < prerequisites.size() ; ++i) {
            adj_list[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indegree[prerequisites[i][0]]++;
        }
        auto dfs = [&](auto& self,int node) ->void{
            vis[node] = true;
            for(auto& neighbour : adj_list[node]) {
                indegree[neighbour]--;
                if(indegree[neighbour] == 0 && !vis[neighbour])
                    self(self,neighbour);
            }
        };
        for(int i = 0 ; i < numCourses ; ++i)
            if(!indegree[i] && !vis[i])
                dfs(dfs,i);

        for(auto const& i : vis)
            if(!i)
                return false;

        return true;
    }
};


int main() {

    return 0;
}
