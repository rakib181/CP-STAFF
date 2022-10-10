#include <bits/stdc++.h>
using  namespace std;

bool feasible(vector<int> &ar, string &s, string &p, int x){
    string new_s = s;
    for(int i = 0; i < x; i++){
        new_s[ar[i] - 1] = ' ';
    }
    int cnt = 0;
    for(int i = 0; i < (int) s.size(); i++){
        if(new_s[i] == p[cnt]){
            cnt++;
            if(cnt == (int) p.size())return true;
        }
    }
    return false;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s, p;
    cin >> s >> p;
    vector<int> ar((int) s.size());
    for(int i = 0; i < (int) s.size(); i++){
        cin >> ar[i];
    }
    int l = 0, r = (int) s.size(), ans = 0;
    while(l <= r){
        int mid = (l + r) >> 1;
        if(feasible(ar, s, p, mid)){
            ans = mid;
            l = mid + 1;
        }else r = mid - 1;
    }
    cout << ans << '\n';
    return 0;
}
