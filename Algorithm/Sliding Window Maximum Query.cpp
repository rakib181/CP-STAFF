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
      int n, k;
      cin >> n >> k;
      vector<int> ar(n), ans;
      deque<int> dq;
      for(int i = 0; i < n; i++){
        cin >> ar[i];
      }
      int i;
      for(i = 0; i < k; i++){
        while(!dq.empty() and ar[i] >= ar[dq.back()]){
            dq.pop_back();
        }
        dq.push_back(i);
      }
      while(i < n){
        ans.push_back(ar[dq.front()]);

        while(!dq.empty() and dq.front() <= i - k){
            dq.pop_front();
        }
        while(!dq.empty() and ar[i] >= ar[dq.back()]){
            dq.pop_back();
        }
        dq.push_back(i);
        i++;
      }
      ans.push_back(ar[dq.front()]);
      for(auto x : ans)cout << x << ' ';
      cerr<<1.0 * (clock()-start)/CLOCKS_PER_SEC<<endl;
      return 0;
}
