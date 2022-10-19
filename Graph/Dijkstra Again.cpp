#include<bits/stdc++.h>
using namespace std;

vector<int> shortestPath(vector<vector<int>> roads,int n)
{
     vector<pair<int, int>> g[n + 1];
     for(auto i : roads)
    {
        g[i[0]].push_back({i[1],i[2]});
        g[i[1]].push_back({i[0],i[2]});
    }
    vector<int> dist(n + 1, INT_MAX), path(n + 1);
    set<pair<int, int>> st;
    dist[1] = 0;
    path[1] = -1;
    st.insert({0, 1});
    while(!st.empty()){
        auto it = st.begin();
        int node = it -> second;
        int cur_dist = it -> first;
        st.erase(it);
        for(auto x : g[node]){
            if(x.second + cur_dist < dist[x.first]){

                if(st.find({dist[x.first], x.first}) != st.end()){
                    st.erase({dist[x.first], x.first});
                }

                dist[x.first] = x.second + cur_dist;
                path[x.first] = node;
                st.insert({dist[x.first], x.first});
            }
        }
    }
    vector<int> ans;
    int t = n;
    while(t != -1){
        ans.push_back(t);
        t = path[t];
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main(){

    int n = 5;
    vector<vector<int>> roads = {{1,2,2},{2, 5, 5},{2, 3, 4},{1, 4, 1},{4, 3, 3},{3, 5, 1}};
    vector<int> ans = shortestPath(roads, n);
    for(auto x : ans){
        cout << x << ' ';
    }
    return 0;
}
