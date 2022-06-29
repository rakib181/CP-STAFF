#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
int a[N], n, q;

class segment{
  public :
  int size;
  int  *v;
  void init(int n){
    size = n;
    v = new int[size * 4];
  }

  void build(int node, int s, int e, int lvl) {
    if(s == e) {
      v[node] = a[s];
      return;
    }

    int mid = (s + e) >> 1;
    int l = node << 1, r = l | 1;

    build(l, s, mid, lvl + 1);
    build(r, mid + 1, e, lvl + 1);

    v[node] = (!((n - lvl) & 1)) ? (v[l] | v[r]) : (v[l] ^ v[r]);
  }

  void update(int node, int s, int e, int idx, int val, int lvl) {
    if(s > idx or e < idx)return;
    if(s == idx && e == idx){
      v[node] = val;
      return;
    }
    int mid = (s + e) >> 1;
     int l = node << 1, r = l | 1;

    update(l, s, mid, idx, val, lvl + 1);
    update(r, mid + 1, e, idx, val, lvl + 1);

     v[node] = (!((n - lvl) & 1)) ? (v[l] | v[r]) : (v[l] ^ v[r]);
  }
};

int32_t main(){
   ios_base::sync_with_stdio(0);
    cin.tie(0); 
    #ifndef ONLINE_JUDGE 
    freopen("input.txt","r",stdin); 
    freopen("output.txt","w",stdout); 
    #endif
    auto start=clock();
    segment tree;
      cin >> n >> q;
      tree.init((1 << n));
     for(int i = 1; i <= (1 << n); i++){
      cin >> a[i];
     }
      tree.build(1, 1, (1 << n), 1);
      while(q--) {
        int i, v;
        cin >> i >> v;
        tree.update(1, 1, (1 << n), i, v, 1);
        cout << tree.v[1]  << '\n';
      }
    cerr<<1.0 * (clock()-start)/CLOCKS_PER_SEC<<endl;
    return 0;
}
