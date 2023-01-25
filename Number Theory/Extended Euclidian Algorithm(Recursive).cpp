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

signed main(){
    int a, b;
    cin >> a >> b;
    if(gcd(a, b) == 1){
        triplet ans = extended(a, b);
        cout << "x : " << ans.x << '\n'  << "y : " << ans.y << '\n' << "gcd : " << ans.gcd << '\n';
    }else cout << "Solution Doesn't Exist !" << '\n';
    return 0;
}
