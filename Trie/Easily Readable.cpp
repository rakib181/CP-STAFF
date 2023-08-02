#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 9;
struct node{
    int nxt[52]{}, cnt{};
}t[N];
int it;

void clear(){
    for(auto & i : t){
        for(int & j : i.nxt){
            j = -1;
        }
        i.cnt = 0;
    }
    it = 0;
}

int get(char c){
    if(c >= 'a' and c <= 'z')return c - 'a';
    return 26 + (c - 'A');
}

void insert(string &s){
    int cur = 0;
    for(auto x : s){
        if(t[cur].nxt[get(x)] == -1){
            t[cur].nxt[get(x)] = ++it;
        }
        cur = t[cur].nxt[get(x)];
    }
    t[cur].cnt += 1;
}

int search(string &s){
    int cur = 0;
    for(auto x: s){
        if(t[cur].nxt[get(x)] == -1)return 0;
        cur = t[cur].nxt[get(x)];
    }
    return t[cur].cnt;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt, cs = 1;
    cin >> tt;
    while(tt--){
        clear();
        int n;
        cin >> n;
        for(int i = 0; i < n; i++){
            string s;
            cin >> s;
            if((int) s.size() > 2) sort(s.begin() + 1, s.end() - 1);
            insert(s);
        }
        int m;
        cin >> m;
        cin.ignore(); cout << "Case " << cs++ << ":\n";
        while (m--){
            string s, word; int ans = 1;
            getline(cin, s);
            stringstream ss(s);
            while(ss >> word){
               if((int) word.size() > 2) sort(word.begin() + 1, word.end() - 1);
                ans *= search(word);
            }
            cout << ans << '\n';
        }
    }
    return 0;
}
