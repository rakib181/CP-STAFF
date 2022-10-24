#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    --k;
    vector<int> ar(n), br(n);
    for(int i = 0; i < n; i++){
        cin >> ar[i];
    }
    for(int i = 0; i < n; i++){
        cin >> br[i];
    }
    sort(ar.begin(), ar.end());
    sort(br.begin(), br.end());

    auto possible = [&](int x){
        int cnt = 0, l = 0;
        while(l < n and ar[l] <= x)l++;
        --l;
        for(int r = 0; r < n; r++){
            while(l >= 0 and ar[l] + br[r] >= x)l--;
            cnt += l + 1;
        }
        return cnt <= k;
    };
    int l = 0, r = 1e12, ans = 0;
    while(l <= r){
        int mid = (l + r) >> 1;
        if(possible(mid)){
            ans = mid;
            l = mid + 1;
        }else r = mid - 1;
    }
    cout << ans << '\n';
    return 0;
}
