#include<bits/stdc++.h>
using namespace std;

int32_t main(){
   ios_base::sync_with_stdio(0);
    cin.tie(0); 
    #ifndef ONLINE_JUDGE 
    freopen("input.txt","r",stdin); 
    freopen("output.txt","w",stdout); 
    #endif
    auto start=clock();
    int n, m;
    cin >> n >> m;
    vector<long long> v(n + 1), prefix(n + 2, 0), suffix(n + 2, 0);
    for(int i = 1; i <= n; i++)cin >> v[i];
    for(int i = 1; i <= n; i++){
      prefix[i] = prefix[i - 1];
      if(v[i] < v[i-1]){
        prefix[i] += (v[i - 1] - v[i]);
      }
    }
    for(int i = n - 1; i >= 1; i--){
      suffix[i] = suffix[i + 1];
      if(v[i] < v[i + 1]){
        suffix[i] += (v[i + 1] - v[i]);
      }
    }
    while(m--){
      int x, y; long long ans = 0;
      cin >> x >> y;
      if(x < y)ans = prefix[y] - prefix[x];
      else ans =  suffix[y] - suffix[x];
      cout << ans << '\n';
    }
    cerr<<1.0 * (clock()-start)/CLOCKS_PER_SEC <<endl;
    return 0;
}
