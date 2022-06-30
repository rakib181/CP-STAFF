#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
pair<int, int> a[N];

class segment{
public:
  int size;
  int *v;
  void init(int n) {
     size = n;
     v = new int[size * 4];
     fill(v + 1, v + (size * 4) + 1, 0);
  }
  void update(int node, int s, int e, int idx, int val) {
    if(s > idx || e < idx) return;
    if(s == idx && e == idx) {
      v[node] = val;
      return;
    }
    int mid = (s + e) >> 1;
    int l = node << 1, r = l | 1;
    update(l, s, mid, idx, val);
    update(r, mid + 1, e, idx, val);
    v[node] = v[l] + v[r];
  }

  int query(int node, int s, int e, int i, int j) {
    if(s > j or e < i) return 0;
    if(s >= i && e <= j){
      return v[node];
    }
    int mid = (s + e) >> 1;
    int l = node << 1, r = l | 1;
    return query(l, s, mid, i, j) + query(r, mid + 1, e, i, j);
  }
};

int32_t main(){
   ios_base::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);
    #ifndef ONLINE_JUDGE 
    freopen("input.txt","r",stdin); 
    freopen("output.txt","w",stdout); 
    #endif
    auto start=clock();
    segment tree;
    int tt;
    cin >> tt;
    while(tt--){
    int n;
    cin >> n;
    tree.init(n);
    for(int i = 0; i < n; i++){
      cin >> a[i].first;
      a[i].second = i;
    }
    sort(a , a + n); long long cnt = 0;
    for(int i = 0; i < n ; i++){
      tree.update(1, 0, n - 1, a[i].second, 1);
      cnt += tree.query(1, 0, n - 1, a[i].second + 1, n - 1);
    } 
    cout << cnt << '\n';
  }
   cerr<<1.0 * (clock()-start)/CLOCKS_PER_SEC<<endl;
    return 0;
}
