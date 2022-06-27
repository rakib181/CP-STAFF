#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int a[N]; 

struct item
{
  int m, cnt;
};

item t[N * 4];

item merge(item a, item b) {
  if(a.m < b.m)return a;
  if(a.m > b.m) return b;
  return {a.m , a.cnt + b.cnt};
}
 
void build(int node, int s, int e) {
   if(s == e) {
    t[node] = {a[s], 1};
    return;
   }
  int mid = (s + e) >> 1;
  int l = node << 1, r = l | 1;
  build(l, s, mid);
  build(r, mid + 1, e);
  t[node] = merge(t[l] , t[r]);
}
 
void upd(int node, int s, int e, int idx, int val){
  if(s > idx or e < idx)return;
  if(s == idx && e == idx) {
    t[node] = {val, 1};
    return;
  }
   int mid = (s + e) >> 1;
  int l = node << 1, r = l | 1;
   upd(l, s, mid, idx, val);
   upd(r, mid + 1, e, idx, val);
   t[node] = merge(t[l] , t[r]);
}
 
item query(int node, int s, int e, int l, int r) {
  if(s > r or e < l)return {INT_MAX, INT_MAX};
  if(s >= l and r >= e)return t[node];
  int mid = (s + e) >> 1;
  int i = node << 1, j = i | 1;
  item x = query(i, s, mid, l, r);
  item y = query(j, mid + 1, e , l , r);
  return merge(x, y);
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
      int x, i , j, cnt = 1; 
      cin >> x >> i >> j;
      if(x == 1){
        upd(1, 0, n - 1, i, j);
      }else{
        item res = query(1, 0, n - 1, i, j - 1);
        cout << res.m <<' ' << res.cnt << '\n';
      }
    } 
    cerr<<1.0 * (clock()-start)/CLOCKS_PER_SEC<<endl;
    return 0;
}
 
