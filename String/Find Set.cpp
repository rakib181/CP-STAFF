#include<bits/stdc++.h>
using namespace std;

vector<string> a;
int n;
vector<int> createLps(string pattern){
    int N = (int) pattern.size();
    vector<int> lps(N);
    int index = 0, i = 1;
    while(i < N){
        if(pattern[index] == pattern[i]){
            lps[i] = index + 1;
            i += 1, index += 1;
        }else{
            if(index != 0) index = lps[index - 1];
            else lps[index] = index, i += 1;
        }
    }
    return lps;
}

bool is_substring(string &s, string &pat){
    int sz = (int) pat.size();
    vector<int> lps = createLps(pat);
    int i = 0, j = 0;
    int N = (int) s.size();
    while(i < N){
        if(s[i] == pat[j]){
            i += 1, j += 1;
        }else{
            if(j != 0) j = lps[j - 1];
            else i += 1;
        }
        if(j == sz)return true;
    }
    return false;
}

int covered(){
    vector<int> vis(n + 1, false);
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(vis[i])continue;
        ans += 1;
        vis[i] = true;
        for(int j = 0; j < n; j++){
            if(!vis[j] and (is_substring(a[i], a[j]) or is_substring(a[j], a[i]))){
                vis[j] = true;
            }
        }
    }
    return ans;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for(int i = 1; i <= n; i++){
        string s;
        cin >> s;
        a.emplace_back(s);
    }
    sort(a.begin(), a.end(), [](string &x, string &y){
        return (int) x.size() < (int) y.size();
    });
    cout << covered() << '\n';
    return 0;
}
