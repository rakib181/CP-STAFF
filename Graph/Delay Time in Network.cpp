#include<bits/stdc++.h>
using namespace std;

int networkDelayTime(vector<vector<int>> times, int n, int k)
{
     vector<pair<int, int>> g[n + 1];
     for(auto i : times)
    {
        g[i[0]].push_back({i[1],i[2]});
    }
    vector<int> dist(n + 1, INT_MAX);
    set<pair<int, int>> st;
    dist[k] = 0;
    st.insert({0, k});
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
                st.insert({dist[x.first], x.first});
            }
        }
    }
    int ans = INT_MIN;
    for(int  i = 1; i <= n; i++){
        if(ans < dist[i]){
            ans = dist[i];
        }
    }
    if(ans != INT_MAX)return ans;
    else return -1;
}

int main(){

    int n = 4, k = 2;
    vector<vector<int>> times = {{2,1,1},{2,3,1},{3,4,1}};
    int ans =  networkDelayTime(times, n, k);
    cout << ans << '\n';
    return 0;
}
