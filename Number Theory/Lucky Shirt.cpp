#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 9;
int phi[N];

void cal(){
    for(int i = 1; i < N; i++)phi[i] = i;
    for(int i = 1; i < N; i++){
        for(int j = i + i; j < N; j += i){
            phi[j] -= phi[i];
        }
    }
}
vector<int> s[N];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cal();
    for(int i = 1; i < N; i++){
        s[phi[i]].emplace_back(i);
    }
    int n, q;
    cin >> n >> q;
    while(q--){
        int l, r, x;
        cin >> l >> r >> x;
        int idx1 = (int) (lower_bound(s[x].begin(), s[x].end(), l) - s[x].begin());
        int idx2 = (int) (upper_bound(s[x].begin(), s[x].end(), r) - s[x].begin());
        cout << idx2 - idx1 << '\n';
    }
    return 0;
}
