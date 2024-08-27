#include<bits/stdc++.h>
using namespace std;

#define long long long

const int N = 1e5 + 9;
vector<int> spf(N);

void cal(){
    for(int i = 1; i < N; i++)spf[i] = i;
    for(int i = 2; i < N; i++){
        for(int j = i; j < N; j += i){
            spf[j] = min(spf[j], i);
        }
    }
}

int f(int n){
    int cnt = 0;
    while(n > 1){
        int p = spf[n];
        while(n % p == 0){
            cnt++;
            n /= p;
        }
    }
    return cnt;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cal();
    int n;
    cin >> n;
    int ans = 0;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        ans ^= f(x);
    }
    cout << (ans ? "Anna\n" : "Bruno\n");
    return 0;
}
