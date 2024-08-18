#include<bits/stdc++.h>
using namespace std;
#define long long long int


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
        string s;
        cin >> s;
        s = s + '$';
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
        int l, r;
        cin >> l >> r;
        long ans = 0;
        for (int i = 0; i < n; i++) {
            int dis = min(n - p[i], r) - max(l - 1, lcp[i]);
            if (dis > 0)ans += dis;
        }
        cout << ans - (r - l + 1) << '\n';
    }
    return 0;
}
