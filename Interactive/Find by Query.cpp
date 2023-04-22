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
    int l = 1, r = n, ans = -1;
    while(l <= r){
    	int m = (l + r) >> 1;
    	cout << '?' << " " << m << '\n';
    	cout.flush();
    	char c;
    	cin >> c;
    	if(c == '1'){
    		ans = m;
    		r = m - 1;
    	}else l = m + 1;
    }
    cout << '!' << " " << ans - 1 << '\n';
    cout.flush();
	return 0;
}
