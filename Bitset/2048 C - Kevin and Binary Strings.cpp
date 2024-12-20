#include<bits/stdc++.h>
using namespace std;

#define long long long

const int M = 5005;


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int n = (int) s.size(), k = 1;
        bitset<M> m(s), ans(0);
        for(int i = 0; i < n; i++){
            if(s[i] == '0'){
                k = n - i;
                break;
            }
        }
        int l = 0, r = 0;
        bitset<M> seg(0);
        for(int j = 0; j < k; j++){
            seg[k - j - 1] = (s[j] == '1' ? 1 : 0);
        }
        bitset<M> f = m ^ seg;
        if(f.to_string() > ans.to_string()){
            ans = f;
            l = 0, r = k - 1;
        }
        for(int j = k; j < n; j++){
            seg.reset(k - 1);
            seg = seg << 1;
            if(s[j] == '1'){
                seg.set(0);
            }else{
                seg.reset(0);
            }
            f = m ^ seg;
            if(f.to_string() > ans.to_string()){
                ans = f;
                l = j - k + 1, r = j;
            }
        }
        cout << 1 << ' ' << n << ' ' << l + 1 << ' ' << r + 1 << '\n';
    }
    return 0;
}
