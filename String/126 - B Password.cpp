#include<bits/stdc++.h>
using namespace std;

void prefix(string &s, vector<int> &pi){
   pi[0] = -1; int n = (int) s.size() ;
   for(int i = 1; i <= n; i++){
       int k = pi[i - 1];
       while (k >= 0 and s[k] != s[i - 1])k = pi[k];
       pi[i] = k + 1;
   }
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string pat;
    cin >> pat;
    int n = (int) pat.size();
    vector<int> pi(n + 1);
    prefix(pat, pi); int idx = 0;
    for(int i = 1; i < n; i++){
        if(pi[i] == pi[n] or pi[i] == pi[pi[n]]){
            idx = max(idx, pi[i]);
        }
    }
    cout << (idx ? pat.substr(0, idx) : "Just a legend");
    return 0;
}

//Hashing
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e6 + 9, p1 = 137, p2 = 277, mod1 = 1e9 + 7, mod2 = 1e9 + 9;
pair<int, int> pw[N], ipw[N];

int bin(int x, int y, int mod) {
	int ans = 1;
	while (y) {
		if (y & 1) ans = 1LL * ans * x % mod;
		x = 1LL * x * x % mod;
		y >>= 1;
	}
	return ans;
}


void cal() {
	pw[0] = {1, 1};
	for (int i = 1; i < N; i++) {
		pw[i].first = 1LL * pw[i - 1].first * p1 % mod1;
		pw[i].second = 1LL * pw[i - 1].second * p2 % mod2;
	}
	int ip1 = bin(p1, mod1 - 2, mod1);
	int ip2 = bin(p2, mod2 - 2, mod2);
	ipw[0] = {1, 1};
	for (int i = 1; i < N; i++) {
		ipw[i].first = 1LL * ipw[i - 1].first * ip1 % mod1;
		ipw[i].second = 1LL * ipw[i - 1].second * ip2 % mod2;
	}
}

struct H {
	pair<int, int> prefix[N];

	void build(string &s) {
		int n = (int) s.size();
		for (int i = 0; i < n; i++) {
			prefix[i].first = 1LL * s[i] * pw[i].first % mod1;
			if (i)prefix[i].first = (1LL * prefix[i].first + prefix[i - 1].first) % mod1;
			prefix[i].second = 1LL * s[i] * pw[i].second % mod2;
			if (i)prefix[i].second = (1LL * prefix[i].second + prefix[i - 1].second) % mod2;
		}
	}

	pair<int, int> get_hash(int i, int j) {
		assert(i <= j);
		pair<int, int> ans = {0, 0};
		ans.first = prefix[j].first;
		if (i) ans.first =  ((1LL * ans.first - prefix[i - 1].first) + mod1) % mod1;
		ans.first = 1LL * ans.first * ipw[i].first % mod1;
		ans.second = prefix[j].second;
		if (i) ans.second = ((1LL * ans.second - prefix[i - 1].second) + mod2) % mod2;
		ans.second = 1LL * ans.second * ipw[i].second % mod2;
		return ans;
	}
} h;

bool found(pair<int, pair<int, int>> &t, int n) {
	int len = t.first;
	auto hash = t.second;
	for (int i = 1; i + len - 1 < n - 1; i++) {
		if (h.get_hash(i, i + len - 1) == hash) {
			return true;
		}
	}
	return false;
}


signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	cal();
	string s;
	cin >> s;
	int n = (int) s.size();
	h.build(s);
	vector < pair<int, pair<int, int>>> len;
	for (int i = 0; i < n - 1; i++) {
		//cout << h.get_hash(0, i).first << ' ' << h.get_hash(0, i).second << ' ' << h.get_hash(n - i, n).first << ' ' << h.get_hash(n - i, n).second << '\n';
		auto x = h.get_hash(0, i), y = h.get_hash(n - i - 1, n - 1);
		if (x == y) {
			//cout << s.substr(0, i + 1) << ' ' << s.substr(n - i - 1) << '\n';
			len.push_back({i + 1, x});
		}
	}
	int l = 0, r = (int) len.size() - 1, ans = -1;
	while (l <= r) {
		int m = (l + r) >> 1;
		if (found(len[m], n)) {
			ans = len[m].first;
			l = m + 1;
		} else r = m - 1;
	}
	ans != -1 ? cout << s.substr(0, ans) << '\n' : cout << "Just a legend\n";
	return 0;
}
