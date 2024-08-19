#include<bits/stdc++.h>
using namespace std;
#define long long long int

const int inf = 1e9 + 7;

struct ST{
    int n;
    vector<int> t, a;
    explicit ST(int _n, vector<int> &ar){
        this -> n = _n;
        this -> t.assign(4 * n, inf);
        this -> a.assign(n,  0);
        for(int i = 0; i < n; i++){
            this -> a[i] = ar[i];
        }
    }

    void build(int node, int b, int e){
        if(b == e){
            t[node] = a[b];
            return;
        }
        int m = (b + e) >> 1;
        build(2 * node, b, m);
        build(2 * node + 1, m + 1, e);
        t[node] = min(t[2 * node], t[2 * node + 1]);
    }

    int query(int node, int b, int e, int l, int r){
        if(b > r or e < l)return inf;
        if(b >= l and e <= r)return t[node];
        int m = (b + e) >> 1;
        return min(query(2 * node, b, m, l, r), query(2 * node + 1, m + 1, e, l, r));
    }
};


void counting(vector<pair<pair<int, int>, int>> &a){
    int n = (int) a.size();
    vector<int> count(n, 0);
    vector<pair<pair<int, int>, int>> a_c(n);
    for(auto x : a){
        count[x.first.second]++;
    }
    for(int i = 1; i < n; i++)count[i] += count[i - 1];
    for(int i = n - 1; i >= 0; i--){
        a_c[--count[a[i].first.second]] = a[i];
    }
    count.assign(n, 0);
    a = a_c;
    for(auto x : a){
        count[x.first.first]++;
    }
    for(int i = 1; i < n; i++)count[i] += count[i - 1];
    for(int i = n - 1; i >= 0; i--){
        a_c[--count[a[i].first.first]] = a[i];
    }
    a = a_c;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t, cs = 1;
    cin >> t;
    while(t--) {
        cout << "Case " << cs++ << ": ";
        string x, y, z;
        cin >> x >> y >> z;
        string s = x + '$' + y + '%' + z + '$';
        int n = (int) s.size();
        vector<int> p(n), c(n);
        {
            vector<pair<char, int>> a(n);
            for (int i = 0; i < n; i++) {
                a[i] = make_pair(s[i], i);
            }
            sort(a.begin(), a.end());
            for (int i = 0; i < n; i++) {
                p[i] = a[i].second;
            }
            c[p[0]] = 0;
            for (int i = 1; i < n; i++) {
                if (a[i].first == a[i - 1].first) {
                    c[p[i]] = c[p[i - 1]];
                } else {
                    c[p[i]] = c[p[i - 1]] + 1;
                }
            }
        }
        int k = 0;
        while ((1 << k) < n) {
            vector<pair<pair<int, int>, int>> a(n);
            for (int i = 0; i < n; i++) {
                int j = (i + (1 << k)) % n;
                a[i] = make_pair(make_pair(c[i], c[j]), i);
            }
            counting(a);
            for (int i = 0; i < n; i++) {
                p[i] = a[i].second;
            }
            c[p[0]] = 0;
            for (int i = 1; i < n; i++) {
                if (a[i].first == a[i - 1].first) {
                    c[p[i]] = c[p[i - 1]];
                } else {
                    c[p[i]] = c[p[i - 1]] + 1;
                }
            }
            k += 1;
        }
        k = 0;
        vector<int> lcp(n, 0);
        for (int i = 0; i < n; i++) {
            if (c[i] == 0) {
                k = 0;
                continue;
            }
            int j = c[i] - 1;
            while (k < n and s[i + k] == s[p[j] + k]) {
                k += 1;
            }
            lcp[c[i]] = k;
            if (k > 0)k -= 1;
        }
        ST st(n, lcp);
        st.build(1, 1, n);
        vector<int> cnt(3, 0), type(n);
        for(int i = 0; i < n; i++){
            int now = p[i];
            int v;
            if(now > x.size() + y.size() + 1){
                v = 2;
            }else if(now > x.size()){
                v = 1;
            }else{
                v = 0;
            }
            type[now] = v;
        }
        int l = 0;
        int r = 0;

        int ans = 0;
        while(true){
            while(r < n && (cnt[0] == 0 or cnt[1] == 0 or cnt[2] == 0)){
                cnt[type[p[r++]]]++;
            }

            while(r < n and cnt[type[p[l]]] > 1){
                cnt[type[p[l++]]]--;
            }

            if(cnt[0] and cnt[1] and cnt[2]){
                ans = max(ans, st.query(1, 1, n, l + 1, r - 1));
            }

            cnt[type[p[l++]]]--;

            if(l >= n && r >= n) {
                break;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
