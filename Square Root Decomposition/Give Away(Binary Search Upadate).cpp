#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int MX = 5e5 + 9, NX = 710;
int a[MX]; vector<int> block[NX];
 
struct Square_Root_Decomposition{
    int n{}, d{}, b{};
    void init(int _n){
        this -> n = _n;
        this -> d = (int) sqrt(n);
        this -> b = (int) ceil((double) n / (double) d);
        for(int i = 0; i <= b; i++){
            sort(block[i].begin(), block[i].end());
        }
    }
    void update(int idx, int val) const{
        int blc = idx / d, old = a[idx];
        int l = 0, r = d - 1;
        while (l <= r){
            int m = (l + r) >> 1;
            if(block[blc][m] == old){
                block[blc][m] = val;
                break;
            }else if(block[blc][m] < old){
                l = m + 1;
            }else r = m - 1;
        }
        a[idx] = val;
        sort(block[blc].begin(), block[blc].end());
    }
    int query(int l, int r, int v) const{
        int lb = l / d, rb = r / d, ans = 0;
        if(lb == rb){
            for(int i = l; i <= r; i++){
                if(a[i] >= v) ans += 1;
            }
            return ans;
        }
        if(l % d != 0) lb += 1;
        int i;
        for(i = l; i < lb * d; i++){
            if(a[i] >= v) ans += 1;
        }
        while (i + d - 1 <= r){
            int blc = i / d;
            ans += block[blc].end() - lower_bound(block[blc].begin(), block[blc].end(), v);
            i += d;
        }
        while (i <= r){
            if(a[i] >= v) ans += 1;
            i++;
        }
        return ans;
    }
}sq;
 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n;
    int d = (int) sqrt(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        block[i / d].push_back(a[i]);
    }
    sq.init(n);
    cin >> m;
    while (m--){
      int type;
      cin >> type;
      if(!type){
          int l, r, v;
          cin >> l >> r >> v;
          l -= 1, r -= 1;
          cout << sq.query(l, r, v) << '\n';
      }else{
          int i, v;
          cin >> i >> v;
          i -= 1;
          sq.update(i, v);
      }
    }
    return 0;
} 
