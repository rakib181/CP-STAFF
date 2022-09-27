#include<bits/stdc++.h>
using namespace std;

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, x;
    cin >> n >> x;
    vector<int> ar(n);
    for(int i = 0; i < n; i++){
        cin >> ar[i];
    }
    sort(ar.begin(), ar.end());
    int l = 0, r = n, ans = -1;
    while (l <= r){
        int mid1 = l + (r - l) / 3;
        int mid2 = r - (r - l) / 3;
        if(ar[mid1] == x){
           ans = mid1 + 1;
           break;
        }
        if(ar[mid2] == x){
            ans = mid2 + 1;
            break;
        }
        if(ar[mid1] > x){
            r = mid1 - 1;
        }else if(ar[mid2] > x){
            l = mid1 + 1;
            r = mid2 - 1;
        }else{
            l = mid2 + 1;
        }
    }
    if(ans != -1)cout << ans << '\n';
    else cout << "Doesn't Exist" << '\n';
    return 0;
}
