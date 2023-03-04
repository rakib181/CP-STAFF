#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N = 1e5, MX = 2000, NX = 1e10;
vector<int> spf(N + 5);

void cal(){
    for(int i = 1; i <= N; i++)spf[i] = i;
    for(int i = 2; i <= N; i++){
        if(spf[i] == i){
            for(int j = i; j <= N; j += i){
                spf[j] = min(spf[j], i);
            }
        }
    }
}
vector<int> divs[MX];
void compute(){
    for(int i = 1; i * i <= NX; i++){
        int cur = i, node = 1;
        while (cur > 1){
            int p = spf[cur], cnt = 0;
            while (cur % p == 0){
                cnt += 1;
                cur /= p;
            }
            cnt *= 2;
            node *= (cnt + 1);
        }
        divs[node].push_back(i * i);
    }
}


signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cal();
    compute();
    int tt;
    cin >> tt;
    while (tt--){
        int k, l, r;
        cin >> k >> l >> r;
        int idx1 = lower_bound(divs[k].begin(), divs[k].end(), l) - divs[k].begin();
        int idx2 = upper_bound(divs[k].begin(), divs[k].end(), r) - divs[k].begin();
        idx2 -= 1;
        cout << max<long long>(0, idx2 - idx1 + 1) << '\n';
    }
    return 0;
}
