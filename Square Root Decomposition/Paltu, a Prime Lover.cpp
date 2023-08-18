#include <bits/stdc++.h>
using namespace std;
const int maxN = 1e8 + 1, inf = 1e9 + 7, N = 1e5 + 9;
bitset<maxN> pm ;
int block[1000001] ;

void sieve(){
    pm[0] = pm[1] = true;
    for(int i = 4; i < maxN; i += 2) pm[i] = true;
    for(int i = 3 ;i * i < maxN; i += 2){
        if(!pm[i]){
            for(int j = i * i ;j < maxN; j += i << 1)
                pm[j] = true;
        }
    }
    block[0] += 1;
    for(int i = 3 ;i < maxN ;i += 2){
        if(!pm[i])block[i / 100] += 1;
    }
    for(int i = 1 ;i <= 1000000; ++i)
        block[i] += block[i - 1];
}

pair<int, int> t[4 * N];

pair<int, int> unite(pair<int, int> x, pair<int, int> y){
    return make_pair(min(x.first, y.first), max(x.second, y.second));
}

void upd(int node, int b, int e, int i, int v){
    if(b > i or e < i)return;
    if(b == e){
        t[node] = {v, v};
        return;
    }
    int m = (b + e) >> 1;
    upd(2 * node, b, m, i, v);
    upd(2 * node + 1, m + 1, e, i, v);
    t[node] = unite(t[2 * node], t[2 * node + 1]);
}

pair<int, int> ask(int node, int b, int e, int l, int r){
    if(b > r or e < l)return {inf, 0};
    if(b >= l and e <= r)return t[node];
    int m = (b + e) >> 1;
    return unite(ask(2 * node, b, m, l, r), ask(2 * node + 1, m + 1, e, l, r));
}


int query(int l, int r){
    int L = l / 100, R = r / 100 ;
    int res = 0 ;
    if(L == R){

        for(int i = l ; i <= r ; ++i)
            res += !pm[i] ;
        return res ;
    }
    else {
        for(int i = l ; i < (L + 1) * 100 ; ++i){
            res += !pm[i] ;
        }
        res += block[R - 1] - block[L] ;
        for(int i = R * 100 ; i <= r ; ++i)
            res += !pm[i] ;
        return res ;
    }
}

void solve(){
    int n, q; cin >> n >> q;
    for(int i = 0; i < 4 * n; i++){
        t[i].first = inf;
        t[i].second = 0;
    }
    for(int i = 1; i <= n; ++i){
        int x ; cin >> x;
        upd(1, 1, n, i, x);
    }
    while(q--){
        int tp, x, y; cin >> tp >> x >> y;
        if(tp == 1){
            upd(1, 1, n, x, y);
        }else {
            pair<int, int> p = ask(1, 1, n, x, y);
            int res = query(p.first, p.second);
            cout << res << '\n';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    sieve();
    int test = 1;
    while (test--) {
        solve();
    }
    return 0;
}
