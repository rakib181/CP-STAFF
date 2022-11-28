#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;
vector<int> cnt(N, 0);
int dc = 0;

void ADD(int x){
    cnt[x]++;
    if(cnt[x] == 1){
       dc++;
    }
}

void REMOVE(int x){
    cnt[x]--;
    if(!cnt[x]){
        dc--;
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--){
        int n;
        cin >> n;
        vector<int> ar(n + 1);
        for(int i = 1; i <= n; i++){
            cin >> ar[i];
            ADD(ar[i]);
        }
        int cur_ans = 0, L = n;
        for(int l = n; l >= 1; l--){
            if(n - l - dc >= cur_ans){
                cur_ans = n - l - dc;
                L = l;
            }
            REMOVE(ar[l]);
        }
        cout << L << ' ' << n << '\n';
    }
    return 0;
}
