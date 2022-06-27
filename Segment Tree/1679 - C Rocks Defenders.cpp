#include<bits/stdc++.h>
using namespace std;
                                                                                                                        
class segment{
  public:
  int size;
  int  *v;

  void init(int n){
    size = n;
    v = new int[n * 4]{0};
  }

  void update(int node, int s, int e, int idx, int val) {
    if(s > idx || e < idx) return;
    if(s == idx && e == idx) {
      v[node] += val;
      return;
    }
     int mid = (s + e) >> 1;
    int i = node << 1, j = i | 1;
    update(i, s, mid, idx, val);
    update(j, mid + 1, e, idx, val);
     v[node] = v[i] + v[j];
  }

    int query(int node, int s, int e, int l, int r){
    if(s > r || e < l) return 0;
    if(s >= l && e <= r){
      return v[node];
    }

    int mid = (s + e) >> 1;
    int i = node << 1, j = i | 1;

    return query(i, s, mid, l, r) + query(j, mid + 1, e, l ,r);
  }

 }AX, AY;

int32_t main(){
   ios_base::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);
    #ifndef ONLINE_JUDGE 
    freopen("input.txt","r",stdin); 
    freopen("output.txt","w",stdout); 
    #endif
    auto start=clock();
    int n, q;
    cin >> n >> q;
    AX.init(n);
    AY.init(n);
    int X[n + 1] = {0}, Y[n + 1] = {0};
    while(q--){
      int p, x, y;;
      cin >> p >> x >> y;
      if(p == 1){
        ++X[x];
        ++Y[y];
        if(X[x] == 1)AX.update(1,1, n, x, 1);
        if(Y[y] == 1)AY.update(1, 1, n, y, 1);
      }else if(p == 2){
        --X[x];
        --Y[y];
        if(X[x] == 0)AX.update(1, 1, n, x, -1);
        if(Y[y] == 0)AY.update(1, 1, n, y, -1);
      }else {
        int x1, y1;
        cin >> x1 >> y1;
        int sum1 = AX.query(1, 1, n, x, x1);
        int sum2 = AY.query(1, 1, n, y, y1);
        if(sum1 == abs(x - x1) + 1 || sum2 == abs(y - y1) + 1){
          cout << "YES\n";
        }else{
          cout << "NO\n";
        }
      }
    }
    cerr<<1.0 * (clock()-start)/CLOCKS_PER_SEC<<endl;
    return 0;
}
