#include<bits/stdc++.h>
using namespace std;
#define int long long int

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
    k = 0;
    vector<int> LCP(n);
    for(int i = 0; i < n - 1; i++){
        int pi = c[i];
        int j = p[pi - 1];
        while ((i + k <  n) and (j + k < n) and s[i + k] == s[j + k])k++;
        LCP[pi] = k;
        k = max<long long> (0, k - 1);
    }
    for(int i = 0; i < n; i++){
        cout << p[i] << ' ';
    }
    cout << '\n';
    for(int i = 1; i < n; i++){
        cout << LCP[i] << ' ';
    }
    return 0;
}
