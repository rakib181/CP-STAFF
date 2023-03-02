#include<bits/stdc++.h>
using namespace std;
#define int long long int

const int N = 1010000;
vector<int> cubes;

void cal(){
    for(int i = 1; i <= N; i++){
        cubes.push_back(i * i * i);
    }
}

int NC(int x){
   int l = 0, r = (int) cubes.size(), ans = 0;
    while (l <= r){
        int m = (l + r) / 2;
        if(cubes[m] > x){
            ans = m;
            r = m - 1;
        }else l = m + 1;
    }
    return ans;
}

int count(int t, int x){
    return t - NC(x);
}

int F(int t, int n){
    return count(t, n);
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cal();
    int tt;
    cin >> tt;
    while (tt--){
        int n;
        cin >> n;
        int l = 1, r = 2e9, ans = 1;
        while (l <= r){
            int m = (l + r) / 2;
            if(F(m, m * m) >= n){
                ans = m * m;
                r = m - 1;
            }else l = m + 1;
        }
        cout << ans << '\n';
    }
    return 0;
}
