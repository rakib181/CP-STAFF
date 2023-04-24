#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 9;
struct node {
	int ones, zeros;
};
node t[4 * N];
bool lazy[4 * N];
string a;

node merge(node x, node y) {
	node ans;
	ans.ones = ans.zeros = 0;
	ans.ones = (x.ones + y.ones);
	ans.zeros = (x.zeros + y.zeros);
	return ans;
}

void push(int n, int b, int e) {
	if (!lazy[n])return;
	swap(t[n].ones, t[n].zeros);
	if (b != e) {
		lazy[2 * n] ^= true;
		lazy[2 * n + 1] ^= true;
	}
	lazy[n] = false;
}

void build(int n, int b, int e) {
	lazy[n] = false;
	if (b == e) {
		t[n].ones = t[n].zeros = 0;
		if (a[b] == '1') {
			t[n].ones = 1;
		} else t[n].zeros = 1;
		return;
	}
	int m = (b + e) >> 1;
	build(2 * n, b, m);
	build(2 * n + 1, m + 1, e);
	t[n] = merge(t[2 * n], t[2 * n + 1]);
}

void upd(int n, int b, int e, int l, int r) {
	push(n, b, e);
	if (b > r or e < l)return;
	if (b >= l and e <= r) {
		lazy[n] = true;
		push(n, b, e);
		return;
	}
	int m = (b + e) >> 1;
	upd(2 * n, b, m, l, r);
	upd(2 * n + 1, m + 1, e, l, r);
	t[n] = merge(t[2 * n], t[2 * n + 1]);
}

node query(int n, int b, int e, int l, int r) {
	push(n, b, e);
	if (b > r or e < l)return {0, 0};
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
	int tt, cs = 1;
	cin >> tt;
	while (tt--) {
		cout << "Case " << cs++ << ":\n";
		cin >> a;
		int n = (int) a.size();
		build(1, 0, n - 1);
		int q;
		cin >> q;
		while (q--) {
			char type;
			cin >> type;
			if (type == 'I') {
				int l, r;
				cin >> l >> r;
				l -= 1;
				r -= 1;
				upd(1, 0, n - 1, l, r);
			} else {
				int i;
				cin >> i;
				i -= 1;
				node ans = query(1, 0, n - 1, i, i);
				if (ans.zeros == 1)cout << "0\n";
				else cout << "1\n";
			}
		}
	}
	return 0;
}
