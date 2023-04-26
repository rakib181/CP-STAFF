#include<bits/stdc++.h>
using namespace std;
#define int long long int

struct item{
    int seg, pref, suf, sum;
};

struct segment{
    int sz;
    vector<item> a;
    void init(int n){
        sz = 1;
        while (sz < n)sz *= 2;
        a.assign(2 * sz, {0, 0, 0, 0});
    }
    item NEUTRAL = {0, 0, 0, 0};
    item merge(item x, item y){
        return {
           max({x.seg, y.seg, x.suf + y.pref}),
           max(x.pref, x.sum + y.pref),
           max(y.suf, y.sum + x.suf),
            x.sum + y.sum
        };
    }
    item single(int v){
        if(v > 0){
            return {v, v, v, v};
        }else{
            return {0, 0, 0, v};
        }
    }
    void build(vector<int> &aa, int x, int lx, int rx){
        if(rx - lx == 1){
            if(lx < (int) aa.size()){
                a[x] = single(aa[lx]);
            }
            return;
        }
        int m = (lx + rx) / 2;
        build(aa, 2 * x + 1, lx, m);
        build(aa, 2 * x + 2, m, rx);
        a[x] = merge(a[2 * x + 1] , a[2 * x + 2]);
    }
    void build(vector<int> &aa){
        build(aa, 0, 0, sz);
    }
    void set(int i, int v, int x, int lx, int rx){
        if(rx - lx == 1){
            a[x] = single(v);
            return;
        }
        int m = (lx + rx) / 2;
        if(i < m){
            set(i, v, 2 * x + 1, lx, m);
        }else{
            set(i, v, 2 * x + 2, m, rx);
        }
        a[x] = merge(a[2 * x + 1] , a[2 * x + 2]);
    }
    void set(int i, int v){
        set(i, v, 0, 0, sz);
    }
    item query(int l, int r, int x, int lx, int rx){
        if(lx >= r or l >= rx)return NEUTRAL;
        if(lx >= l and rx <= r)return a[x];
        int m = (lx + rx) / 2;
        return merge(query(l, r, 2 * x + 1, lx, m) , query(l, r, 2 * x + 2, m, rx));
    }
    item query(int l, int r){
        return query(l, r, 0, 0, sz);
    }
};

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    segment st;
    st.init(n);
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    st.build(a);
    cout << st.query(0, n).seg << '\n';
    while (m--){
       int i, v;
       cin >> i >> v;
       st.set(i, v);
       cout << st.query(0, n).seg << '\n';
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 9, inf = 1e9 + 7;
int a[N];
struct node {
	ll max_sub_sum, max_prefix, max_suffix, max_tot_sum;
};
node t[4 * N];

node merge(node x, node y) {
	if (x.max_sub_sum == inf)return y;
	if (y.max_sub_sum == inf)return x;
	node ans;
	ans.max_sub_sum = max(x.max_sub_sum, y.max_sub_sum);
	ans.max_sub_sum = max(ans.max_sub_sum, x.max_suffix + y.max_prefix);
	ans.max_prefix = max(x.max_prefix, x.max_tot_sum + y.max_prefix);
	ans.max_suffix = max(y.max_suffix, y.max_tot_sum + x.max_suffix);
	ans.max_tot_sum = x.max_tot_sum + y.max_tot_sum;
	return ans;
}

void build(int n, int b, int e) {
	if (b == e) {
		if (a[b] > 0)t[n] = {a[b], a[b], a[b], a[b]};
		else t[n] = {0, 0, 0, a[b]};
		return;
	}
	int m = (b + e) >> 1;
	build(2 * n, b, m);
	build(2 * n + 1, m + 1, e);
	t[n] = merge(t[2 * n], t[2 * n + 1]);
}

void upd(int n, int b, int e, int i, int v) {
	if (b > i or e < i)return;
	if (b == e) {
		if (v > 0)t[n] = {v, v, v, v};
		else t[n] = {0, 0, 0, v};
		return;
	}
	int m = (b + e) >> 1;
	upd(2 * n, b, m, i, v);
	upd(2 * n + 1, m + 1, e, i, v);
	t[n] = merge(t[2 * n], t[2 * n + 1]);
}

node query(int n, int b, int e, int l, int r) {
	if (b > r or e < l)return {inf, inf, inf, inf};
	if (b >= l and e <= r)return t[n];
	int m = (b + e) >> 1;
	return merge(query(2 * n, b, m, l, r), query(2 * n + 1, m + 1, e, l, r));
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	build(1, 1, n);
	cout << query(1, 1, n, 1, n).max_sub_sum << '\n';
	while (q--) {
		int i, v;
		cin >> i >> v;
		i += 1;
		upd(1, 1, n, i, v);
		cout << query(1, 1, n, 1, n).max_sub_sum << '\n';
	}
	return 0;
}
