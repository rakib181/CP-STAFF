#include<bits/stdc++.h>
using namespace std;

const int N = 1e8;
vector<int> lp(N + 1);
vector<int> pr;

int32_t main(){
   ios_base::sync_with_stdio(0);
    cin.tie(0); 
    #ifndef ONLINE_JUDGE 
    freopen("input.txt","r",stdin); 
    freopen("output.txt","w",stdout); 
    #endif
    auto start=clock();
    for(int i = 2; i <= N; i++){
      if(lp[i] == 0){
        lp[i] = i;
        pr.push_back(i);
      }
      for(int j = 0; j < pr.size() && pr[j] <= lp[i] && (i * pr[j] <= N); j++){
        lp[i * pr[j]] = pr[j];
      }
    }
    for(int i = 1, cnt = 0, n = 1; i <= N; i++){
      if(lp[i] == i){
       cnt++;
       if(cnt == n){
        n += 100;
        cout << i << '\n';
       }
      }
    }
    cerr<<1.0 * (clock()-start)/CLOCKS_PER_SEC<<endl;
    return 0;
}
