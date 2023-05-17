#include<bits/stdc++.h>
using namespace std;
using ll = long long;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	int a[n + 1];
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if ((int) accumulate(a + 1, a + n + 1, 0) == 0)cout << "0\n";
	else {
		ll ans = 1;
		stack<int> st;
		for (int i = 1; i <= n; i++) {
			if (a[i] and !st.empty()) {
				int d = i - st.top();
				ans *= d;
			}
			if (a[i])st.push(i);
		}
		cout << ans << '\n';
	}
	return 0;
}
