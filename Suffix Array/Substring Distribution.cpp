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


vector<int> longest_common_prefix(string &s, vector<int> &p, int n){
    vector<int> lcp(n), c(n);
    int k = 0;
    for(int i = 0; i < n; i++){
        c[p[i]] = i;
    }
    for(int i = 0; i < n; i++){
        if(c[i] == 0){
            k = 0;
            continue;
        }
        int j = p[c[i] - 1];
        while(i + k < n and j + k < n and  s[i + k] == s[j + k])k++;
        lcp[c[i]] = k;
        if(k > 0)k--;
    }
    return lcp;
}


vector<int> suffixArray(string &s, int n){
    vector<int> p(n), c(n);
    {
        vector<pair<char, int>> a;
        for (int i = 0; i < n; i++) {
            a.emplace_back(s[i], i);
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
    while((1 << k) < n){
        vector<pair<pair<int, int>, int>> a;
        for(int i = 0; i < n; i++){
            int j = (i + (1 << k)) % n;
            a.push_back({{c[i], c[j]}, i});
        }
        counting(a);
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
        k += 1;
    }
    return p;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    s += '$';
    int n = (int) s.size();
    vector<int> p = suffixArray(s, n);
    vector<int> lcp = longest_common_prefix(s, p, n);
    vector<int> ans(n + 2);
    for(int i = 0; i < n; i++){
        int len = n - p[i];
       // cout << lcp[i] + 1 << ' ' << len + 1 << ' ' << s.substr(p[i]) << ' ' << lcp[i] << '\n';
        ans[lcp[i] + 1]++;
        ans[len + 1]--;
    }
    for(int i = 1; i < n; i++){
       ans[i] += ans[i - 1];
       cout << ans[i] - 1 << ' ';
    }
    return 0;
}
