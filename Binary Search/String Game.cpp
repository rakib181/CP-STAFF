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

#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N = 2e5 + 9;
string t, p; int n, k, a[N];

bool subsequence(string &S, string &P){
    int sz = (int) S.size(), i = 0;
    for(auto c : P){
        while (i < sz and S[i] != c){
            i += 1;
        }
        if(i >= sz)return false;
        i += 1;
    }
    return true;
}

bool good(int m){
    bool del[n];
    memset(del, false, sizeof del);
    for(int i = 1; i <= m; i++){
        del[a[i]] = true;
    }
    string s;
    for(int i = 0; i < n; i++){
       if(!del[i]){
           s += t[i];
       }
    }
    return subsequence(s, p);
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t >> p;
    n = (int) t.size(), k = (int) p.size();
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        a[i] -= 1;
    }
    int l = 0, r = n, ans = 0;
    while (l <= r){
        int m = (l + r) >> 1;
        if(good(m)){
            ans = m;
            l = m + 1;
        }else r = m - 1;
    }
    cout << ans << '\n';
    return 0;
}
