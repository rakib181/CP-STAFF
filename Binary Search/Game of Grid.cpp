#include<bits/stdc++.h>
using namespace std;

bool good(vector<int> &ar, int n, long long limit, int m){
    long long cnt = 1, sum = 0;
    for(int i = 0; i < n; i++){
        if(sum + ar[i] > limit){
            cnt++;
            sum = 0;
        }else{
            sum += ar[i];
        }
    }
    return cnt >= m;
}

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
    vector<int> ar(n);
    for(int i = 0; i < n; i++)cin >> ar[i];

    long long l = 0, r = accumulate(ar.begin(), ar.end(), 0LL), ans = r;

    while(l <= r){
        long long mid = (l + r) >> 1;
        if(good(ar, n, mid, m)){
            ans = mid;
            l = mid + 1;
        }else r = mid - 1;
    }
   cout << ans << '\n';
      cerr<<1.0 * (clock()-start)/CLOCKS_PER_SEC<<endl;
      return 0;
}
