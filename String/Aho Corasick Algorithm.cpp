#include<bits/stdc++.h>
using namespace std;

const int NX = 505, MXS = NX * NX + 2;
string text;    int n;
vector<string> inp(NX);
vector<int> failure, ans;
vector<vector<int>> trie;
bitset<NX> out[MXS];

void BuildAutomata(){
    failure.assign(MXS, -1);
    trie.assign(MXS, vector<int> (30, -1));
    memset(out, 0, sizeof out);
    int state = 0;
    for(int i = 0; i < n; i++){
        int cur_state = 0;
        for(int j = 0; j < (int) inp[i].size(); j++){
              int c = inp[i][j] - 'a';
              if(trie[cur_state][c] == -1){
                  trie[cur_state][c] = ++state;
              }
              cur_state = trie[cur_state][c];
        }
        out[cur_state].set(i);
    }
    for(int i = 0; i < 26; i++){
        if(trie[0][i] == -1)trie[0][i] = 0;
    }
    queue<int> q;
    for(int i = 0; i < 26; i++){
        if(trie[0][i] != -1 and trie[0][i] != 0){
            failure[trie[0][i]] = 0;
            q.push(trie[0][i]);
        }
    }
    while (!q.empty()){
        int st = q.front();
        q.pop();
        for(int i = 0; i < 26; i++){
            if(trie[st][i] != -1){
                int fail = failure[st];
                while (trie[fail][i] == -1)fail = failure[fail];
                fail = trie[fail][i];
                failure[trie[st][i]] = fail;
                out[trie[st][i]] |= out[fail];
                q.push(trie[st][i]);
            }
        }
    }
}

int find_next_state(int cur_state, int now){
    while (trie[cur_state][now] == -1) cur_state = failure[cur_state];
    return trie[cur_state][now];
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt, cs = 1;
    cin >> tt;
    while (tt--){
        ans.assign(NX, 0);
        cin >> n;
        cin >> text;
        for(int i = 0; i < n; i++){
            cin >> inp[i];
        }
        BuildAutomata();
        int current_state = 0;
        for(char i : text){
            int now = i - 'a';
            current_state = find_next_state(current_state, now);
            if(out[current_state] == 0) continue;
            for(int j = 0; j < n; j++){
                 if(out[current_state].test(j)){
                     ans[j]++;
                 }
            }
        }
        cout << "Case " << cs++ << ":\n";
        for(int i = 0; i < n; i++){
            cout << ans[i] << '\n';
        }
    }
    return 0;
}
