#include<bits/stdc++.h>
using namespace std;

#define long long long int
const int inf = 1e9 + 7;
struct item{
    int mx, lazy;
    item() : mx(0), lazy(0) {};
};
const int N = 2e5 + 9;
vector<item> t(4 * N);

void push(int node, int b, int e){
    if(t[node].lazy){
        t[node].mx = t[node].lazy;
        if(b != e){
            t[2 * node].lazy = t[node].lazy;
            t[2 * node + 1].lazy = t[node].lazy;
        }
    }
    t[node].lazy = 0;
}

item merge(item x, item y){
    item ans{};
    ans.mx = max(x.mx, y.mx);
    return ans;
}

void upd(int node, int b, int e, int l, int r, int v){
    push(node, b, e);
    if(b > r or e < l)return;
    if(b >= l and e <= r){
        t[node].lazy = v;
        push(node, b, e);
        return;
    }
    int m = (b + e) >> 1;
    upd(2 * node, b, m, l, r, v);
    upd(2 * node + 1, m + 1, e, l, r, v);
    t[node] = merge(t[2 * node], t[2 * node + 1]);
}

item query(int node, int b, int e, int l, int r){
    push(node, b, e);
    if(b > r or e < l)return {};
    if(b >= l and e <= r)return t[node];
    int m = (b + e) >> 1;
    return merge(query(2 * node, b, m, l, r), query(2 * node + 1, m + 1, e, l, r));
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while(tt--){
        int n;
        cin >> n;
        for(int i = 1; i <= 4 * n; i++){
            t[i] = {};
        }
        vector<int> a(n + 1);
        map<int, int> cnt;
        map<int, vector<int>> id;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }
        bool possible = true;
        for(int i = 1; i <= n; i++){
            int x;
            cin >> x;
            upd(1, 1, n, i, i, x);
            if(a[i] == x)continue;
            id[x].emplace_back(i);
            if(a[i] < x) possible = false;
        }
        int m;
        cin >> m;
        for(int i = 1; i <= m; i++){
            int x;
            cin >> x;
            cnt[x]++;
        }
        for(auto &[x, vec] : id){
            int l = vec[0], r = vec[0];
            for(int i = 0; i < (int) vec.size(); i++){
                if(query(1, 1, n, l, vec[i]).mx > x){
                   if(cnt[x] > 0) {
                       upd(1, 1, n, l, r, x);
                   }else {
                       possible = false;
                   }
                   cnt[x]--;
                   l = vec[i], r = vec[i];
                }else{
                    r = vec[i];
                }
            }
            if(query(1, 1, n, l, r).mx > x){
                possible = false;
            }else{
                if(cnt[x]){
                    upd(1, 1, n, l, r, x);
                    cnt[x]--;
                }else{
                    possible = false;
                }
            }
        }
        cout << (possible ? "YES\n" : "NO\n");
    }
    return 0;
}
