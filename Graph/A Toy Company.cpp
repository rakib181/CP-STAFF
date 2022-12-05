#include<bits/stdc++.h>
using namespace std;

#define int long long int
string a, b;
set<string> st;
map<string, bool> mp;

int BFS(){
    queue<string> q;
    q.push(a);
    mp[a] = true;
    int dep = 0;
    while (!q.empty()){
        int sz = (int) q.size();
        dep++;
        while(sz--){
           string cur = q.front();
           q.pop();
           for(int i = 0; i < (int) cur.size(); i++){
               string t = cur, tt = cur;
               t[i] = char(cur[i] - 'a' + 1) % 26 + 'a';
               tt[i] = char(cur[i] - 'a' - 1 + 26) % 26 + 'a';
               if(st.find(cur) != st.end())continue;
               if((st.find(t) == st.end() and t == b) or (st.find(tt) == st.end() and tt == b)){
                   return dep;
               }
               if(st.find(t) == st.end() and !mp[t]){
                   q.push(t);
                   mp[t] = true;
               }
               if(st.find(tt) == st.end() and !mp[tt]){
                  q.push(tt);
                  mp[tt] = true;
               }
           }
        }
    }
    return -1;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt, cs = 1;
    cin >> tt;
    while (tt--){
        cout << "Case " << cs++ << ": ";
        cin >> a >> b;
        int n;
        cin >> n;
        for(int i = 0; i < n; i++){
            string s, ss, sss;
            cin >> s >> ss >> sss;
            for(char j : s){
                for(char k : ss){
                    for(char l : sss){
                        string x;
                        x += j;
                        x += k;
                        x += l;
                        st.insert(x);
                    }
                }
            }
        }
        if(st.find(b) != st.end())cout << "-1" << '\n';
        else if(a == b)cout << "0" << '\n';
        else cout << BFS() << '\n';
        st.clear();
        mp.clear();
    }
    return 0;
}
