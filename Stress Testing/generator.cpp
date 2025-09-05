#include <bits/stdc++.h>
using namespace std;
using ll = long long;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

inline ll gen_random(ll l, ll r) {
    return uniform_int_distribution<ll>(l, r)(rng);
}

//inline double gen_random(double l, double r) {
//    return uniform_real_distribution<double>(l, r)(rng);
//}

int main(int argc, char* argv[]){
    int w = gen_random(1, 100);
    cout<< w << endl;
    return 0;
}
