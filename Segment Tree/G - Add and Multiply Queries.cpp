#include<bits/stdc++.h>
using namespace std;
#define long long long int

const int N = 1e5 + 9;
const long inf = 1e18;
vector<long> t(4 * N);

long merge(long x, long y){
    return x + y;
}

void upd(int node, int b, int e, int i, long v){
    if(b > i or e < i)return;
    if(b == e){
        t[node] = v;
        return;
    }
    int m = (b + e) >> 1;
    upd(2 * node, b, m, i, v);
    upd(2 * node + 1, m + 1, e, i, v);
    t[node] = merge(t[2 * node], t[2 * node + 1]);
}

long query(int node, int b, int e, int l, int r){
    if(b > r or e < l)return 0;
    if(b >= l and e <= r)return t[node];
    int m = (b + e) >> 1;
    return merge(query(2 * node, b, m, l, r), query(2 * node + 1, m + 1, e, l, r));
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        upd(1, 1, n, i, a[i]);
    }
    set<int> se;
    for(int i = 1; i <= n; i++){
        cin >> b[i];
        if(b[i] > 1)se.insert(i);
    }
    int q;
    cin >> q;
    while(q--){
        int type;
        cin >> type;
        if(type == 1){
            int i, x;
            cin >> i >> x;
            upd(1, 1, n, i, x);
        }else if(type == 2){
            int i, x;
            cin >> i >> x;
            if(x == 1){
                if(b[i] != 1){
                    se.erase(b[i]);
                }
            }else{
                if(b[i] != 1){
                    se.erase(b[i]);
                }
                se.insert(x);
                b[i] = x;
            }
        }else{
            int l, r;
            cin >> l >> r;
            long ans = 0;
            auto it = se.lower_bound(l);
            while(l <= r){
                if(it != se.end() and *it <= r) {
                    ans += query(1, 1, n, l, *it - 1);
                    ans = max(ans * b[*it], ans + query(1, 1, n, *it, *it));
                    if(ans >= inf){
                        ans = inf;
                        break;
                    }
                    l = *it + 1;
                    it++;
                }else{
                    ans += query(1, 1, n, l, r);
                    l = r + 1;
                }
            }
            cout << ans << '\n';
        }
    }
    return 0;
}
