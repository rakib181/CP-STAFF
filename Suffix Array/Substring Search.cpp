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

bool search_substr(vector<int> &p, int n, string &s, string &str){
    int l = 1, r = n, len = (int) str.size();
    while (l <= r){
        int mid = (l + r) >> 1;
        string sub = s.substr(p[mid], min((n - p[mid] + 1), len));
        if(str == sub)return true;
        if(sub > str)r = mid - 1;
        else l = mid + 1;
    }
    return false;
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
    int q;
    cin >> q;
    while (q--){
        string str;
        cin >>  str;
        if(search_substr(p, n - 1, s, str)){
            cout << "Yes" << '\n';
        }else cout << "No" << '\n';
    }
    return 0;
}
