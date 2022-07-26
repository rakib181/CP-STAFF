#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 9;
vector<int> ar(N);

class segment{
public:
    int n;
    long long *seg;
    void init(int n){
        this -> n = n;
        this -> seg = new long long [4 * n];
    }
    void build(int node, int s, int e){
        if(s == e){
            seg[node] = 0;
            return;
        }
        int mid = (s + e) >> 1;
        build(2 * node, s, mid);
        build(2 * node + 1, mid + 1, e);
        seg[node] = seg[2 * node] + seg[2 * node + 1];
    }
    void upd(int node, int s, int e, int idx, int val){
        if(s > idx || e < idx)return;
        if(s == idx && e == idx){
            seg[node] += val;
            return;
        }
        int mid = (s + e) >> 1;
        upd(2 * node, s, mid, idx, val);
        upd(2 * node + 1, mid + 1, e, idx, val);
        seg[node] = seg[2 * node] + seg[2 * node + 1];
    }

    long long query(int node, int s, int e, int l, int r){
        if(s > r || e < l)return 0;
        if(s >= l && e <= r){
            return seg[node];
        }
        int mid = (s + e) >> 1;
        return query(2 * node, s, mid, l, r) + query(2 * node + 1, mid + 1, e, l, r);
    }
}st;

int32_t main(){
    int n, idx = 1;
    cin >> n;
    st.init(n);
    st.build(1, 1, n);
    string s, rev;
    cin >> s;
    rev = s;
    reverse(rev.begin(), rev.end());
    queue<int> q[26];
    for(int i = 0; i < n; i++){
        q[rev[i] - 'a'].push(idx++);
    }
    for(int i = 0; i < n; i++){
        ar[i] = q[s[i] - 'a'].front();
        q[s[i] - 'a'].pop();
    }
    long long ans = 0;
    for(int i = 0; i < n; i++){
        st.upd(1, 1, n, ar[i], 1);
        ans += st.query(1, 1, n, ar[i] + 1, n);
    }
    cout << ans << '\n';
    return 0;
}

