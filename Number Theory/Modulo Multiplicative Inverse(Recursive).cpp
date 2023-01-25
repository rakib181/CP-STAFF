#include <bits/stdc++.h>
using namespace std;
#define int long long int

struct triplet{
    int x, y, gcd;
};

int gcd(int a, int b){
    if(b == 0)return a;
    return gcd(b, a % b);
}

triplet extended(int a, int b){
    if(b == 0){
        triplet ans{};
        ans.x = 1;
        ans.gcd = a;
        ans.y = 0;
        return ans;
    }
    triplet small = extended(b, a % b);
    triplet ans{};
    ans.gcd = small.gcd;
    ans.x = small.y;
    ans.y = small.x - (a / b) * small.y;
    return ans;
}

int modular_multiplicative_inv(int a, int m){
    triplet ans = extended(a, m);
    return (ans.x + m) % m;
}

signed main(){
    int a, m;
    cin >> a >> m;
    if(gcd(a, m) == 1){
        int inv = modular_multiplicative_inv(a, m);
        cout << inv << '\n';
    }else cout << "Solution Doesn't Exist !" << '\n';
    return 0;
}
