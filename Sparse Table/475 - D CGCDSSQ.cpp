#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 9, K = 20;
int gc[K][N], lg[N];

int query(int l, int r){
    int k = lg[r - l];
    return __gcd(gc[k][l], gc[k][r - (1 << k)]);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    for(int i = 2; i < N; i++){
        lg[i] = lg[(i >> 1)] + 1;
    }
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        gc[0][i] = a[i];
    }
    for(int i = 1; i < K; i++){
        for(int j = 0; j + (1 << (i - 1)) <= n; j++){
            gc[i][j] = __gcd(gc[i - 1][j], gc[i - 1][j + (1 << (i - 1))]);
        }
    }
    map<int, ll> cnt;
    for(int L = 0; L < n; L++){
        int R = L;
        while(R < n){
            int g = query(L, R + 1);
            int l = R, r = n, sz = n;
            while(l <= r){
                int m = (l + r) >> 1;
                if(query(L, m + 1) < g){
                    sz = m;
                    r = m - 1;
                }else l = m + 1;
            }
            cnt[g] += (sz - R);
            R = sz;
        }
    }
    int q;
    cin >> q;
    while(q--){
        int x;
        cin >> x;
        cout << cnt[x] << '\n';
    }
    return 0;
}
