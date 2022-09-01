#include<bits/stdc++.h>
using namespace std;

void min_pair(vector<int> &a, vector<int> &b, int n, int m){
    sort(b.begin(), b.end());
    int diff = INT_MAX, p1 = 0, p2 = 0;
    for(auto x : a){
        auto lb = lower_bound(b.begin(), b.end(), x) - b.begin();

        if(lb >= 1 and x - b[lb - 1] <= diff){
            diff = x - b[lb - 1];
            p1 = x, p2 = b[lb - 1];
        }
        if(lb != m and b[lb] - x <= diff){
            diff = b[lb] - x;
            p1 = x, p2 = b[lb];
        }
    }
    cout << p1 << ' ' << p2 << '\n';
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
      vector<int> a(n), b(m);
      for(int i = 0; i < n; i++){
        cin >> a[i];
      }
      for(int i = 0; i < m; i++){
        cin >> b[i];
      }

      min_pair(a, b, n, m);
      cerr<<1.0 * (clock()-start)/CLOCKS_PER_SEC<<endl;
      return 0;
}
