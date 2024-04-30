#include<bits/stdc++.h>
using namespace std;
using ll = long long;


ll ask(vector<ll> &a){
    cout << "? ";
    for(int i = 0; i < 100; i++){
        cout << a[i] << ' ';
    }
    cout << endl;
    ll x;
    cin >> x;
    return x;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<ll> a(100);
    iota(a.begin(), a.end(), 1);
    ll y = ask(a);
    ll x = 0;
    for(int i = 13; i >= 7; i--){
        if(y >> i & 1){
            x |= (1LL << i);
        }
    }
    for(int i = 0; i < 100; i++){
        a[i] <<= 7;
    }
    ll z = ask(a);
    for(int i = 6; i >= 0; i--){
        if(z >> i & 1){
            x |= (1LL << i);
        }
    }
    cout << "! " << x << endl;
    return 0;
}
