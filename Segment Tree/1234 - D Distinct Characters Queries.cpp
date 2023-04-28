#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 9;
string a;
struct node {
	int cnt[26], c;
};
node t[4 * N];

node merge(node x, node y) {
	node ans;
	ans.c = 0;
	for (int i = 0; i < 26; i++) {
		ans.cnt[i] = x.cnt[i] + y.cnt[i];
		if (ans.cnt[i] > 0)ans.c += 1;
	}
	return ans;
}

void build(int n, int b, int e) {
	if (b == e) {
		memset(t[n].cnt, 0, sizeof t[n].cnt);
		t[n].cnt[a[b] - 'a'] = 1;
		t[n].c = 1;
		return;
	}
	int m = (b + e) >> 1;
	build(2 * n, b, m);
	build(2 * n + 1, m + 1, e);
	t[n] = merge(t[2 * n], t[2 * n + 1]);
}

void upd(int n, int b, int e, int i, char c) {
	if (b > i or e < i)return;
	if (b == e) {
		memset(t[n].cnt, 0, sizeof t[n].cnt);
		t[n].cnt[c - 'a'] = 1;
		t[n].c = 1;
		return;
	}
	int m = (b + e) >> 1;
	upd(2 * n, b, m, i, c);
	upd(2 * n + 1, m + 1, e, i, c);
	t[n] = merge(t[2 * n], t[2 * n + 1]);
}

node query(int n, int b, int e, int l, int r) {
	if (b > r or e < l) {
		node ans;
		memset(ans.cnt, 0, sizeof ans.cnt);
		ans.c = 0;
		return ans;
	}
	if (b >= l and e <= r) {
		return t[n];
	}
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
	cin >> a;
	int n = (int) a.size();
	build(1, 0, n - 1);
	int q;
	cin >> q;
	while (q--) {
		int type;
		cin >> type;
		if (type == 1) {
			int i; char c;
			cin >> i >> c;
			i -= 1;
			upd(1, 0, n - 1, i, c);
		} else {
			int l, r;
			cin >> l >> r;
			l -= 1, r -= 1;
			node ans = query(1, 0, n - 1, l, r);
			cout << ans.c << '\n';
		}
	}
	return 0;
}
