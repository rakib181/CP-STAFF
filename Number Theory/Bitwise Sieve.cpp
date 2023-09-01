#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e7 + 9;
int status[(N >> 5) + 1];
vector<int> prime;

bool check(int n, int pos){
    return ((n >> pos) & 1);
}
void mark(int &n, int pos){
    n |= (1 << pos);
}

void sieve(){
    for(int i = 3; i * i < N; i += 2){
        if(!check(status[(i >> 5)], (i & 31))){
           for(int j = i * i; j < N; j += i + i){
               mark(status[(j >> 5)], (j & 31));
           }
        }
    }
    prime.emplace_back(2);
    for(int i = 3; i < N; i += 2){
        if(!check(status[(i >> 5)], (i & 31))){
            prime.emplace_back(i);
        }
    }
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    sieve();
    int n;
    cin >> n;
    cout << prime[n - 1] << '\n';
    return 0;
}
