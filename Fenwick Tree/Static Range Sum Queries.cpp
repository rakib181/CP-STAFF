#include <bits/stdc++.h>
using namespace std;

struct fenwick{
    int n;
    long long *fen;
    void init(int n){
        this -> n = n;
        this -> fen = new long long[n + 10]{0};
    }
    void add(int x, int val){
        ++x;
        while(x <= n){
            fen[x] += val;
            x += x & (-x);
        }
    }
    long long query(int x){
        long long sum = 0; ++x;
        while(x){
            sum += fen[x];
            x -= x & (-x);
        }
        return sum;
    }
    long long query(int l, int r){
        l--, r--;
        return query(r) - query(l - 1);
    }
}BIT;

int32_t  main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    BIT.init(n);
    vector<int> ar(n + 10);
    for (int i = 0; i < n; ++i) {
       cin >> ar[i];
       BIT.add(i, ar[i]);
    }
    while(q--){
        int l, r;
        cin >> l >> r;
        cout << BIT.query(l, r) << '\n';
    }
    return 0;
}
