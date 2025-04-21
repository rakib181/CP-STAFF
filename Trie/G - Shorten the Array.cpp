#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

// @author  heisenberg

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

#define long long long
typedef tree<pair<long, long>, null_type, greater<>, rb_tree_tag, tree_order_statistics_node_update> o_set;
const int inf = 1e9 + 7;
const int mod = 1e9 + 7;


struct node{
    node *bit[2]{};
    int index{};
    node(){
        this -> bit[0] = nullptr;
        this -> bit[1] = nullptr;
        this -> index = -1;
    }
};
node *root;

void insert(int x, int index){
    node *t = root;
    for(int i = 29; i >= 0; i--){
        int b = (x >> i) & 1;
        if(t -> bit[b] == nullptr){
            t -> bit[b] = new node();
        }
        t -> bit[b] -> index = max(t -> bit[b] ->index, index);
        t = t -> bit[b];
    }
}

int get(int x, int k){
    node *t = root;
    int ans = -1;
    for(int i = 29; i >= 0; i--){
        int xth = (x >> i) & 1;
        int kth = (k >> i) & 1;
        if(kth){
            if(t -> bit[xth ^ 1] != nullptr){
                if(i == 0){
                    ans = max(ans, t -> bit[xth ^ 1] -> index);
                }
                t = t -> bit[xth ^ 1];
            }else{
                break;
            }
        }else{
           if(t -> bit[xth ^ 1] != nullptr){
               ans = max(ans, t -> bit[xth ^ 1] -> index);
           }
           if(t -> bit[xth] != nullptr){
               if(i == 0){
                   ans = max(ans, t -> bit[xth] -> index);
               }
               t = t -> bit[xth];
           }else{
               break;
           }
        }
    }
    return ans;
}



signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--){
      root = new node();
      int n, k;
      cin >> n >> k;
      int ans = inf;
      for(int i = 1; i <= n; i++){
          int x;
          cin >> x;
          insert(x, i);
          int j = get(x, k);
          if(j != -1){
              ans = min(ans, i - j + 1);
          }
      }
      if(ans == inf)ans = -1;
      cout << ans << '\n';
    }
    return 0;
}
