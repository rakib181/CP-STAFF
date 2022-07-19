#include<bits/stdc++.h>
using namespace std;

#define int long long int
 
vector<int> sumsub(vector<int> a){
   int n = a.size();
   vector<int> res; 
   for(int i = 0; i < (1 << n); i++){
      int sum = 0;
      for(int j = 0; j < n; j++){
         if((i >> j) & 1) sum += a[j];
      }
      res.push_back(sum);
   }
   return res;
}

int32_t main(){
     ios_base::sync_with_stdio(0);
     cin.tie(0); 
     #ifndef ONLINE_JUDGE 
     freopen("input.txt","r",stdin); 
     freopen("output.txt","w",stdout); 
     #endif
     auto start=clock();
     int n, a, b;
     cin >> n >> a >> b;

     vector<int> v(n);

     for(int i = 0; i < n ; i++){
      cin >> v[i];
     }

     vector<int> left, right;

     for(int i = 0; i < n; i++){
       if(i <= n / 2)left.push_back(v[i]);
       else right.push_back(v[i]);
     } 

     vector<int> sum_left = sumsub(left);
     vector<int> sum_right = sumsub(right);

     sort(sum_right.begin(), sum_right.end());

     int ans = 0;

     for(auto x : sum_left){
        ans += upper_bound(sum_right.begin(), sum_right.end(), (b - x)) -
        lower_bound(sum_right.begin(), sum_right.end(), (a - x));
     }

     cout << ans;

     cerr<<1.0 * (clock()-start)/CLOCKS_PER_SEC<<endl;
     return 0;
}
