#include<bits/stdc++.h>
using namespace std;
#define int long long int

const int N = 1e5 + 10;
long long t[N * 4];

void build(int node, int s, int e, vector<int> &a) {
    if(s == e) {
        t[node] = a[s];
        return;
    }
    int mid = (s + e) >> 1;
    int l = node << 1, r = l | 1;
    build(l, s, mid, a);
    build(r, mid + 1, e, a);
    t[node] = min(t[l] , t[r]);
}

long long query(int node, int s, int e, int l, int r) {
    if(s > r or e < l)return INT_MAX;
    if(s >= l and r >= e)return t[node];
    int mid = (s + e) >> 1;
    int i = node << 1, j = i | 1;
    return min(query(i, s, mid, l, r) , query(j, mid + 1, e , l , r));
}

void count_sort(vector<int> &p, vector<int> &c){
    int n = (int) p.size();
    vector<int> cnt(n);
    for (auto x: c) {
        cnt[x]++;
    }
    vector<int> p_new(n);
    vector<int> pos(n);
    pos[0] = 0;
    for (int i = 1; i < n; i++) {
        pos[i] = pos[i - 1] + cnt[i - 1];
    }
    for (auto x: p) {
        int i = c[x];
        p_new[pos[i]] = x;
        pos[i]++;
    }
    p = p_new;
}

int search_substr_left(vector<int> &p, int n, string &s, string &str){
    int l = 1, r = n, len = (int) str.size(), ans = 0;
    while (l <= r){
        int mid = (l + r) >> 1;
        string sub = s.substr(p[mid], min((n - p[mid] + 1), len));
        if(str > sub){
            l = mid + 1;
        }else{
            ans = mid;
            r = mid - 1;
        }
    }
    return ans;
}
int search_substr_right(vector<int> &p, int n, string &s, string &str){
    int l = 1, r = n, len = (int) str.size(), ans = 0;
    while (l <= r){
        int mid = (l + r) >> 1;
        string sub = s.substr(p[mid], min((n - p[mid] + 1), len));
        if(str < sub){
            r = mid - 1;
        }else{
            ans = mid;
            l = mid + 1;
        }
    }
    return ans;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    s += "$";
    int n = (int) s.size();
    vector<int> p(n), c(n);
    {
        vector<pair<char, int>> a(n);
        for(int i = 0; i < n; i++)a[i] = {s[i], i};
        sort(a.begin(), a.end());
        for(int i = 0; i < n; i++){
            p[i] = a[i].second;
        }
        c[p[0]] = 0;
        for(int i = 1; i < n; i++){
            if(a[i].first == a[i - 1].first){
                c[p[i]] = c[p[i - 1]];
            }else{
                c[p[i]] = c[p[i - 1]] + 1;
            }
        }
    }
    int k = 0;
    while ((1 << k) < n){
        for(int i = 0; i < n; i++){
            p[i] = (p[i] - (1 << k) + n) % n;
        }
        count_sort(p, c);
        vector<int> c_new(n);
        c_new[p[0]] = 0;
        for(int i = 1; i < n; i++){
            pair<int, int> prev = {c[p[i - 1]], c[(p[i - 1] + (1 << k)) % n]};
            pair<int, int> now = {c[p[i]],c[(p[i] + (1 << k)) % n]};
            if(prev == now){
                c_new[p[i]] = c_new[p[i - 1]];
            }else{
                c_new[p[i]] = c_new[p[i - 1]] + 1;
            }
        }
        c = c_new;
        k++;
    }
    build(1, 0, n - 1, p);
    int q;
    cin >> q;
    while (q--){
        string str;
        cin >>  str;
        int left = search_substr_left(p, n - 1, s, str);
        int right = search_substr_right(p, n - 1, s, str);
        if(right >= left and (right != 0 and left != 0)){
            int ans = query(1, 0, n - 1, left, right);
            cout << ans + 1 << '\n';
        }else cout << "-1" << '\n';
    }
    return 0;
}
