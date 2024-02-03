/* Today's Target (Y, AL, AM)
Academic Dynamic Programming Problem Sets*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1005;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
int n;
string a[N];
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

bool prime(int x){
    for(int i = 2; 1LL * i * i <= x; i++){
        if(x % i == 0)return false;
    }
    return true;
}

int get_rand(){
    while(true){
        int num = uniform_int_distribution<int> (1e9, 2e9)(rng);
        if(prime(num)){
            return num;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    int mod[16];
    for(int i = 1; i <= 15; i++){
        mod[i] = get_rand();
    }
    int b[n + 1]; ll answer = LLONG_MAX;
    for(int m = 1; m <= 15; m++){
        unordered_map<int, int, custom_hash> cnt;
        for(int i = 1; i <= n; i++){
            int num = 0;
            for(auto d : a[i]){
                num = 1LL * num * 10 % mod[m];
                num += (d - '0');
                num %= mod[m];
            }
            b[i] = num;
            cnt[num] += 1;
        }
        ll ans = 0;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(cnt.count(1LL * b[i] * b[j] % mod[m])) ans += cnt[1LL * b[i] * b[j] % mod[m]];
            }
        }
        answer = min(answer, ans);
    }
    cout << answer << '\n';
    return 0;
}
