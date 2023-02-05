#include<bits/stdc++.h>
using namespace std;
#define  int long long int
const int N = 1e6 + 9;
vector <int> prime;
bool is_composite[N];

void sieve () {
    std::fill (is_composite, is_composite + N, false);
    for (int i = 2; i < N; ++i) {
        if (!is_composite[i]) prime.push_back (i);
        for (int j = 0; j < prime.size () && i * prime[j] < N; ++j) {
            is_composite[i * prime[j]] = true;
            if (i % prime[j] == 0) break;
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    sieve();
    int n;
    while (cin >> n and n){
        int tmp = n, cnt = 0;
        for(int i = 0; i * i <= tmp; i++){
            if(tmp % prime[i] == 0){
                cnt++;
                while (tmp % prime[i] == 0){
                    tmp /= prime[i];
                }
            }
        }
        if(tmp > 1) cnt++;
        cout << n << " : " << cnt << '\n';
    }
    return 0;
}

