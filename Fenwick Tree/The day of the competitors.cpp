#include <bits/stdc++.h>
using  namespace std;

const int N = 1e5 + 9, INF = INT_MAX;

struct player_rank{
    int x, y, z;
};

class compare{
public:
    bool operator()(const player_rank &a, const player_rank &b){
        return a.x < b.x;
    }
}cmp;

class BIT{
public:
    vector<int> tree;
    void init(int n){
        this -> tree.resize(N);
        fill(tree.begin(), tree.end(), INF);
    }

    void update(int idx, int val, int n){
        while (idx <= n){
           tree[idx] = min(tree[idx], val);
           idx += (idx & -idx);
        }
    }

    int read(int idx){
        int ans = INT_MAX;
        while(idx){
            ans = min(tree[idx], ans);
            idx -= (idx & -idx);
        }
        return ans;
    }
}bit;

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<player_rank> ar(n);
        for (int i = 0; i < n; i++) {
            cin >> ar[i].x >> ar[i].y >> ar[i].z;
        }
        sort(ar.begin(), ar.end(), cmp);
        bit.init(n + 2);
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            int cur = bit.read(ar[i].y);
            if (cur > ar[i].z) {
                cnt++;
            }
            bit.update(ar[i].y, ar[i].z, n);
        }
        cout << cnt << '\n';
    }
    return 0;
}
