#include<bits/stdc++.h>
using namespace std;

int32_t main(){
   ios_base::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);
    #ifndef ONLINE_JUDGE 
    freopen("input.txt","r",stdin); 
    freopen("output.txt","w",stdout); 
    #endif
    auto start=clock();
    int n,m;
    cin>> n >> m;
   vector<int> a(n);
   vector<int> b(m);
    for(int i=0;i<n;i++){
      cin>> a[i];
    }
    for(int i=0;i<m;i++){
      cin>> b[i];
    }
    vector<long long> dp(m,0);
    int i=0,j;
    for(j=0;j<m;j++){
      while(i<n && a[i]<b[j])i++;
      if(j > 0 && b[j]==b[j-1]){
        dp[j]=dp[j-1];
      }else{
      while(i<n && a[i]==b[j]){
        i++;
        dp[j]++;
      }
    }
    }
    long long cnt=0;    
    for(int i=0;i<m;i++){
      cnt+=dp[i];
    }
    cout << cnt << '\n';
    cerr<<1.0 * (clock()-start)/CLOCKS_PER_SEC<<endl;
    return 0;
}
