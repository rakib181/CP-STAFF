#include <bits/stdc++.h>
using namespace std;
#define int long long int
const int N = 1010;
vector<int> f(N), a(N);

int find(int x){
    if(x != f[x]){
        f[x] = find(f[x]);
    }
    return f[x];
}

void _union(int u, int v){
    u = find(u), v = find(v);
    if(u != v){
        f[v] = u;
    }
}

struct {
    int x, y;
}s[N];


int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt, idx = 1;
    cin >> tt;
    while (tt--) {
        cout << "Case " << idx++ << ": ";
        int n, m, sum = 0;
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            sum += a[i];
            f[i] = i;
        }
        int avg = sum / n;
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            _union(u, v);
        }
        bool ok = true;
        if(sum % n != 0) ok = false;
        if(ok) {
            for(int i = 1; i <= n; i++){
                s[i].x = 0, s[i].y = 0;
            }
            for(int i = 1; i <= n; i++){
                s[find(i)].x += a[i], s[find(i)].y += 1;
            }
            for(int i = 1; i <= n; i++){
                if(!s[f[i]].x and !s[f[i]].y)continue;
                if((s[f[i]].x % s[f[i]].y != 0) or (s[f[i]].x / s[f[i]].y != avg)){
                    ok = false;
                    break;
                }
            }
        }
        if (ok)cout << "Yes" << '\n';
        else cout << "No" << '\n';
    }
    return 0;
}
