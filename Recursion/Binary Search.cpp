#include <bits/stdc++.h>
using namespace std;

int binary(vector<int> &ar, int n, int l, int r, int x){
    int mid = (l + r) >> 1;
    if(ar[mid] == x){
        return mid;
    }
    if(r < 0 or l > n - 1)return -1;
    if(ar[mid] < x){
        return binary(ar, n, mid + 1, r, x);
    }else return binary(ar, n, l, mid - 1, x);
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, x;
    cin >> n >> x;
    vector<int> ar(n);
    for(int i = 0; i < n; i++){
        cin >> ar[i];
    }
    int idx = binary(ar, n, 0, n - 1, x);
    if(idx == -1)cout << "Nof Found !" << '\n';
    else cout << idx << '\n';
    return 0;
}
