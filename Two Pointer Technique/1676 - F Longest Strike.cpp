#include<bits/stdc++.h>
using namespace std;
#define int long long int


signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while(tt--){
       int n, k;
       cin >> n >> k;
       vector<int> A(n), c; map<int, int> cnt;
       for(int i = 0; i < n; i++){
           cin >> A[i];
           cnt[A[i]] += 1;
       }
       for(auto x : cnt){
           if(x.second >= k){
               c.push_back(x.first);
           }
       }
       sort(c.begin(), c.end());
       if(c.empty()){
           cout << "-1" << '\n';
           continue;
       }
       int l = c[0], r = c[0], mx = -1, idx = 0;
       for(int i = 1; i < (int) c.size(); i++){
           int K = i;
           while (K < (int) c.size() and c[K] == c[K - 1] + 1){
               K += 1;
           }
           if(K - idx - 1 > mx){
               mx = K - idx - 1;
               l = c[idx], r = c[K - 1];
           }
           idx = K;
           i = K;
       }
       cout << l << ' ' << r << '\n';
    }
    return 0;
}
