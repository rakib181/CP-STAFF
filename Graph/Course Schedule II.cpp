#include<bits/stdc++.h>
using namespace std;

vector<int> findOrder(int numCourses, vector<vector<int>> prerequisites) {
     map<int, vector<int>> g; vector<int> deg(numCourses + 1, 0);
     for(int i = 0; i < prerequisites.size(); i++){
        g[prerequisites[i][1]].push_back(prerequisites[i][0]);
        deg[prerequisites[i][0]]++;
     }
     priority_queue<int, vector<int>, greater<>> q;
     for(int i = 0; i < numCourses; i++){
        if(!deg[i])q.push(i);
     }
     if(q.empty())return {};
     vector<int> ans;
     while(!q.empty()){
        int node = q.top();
        ans.push_back(node);
        q.pop();
        for(auto x : g[node]){
            if(--deg[x] == 0){
                q.push(x);
            }
        }
     }
     return ans;
}
