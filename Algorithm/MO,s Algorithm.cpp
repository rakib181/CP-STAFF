#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int k, sum = 0, a[N + 10];

struct Q{
   int l, r, idx;
};
Q *query;
bool compare(Q q1, Q q2){
   if(q1.l / k == q2.l / k){
      return q1.r > q2.r;
   }
   return q1.l / k < q2.l / k;
}

int32_t main(){
    ios_base::sync_with_stdio(0);
     cin.tie(0); 
     #ifndef ONLINE_JUDGE 
     freopen("input.txt","r",stdin); 
     freopen("output.txt","w",stdout); 
     #endif
     auto start=clock();
     int n;
     cin >> n;
     for(int i = 0; i < n; i++){
      cin >> a[i];
     }
     int q;
     cin >> q;
     k = sqrt(n);
     query = new Q[q];
     for(int i = 0; i < q; i++){
      int l, r;
      cin >> l >> r;
      query[i].l = l;
      query[i].r = r;
      query[i].idx = i;
     }
     sort(query, query + q, compare);int L = 0, R = -1;
     vector<int> ans(q);
     for(int i = 0; i < q; i++){
      while(R < query[i].r)sum += a[++R];
      while(L > query[i].l)sum += a[--L];
      while(R > query[i].r)sum -= a[R--];
      while(L < query[i].l)sum -= a[L++];
      cout << sum << '\n';
      ans[query[i].idx] = sum;
     }
     for(int i =0; i < q; i++){
      cout << ans[i] << '\n';
     }
     cout << '\n';
     cerr<<1.0 * (clock()-start)/CLOCKS_PER_SEC<<endl;
     return 0;
}
