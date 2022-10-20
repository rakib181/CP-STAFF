#include<bits/stdc++.h>
using namespace std;

int tsp(vector<vector<int>> &dist, int setOfCity, int city, int n){
    if(setOfCity == (1 << n) - 1){
        return dist[city][0];
    }
    int ans = INT_MAX;
    for(int choice = 0; choice < n; choice++){
        if(!(setOfCity & (1 << choice))){
            int sub = dist[city][choice] + tsp(dist, (setOfCity | (1 << choice)), choice, n);
            ans = min(ans, sub);
        }
    }
    return ans;
}


int  main(){
    vector<vector<int>> dist = {
            {0, 20, 42, 25}, {20, 0, 30, 34},
            {42, 30, 0, 10}, {25, 34, 10, 0}
    };
    cout << tsp(dist, 1, 0, 4) << '\n';
    return 0;
}
