#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N = 2e5 + 9;
int a[N];

int merge_sort(int l, int r){
    if(l < r){
        int m = (l + r) >> 1;
        int c1 = merge_sort(l, m);
        int c2 = merge_sort(m + 1, r);
        vector<int> t; int cnt = 0;
        int i = l, d = m, j = m + 1;
        while (i <= d and j <= r){
            if(a[i] < a[j]){
                t.push_back(a[i++]);
            }else {
                cnt += (m - i + 1);
                t.push_back(a[j++]);
            }
        }
        while (i <= d)t.push_back(a[i++]);
        while (j <= r)t.push_back(a[j++]);
        int k = 0;
        for(i = l; i <= r; i++){
            a[i] = t[k++];
        }
        return c1 + c2 + cnt;
    }
    return 0;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
       int n;
       cin >> n;
       for(int i = 0; i <= n; i++){
           a[i] = 0;
       }
       for(int i = 1; i <= n; i++){
           cin >> a[i];
       }
       cout << merge_sort(1, n) << '\n';
    }
    return 0;
}
