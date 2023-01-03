#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
int k, sum, a[N];

struct Q{
    int l, r, idx;
};
Q *query;
bool compare(Q q1, Q q2){
    if(q1.l / k == q2.l / k){
        return q1.r > q2.r;
    }
    return q1.l / k < q2.l / k;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt, cs = 1;
    cin >> tt;
    while (tt--) {
        cout << "Case " << cs++ << ":" << '\n';
        int n, q;
        cin >> n >> q; sum = 0;
        for(int i = 0; i < N; i++)a[i] = 0;
        unordered_map<int, int> coordinateCompress;
        int compressNum = 1;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (coordinateCompress.find(a[i]) != coordinateCompress.end()) {
                a[i] = coordinateCompress[a[i]];
            } else {
                coordinateCompress[a[i]] = compressNum;
                a[i] = compressNum++;
            }
        }
        k = (int) sqrt(n) + 1;
        query = new Q[q];
        for (int i = 0; i < q; i++) {
            int l, r;
            cin >> l >> r;
            query[i].l = l;
            query[i].r = r;
            query[i].idx = i;
        }
        sort(query, query + q, compare);
        int L = 0, R = -1, cur_l, cur_r;
        vector<int> ans(q), freq(N * 10);
        for (int i = 0; i < q; i++) {
            cur_l = query[i].l, cur_r = query[i].r;
            cur_l--, cur_r--;
            while (R < cur_r) {
                freq[a[++R]]++;
                if (freq[a[R]] == 1) {
                    sum++;
                }
            }
            while (L > cur_l) {
                freq[a[--L]]++;
                if (freq[a[L]] == 1) {
                    sum++;
                }
            }
            while (R > cur_r) {
                freq[a[R]]--;
                if (freq[a[R]] == 0) {
                    sum--;
                }
                R--;
            }
            while (L < cur_l) {
                freq[a[L]]--;
                if (freq[a[L]] == 0) {
                    sum--;
                }
                L++;
            }
            ans[query[i].idx] = sum;
        }
        for (int i = 0; i < q; i++) {
            cout << ans[i] << '\n';
        }
    }
    return 0;
}
