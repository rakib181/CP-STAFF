#include<bits/stdc++.h>
using namespace std;

float perfact_squire(int n, int p){
    int l = 1, r = n / 2; float ans = 0;
    while(l <= r){
        int mid = (l + r) / 2;
        if(mid * mid == n)return mid;
        if(mid * mid < n){
            ans = mid;
            l = mid + 1;
        }else r = mid - 1;
    }

    float inc = 0.1;
    for(int i = 1; i <= p; i++){
        while(ans * ans <= n){
            ans += inc;
        }

        ans -= inc;
        inc /= 10;
    }
    return ans;
}

int32_t main(){
     ios_base::sync_with_stdio(0);
      cin.tie(0); 
      #ifndef ONLINE_JUDGE 
      freopen("input.txt","r",stdin); 
      freopen("output.txt","w",stdout); 
      #endif
      auto start=clock();
      int n, p;
      cin >> n >> p;
      float x = perfact_squire(n, p);
      cout << x << '\n';   
      cerr<<1.0 * (clock()-start)/CLOCKS_PER_SEC<<endl;
      return 0;
}
