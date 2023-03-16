#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int k,  distinct = 0, a[N + 10];
vector<int> freq (N * 10);
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
 void add(int i){
     freq[i]++;
     if(freq[i] == 1){
         distinct++;
     }
}

void remove(int i){
    freq[i]--;
    if(freq[i] == 0){
        distinct--;
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int q;
    cin >> q;
    k = (int) sqrt(n);
    query = new Q[q];
    for(int i = 0; i < q; i++){
        int l, r;
        cin >> l >> r;
        query[i].l = l - 1;
        query[i].r = r - 1;
        query[i].idx = i;
    }
    sort(query, query + q, compare);int L = 0, R = -1, cur_l, cur_r;
    vector<int> ans(q);
    for(int i = 0; i < q; i++){
        cur_l = query[i].l, cur_r = query[i].r;
        while(R < cur_r){
            R += 1;
            add(a[R]);
        }
        while(L > cur_l){
            L -= 1;
            add(a[L]);
        }
        while(R > cur_r){
            remove(a[R]);
            R -= 1;
        }
        while(L < cur_l){
            remove(a[L]);
            L += 1;
        }
        ans[query[i].idx] = distinct;
    }
    for(int i =0; i < q; i++){
        cout << ans[i] << '\n';
    }
    return 0;
}
