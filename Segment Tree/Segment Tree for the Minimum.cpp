#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int a[N]; long long t[N * 4];
 
void build(int node, int s, int e) {
   if(s == e) {
    t[node] = a[s];
    return;
   }
  int mid = (s + e) >> 1;
  int l = node << 1, r = l | 1;
  build(l, s, mid);
  build(r, mid + 1, e);
  t[node] = min(t[l] , t[r]);
}
 
void upd(int node, int s, int e, int idx, int val){
  if(s > idx or e < idx)return;
  if(s == idx && e == idx) {
    t[node] = val;
    return;
  }
   int mid = (s + e) >> 1;
  int l = node << 1, r = l | 1;
   upd(l, s, mid, idx, val);
   upd(r, mid + 1, e, idx, val);
   t[node] = min(t[l] , t[r]);
}
 
long long query(int node, int s, int e, int l, int r) {
  if(s > r or e < l)return INT_MAX;
  if(s >= l and r >= e)return t[node];
  int mid = (s + e) >> 1;
  int i = node << 1, j = i | 1;
  return min(query(i, s, mid, l, r) , query(j, mid + 1, e , l , r));
}
 
int32_t main(){
   ios_base::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);
    #ifndef ONLINE_JUDGE 
    freopen("input.txt","r",stdin); 
    freopen("output.txt","w",stdout); 
    #endif
    auto start=clock();
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
      cin >> a[i];
    }
    build(1, 0, n - 1);
    while(m--){
      int x, i , j; 
      cin >> x >> i >> j;
      if(x == 1){
        upd(1, 0, n - 1, i, j);
      }else{
        cout << query(1, 0, n - 1, i, j - 1) << '\n';
      }
    } 
    cerr<<1.0 * (clock()-start)/CLOCKS_PER_SEC<<endl;
    return 0;
}
 
