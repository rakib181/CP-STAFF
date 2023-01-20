#include<bits/stdc++.h>
using namespace std;
#define int long long int

const int N = 1e6 + 9;
vector<bool> P(N);
vector<int> CNT(N);

int bin(int a, int b){
    int ans = 1;
    while (b){
        if(b & 1) ans = ans * a;
        a = a * a;
        b >>= 1;
    }
    return ans;
}

bool afraid(int num){
   int tmp = num, dig = 0;
    while (num){
        if(num % 10 == 0){
            return false;
        }
        dig++;
        num /= 10;
    }
    int div = bin(10, dig - 1);
    num  = tmp;
    while (num){
        num %= div;
        div /= 10;
        if(num and P[num])return false;
    }
    return true;
}

void sieve(){
    P[0] = P[1] = true;
    for(int i = 2; i * i <= N; i++){
        if(!P[i]){
            for(int j = 2 * i; j <= N; j += i){
                P[j] = true;
            }
        }
    }

    for(int i = 2; i <= N; i++){
        CNT[i] = CNT[i - 1];
        if(!P[i]){
            if(afraid(i)){
                CNT[i]++;
            }
        }
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    sieve();
    int tt;
    cin >> tt;
    while (tt--){
        int n;
        cin >> n;
        cout << CNT[n] << '\n';
    }
    return 0;
}
