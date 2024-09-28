#include <bits/stdc++.h>

using namespace std;

// problem : https://leetcode.com/problems/course-schedule-ii/description/?envType=problem-list-v2&envId=topological-sort

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // int sz = (int)prerequisites.size();
        vector<int> indegree(numCourses,0);
        vector<vector<int>> adj(numCourses);
        vector<int> ordering;
        for(auto & pre : prerequisites) {
            adj[pre[1]].push_back(pre[0]);
            indegree[pre[0]]++;
        }
        queue<int> ready;
        for(int i = 0 ; i < (int)indegree.size() ; ++i)
            if(!indegree[i])
                ready.push(i);

        int vis = 0;
        while(!ready.empty()) {
            int course = ready.front();
            ready.pop();
            ++vis;
            ordering.push_back(course);
            for(auto& i : adj[course]) {
                indegree[i]--;
                if(!indegree[i])
                    ready.push(i);
            }
        }
        if(vis != numCourses)
            ordering.clear();
        return ordering;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
