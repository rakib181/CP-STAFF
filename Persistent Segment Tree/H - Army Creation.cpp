#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

// @author  heisenberg

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

#define long long long
typedef tree<pair<long, long>, null_type, greater<>, rb_tree_tag, tree_order_statistics_node_update> o_set;
const int inf = 1e9 + 7;
const int mod = 1e9 + 7;

struct node{
    node *left, *right;
    long sum;
    explicit node(int x){
        this->left = nullptr;
        this->right = nullptr;
        this->sum = x;
    }
    explicit node(node *left, node *right){
        this->left = left;
        this->right = right;
        this->sum = 0;
        if(left){
            this->sum += left->sum;
        }
        if(right){
            this->sum += right->sum;
        }
    }
    node *build(int b, int e){
        if(b == e){
            return new node(0);
        }
        int m = (b + e) >> 1;
        return new node(build(b, m), build(m + 1, e));
    }
    node *upd(node *v, int b, int e, int pos, int x){
        if(b == e){
            return new node(x);
        }
        int m = (b + e) >> 1;
        if(pos <= m){
            return new node(upd(v->left, b, m, pos, x), v->right);
        }else{
            return new node(v->left, upd(v->right, m + 1, e, pos, x));
        }
    }
    int query(node *v, int b, int e, int l, int r){
        if(b > r or e < l)return 0;
        if(b >= l and e <= r){
            return v->sum;
        }
        int m = (b + e) >> 1;
        return query(v->left, b, m, l, r) + query(v->right, m + 1, e, l, r);
    }
};


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    gp_hash_table<int, vector<int>> p;
    vector<node *> roots(n + 2);
    roots[0] = roots[0]->build(1, n);
    for(int i = 1; i <= n; i++){
        auto &v = p[a[i]];
        v.emplace_back(i);
        roots[i] = roots[i - 1]->upd(roots[i - 1], 1, n, i, 1);
        if((int) v.size() > k){
            int j = v[(int) v.size() - k - 1];
            roots[i] = roots[i]->upd(roots[i], 1, n, j, 0);
        }
    }
    int q;
    cin >> q;
    int last = 0;
    while (q--){
        int l, r;
        cin >> l >> r;
        l = (l + last) % n + 1;
        r = (r + last) % n + 1;
        if(l > r)swap(l, r);
        last = roots[r]->query(roots[r], 1, n, l, r);
        cout << last << '\n';
    }
    return 0;
}
