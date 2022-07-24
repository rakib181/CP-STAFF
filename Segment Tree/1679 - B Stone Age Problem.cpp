#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 9;
int ar[N], n, q;
struct segment{
   long long *seg, *lazy;
   void init(int n){
       seg = new long long[4 * n];
       lazy = new long long[4 * n];
       memset(seg, 0, 4 * n);
       memset(lazy, 0, 4 * n);
   }

   void push(int node, int s, int e){
    if(lazy[node] == 0)return;
    seg[node] = lazy[node] * (e - s + 1);
    if(s != e){
       lazy[2 * node + 1] = lazy[node];
       lazy[2 * node + 2] = lazy[node];    
    }
    lazy[node] = 0;
   }
   void build(int node, int s, int e){
      if(s == e){
          seg[node] = ar[s];
          return;
      }
      int mid = (s + e) >> 1;
       build(2 * node + 1, s, mid);
       build(2 * node + 2, mid + 1, e);
       seg[node] = seg[2 * node + 1] + seg[2 * node + 2];
   }
   void update(int node, int s, int e, int i, int j, int x){
      push(node, s, e);
      if(s > j || e < i)return;
      if(s >= i && e <= j){
        lazy[node] = x;
        push(node, s, e);
        return;
      }
      int mid = (s + e) >> 1;
      update(2 * node + 1, s, mid, i, j, x);
      update(2 * node + 2, mid + 1, e, i, j, x);
      seg[node] = seg[2 * node + 1] + seg[2 * node + 2];
   }
   long long query(int node, int s, int e, int l, int r){
       if(s > r || e < l) return 0;
       if(s >= l && e <= r){
           return seg[node];
       }
      int mid =(s + e) >> 1;
      return query(2 * node + 1, s, mid, l, r) + query(2 * node + 2, mid + 1, e, l, r);
   }
} st;

int32_t main(){
     ios_base::sync_with_stdio(0);
      cin.tie(0); 
      #ifndef ONLINE_JUDGE 
      freopen("input.txt","r",stdin); 
      freopen("output.txt","w",stdout); 
      #endif
      auto start=clock();
       cin >> n >> q;
    st.init(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> ar[i];
    }
    st.build(1, 1, n);
    while(q--){
        int x;
        cin >> x;
        if(x == 1){
            int i, val;
            cin >> i >> val;
            st.update(1, 1, n, i, i, val);
        }else{
            int val;
            cin >> val;
            st.update(1, 1, n, 1, n, val);
        }
        cout << st.query(1, 1, n, 1, n) << '\n';
    }
      cerr<<1.0 * (clock()-start)/CLOCKS_PER_SEC<<endl;
      return 0;
}
