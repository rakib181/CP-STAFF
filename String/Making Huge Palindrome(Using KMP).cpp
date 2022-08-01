#include <bits/stdc++.h>
using namespace std;


int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt, Case = 1;
    cin >> tt;
    while(tt--) {
        cout << "Case " << Case++ << ": ";
        string s, rev;
        cin >> s;
        rev = s;
        reverse(rev.begin(), rev.end());
        rev += '#' + s;
        vector<int> lps;
        auto _lps = [&](string s) {
            int n = s.size();
            lps.push_back(0);
            int i = 0, j = 1;
            for (; s[j];) {
                if (s[i] == s[j]) {
                    lps.push_back(i + 1);
                    i++, j++;
                } else {
                    if (i != 0)i = lps[i - 1];
                    else j++, lps.push_back(0);
                }
            }
        };
        _lps(rev);
        cout << 2 * s.size() - lps[lps.size() - 1] << '\n';
        lps.clear();
    }
    return 0;
}
