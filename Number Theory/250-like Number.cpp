#include<bits/stdc++.h>
using namespace  std;
#define int long long int
const int N = 2e6 + 9;
bool P[N]; vector<int> p;
void sieve(){
    memset(P, false, sizeof P);
    P[1] = true;
    for(int i = 4; i < N; i += 2) P[i] = true;
    for(int i = 3; i < N; i++){
        if(!P[i]) {
            for (int j = i * 2; j < N; j += i) {
               P[j] = true;
            }
        }
    }
    for(int i = 2; i < N; i++){
        if(!P[i])p.push_back(i);
    }
}
int f(int a, int b){
    double est;
    est = (b * b * b);
    est *= a;
    if(est > 4e18) return 4e18;
    return a * b * b * b;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    sieve();
    int n, res = 0;
    cin >> n;
    int sz = (int) p.size(), j = sz - 1;
    for(int i = 0; i < sz; i++){
        while (i < j and f(p[i], p[j]) > n) j -= 1;
        if(i >= j) break;
        res += (j - i);
    }
    cout << res << '\n';
    return 0;
}
