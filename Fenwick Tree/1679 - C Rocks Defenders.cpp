#include<bits/stdc++.h>
using namespace std;

class fenwick{
  public : 
  int size;
  vector<int> v;
  void init(int n){
    this -> size = n + 10;
    this -> v.resize(this -> size, 0);
  }
  void add(int x, int val){
    x++;
    while(x < size){
      v[x] += val;
      x += x & (-x);
    }
  }
  void upd(int x, int val){
    x++;
    while(x < size){
      v[x] += val;
      x += x & (-x);
    }
  }
  int query (int x){
    ++x;
    int ans = 0;
    while(x){
      ans += v[x];
      x -= x & (-x);
    }
    return ans;
  }

  int query(int l, int r){
    return query(r) - query(l - 1);
  }
} AX, AY;

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
    int ax[n + 1] = {0}, ay[n + 1] = {0};
    while(q--){
      int t, x, y;
      cin >> t >> x >> y;
      if(t == 1){
        ax[x]++;
        ay[y]++;
        if(ax[x] == 1) AX.add(x, 1);
        if(ay[y] == 1) AY.add(y, 1);
      }else if(t == 2){
        --ax[x];
        --ay[y];
        if(ax[x] == 0)AX.add(x, -1);
        if(ay[y] == 0)AY.add(y, -1);
      }else{
        int x1, y1;
        cin >> x1 >> y1;
        int sum1 = AX.query(x, x1), sum2 = AY.query(y, y1);
        if((sum1 == (abs(x - x1) + 1)) || (sum2 == (abs(y - y1) + 1))){
          cout << "YES\n";
        }else{
          cout << "NO\n";
        }
      }
    }
    cerr<<1.0 * (clock()-start)/CLOCKS_PER_SEC<<endl;
    return 0;
}
