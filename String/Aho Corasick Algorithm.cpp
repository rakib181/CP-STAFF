#include <bits/stdc++.h>
using namespace std;
const int MX = 500, MXC = 27;
vector<vector<int>> Goto(MX, vector<int> (MXC, -1));
vector<int> failure(MX, -1), output(MX, 0);

void build_automata(string ar[], int n) {
    int st = 1;
    for (int i = 0; i < n; i++) {
        string word = ar[i];
        int cur_state = 0;
        for (char j: word) {
            int ch = j - 'a';
            if (Goto[cur_state][ch] == -1) {
                Goto[cur_state][ch] = st++;
            }
            cur_state = Goto[cur_state][ch];
        }
        output[cur_state] |= (1 << i);
    }
    for (int i = 0; i < MXC; i++) {
        if (Goto[0][i] == -1) {
            Goto[0][i] = 0;
        }
    }
    queue<int> q;
    for (int i = 0; i < MXC; i++) {
        if (Goto[0][i] != 0) {
            failure[Goto[0][i]] = 0;
            q.push(Goto[0][i]);
        }
    }
    while (!q.empty()) {
        int state = q.front();
        q.pop();
        for (int i = 0; i < MXC; i++) {
            if (Goto[state][i] != -1) {
                int f = failure[state];
                while (Goto[f][i] == -1) f = failure[f];

                f = Goto[f][i];
                failure[Goto[state][i]] = f;
                output[Goto[state][i]] |= output[f];
                q.push(Goto[state][i]);
            }
        }
    }
}

int get_next_state(int present_state, char ch){
    int tmp_state = present_state, i = ch - 'a';
    while(Goto[tmp_state][i] == -1){
        tmp_state = failure[tmp_state];
    }
    return Goto[tmp_state][i];
}

void search_word(string ar[], int n, string &text){
    build_automata(ar, n);
    int present_state = 0;
    for(int i = 0; i < (int) text.size(); i++){
        present_state = get_next_state(present_state, text[i]);
        if(!output[present_state])continue;
            for(int j = 0; j < n; j++){
                if(output[present_state] & (1 << j)){
                    cout << "Word " << ar[j] << " location " << i - (int) ar[j].size() + 1 << '\n';
                }
            }
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    string ar[n];
    for(int i = 0; i < n; i++){
        cin >> ar[i];
    }
    string s;
    cin >> s;
    search_word(ar,n, s);
    return 0;
}
