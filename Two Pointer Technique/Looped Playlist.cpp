#include<bits/stdc++.h>
using namespace std;
#define int long long int

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, s, tot = 0;
    cin >> n >> s;
    vector<int> a((n << 1));
    for(int i = 0; i < n; i++){
        cin >> a[i];
        tot += a[i];
    }
    for(int i = n; i < (n << 1); i++){
        a[i] = a[i - n];
    }
    int remain = s % tot;
    int l = 0, r = 0, cnt = LONG_LONG_MAX, idx = -1, sum = 0;
    while (r < (n << 1)){
        sum += a[r];
        if(sum >= remain){
            if((r - l + 1) < cnt){
                cnt = r - l + 1;
                idx = (l % n);
            }
            while (sum >= remain){
                sum -= a[l++];
                if(sum >= remain and (r - l + 1) < cnt){
                    cnt = (r - l + 1);
                    idx = (l % n);
                }
            }
        }
        r++;
    }
    while (l < r and sum >= remain){
        sum -= a[l++];
        if(sum >= remain and (r - l + 1) < cnt){
            cnt = r - l + 1;
            idx = (l % n);
        }
    }
    cout << (idx + 1) << ' ' << cnt + n * (s / tot) << '\n';
    return 0;
}
