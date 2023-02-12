#include <bits/stdc++.h>
using namespace std;
#define int long long int

struct segment{
    int sz{};
    vector<int> a;
    void init(int n){
        sz = 1;
        while (sz < n)sz *= 2;
        a.assign(2 * sz, INT_MAX);
    }
    void build(vector<int> &aa, int x, int lx, int rx){
        if(rx - lx == 1){
            if(lx < (int) aa.size()){
                a[x] = aa[lx];
            }
            return;
        }
        int m = (lx + rx) / 2;
        build(aa, 2 * x + 1, lx, m);
        build(aa, 2 * x + 2, m, rx);
        a[x] = min(a[2 * x + 1] , a[2 * x + 2]);
    }
    void build(vector<int> &aa){
        build(aa, 0, 0, sz);
    }
    int query(int l, int r, int x, int lx, int rx){
        if(lx >= r or l >= rx)return INT_MAX;
        if(lx >= l and rx <= r)return a[x];
        int m = (lx + rx) / 2;
        return min(query(l, r, 2 * x + 1, lx, m) , query(l, r, 2 * x + 2, m, rx));
    }
    int query(int l, int r){
        return query(l, r, 0, 0, sz);
    }
};

struct segment1{
    int sz{};
    vector<int> a;
    void init(int n){
        sz = 1;
        while (sz < n)sz *= 2;
        a.assign(2 * sz, INT_MIN);
    }
    void build(vector<int> &aa, int x, int lx, int rx){
        if(rx - lx == 1){
            if(lx < (int) aa.size()){
                a[x] = aa[lx];
            }
            return;
        }
        int m = (lx + rx) / 2;
        build(aa, 2 * x + 1, lx, m);
        build(aa, 2 * x + 2, m, rx);
        a[x] = max(a[2 * x + 1] , a[2 * x + 2]);
    }
    void build(vector<int> &aa){
        build(aa, 0, 0, sz);
    }
    int query(int l, int r, int x, int lx, int rx){
        if(lx >= r or l >= rx)return INT_MIN;
        if(lx >= l and rx <= r)return a[x];
        int m = (lx + rx) / 2;
        return max(query(l, r, 2 * x + 1, lx, m) , query(l, r, 2 * x + 2, m, rx));
    }
    int query(int l, int r){
        return query(l, r, 0, 0, sz);
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--){
         int n;
         cin >> n;
         segment st1;
         segment1 st2;
         st1.init(n);
         st2.init(n);
         vector<int> a(n);
         for(int i = 0; i < n; i++){
             cin >> a[i];
         }
         st1.build(a);
         st2.build(a);
         int l = 0, r = n - 1; pair<int, int> ans = {-1, -1};
        while (l <= r){
            int x = st1.query(l, r + 1);
            int y = st2.query(l, r + 1);
            if((a[l] == x and a[r] == y) or (a[l] == y and a[r] == y)){
                l++, r--;
            }else if(a[l] == x){
                l++;
            }else if(a[l] == y){
                l++;
            }else if(a[r] == x){
                r--;
            }else if(a[r] == y){
                r--;
            }else{
                ans.first = l, ans.second = r;
                break;
            }
        }
        if(ans.first == -1 and ans.second == -1){
            cout << "-1" << '\n';
        }else cout << ans.first + 1 << ' ' << ans.second + 1 << '\n';
    }
    return 0;
}
