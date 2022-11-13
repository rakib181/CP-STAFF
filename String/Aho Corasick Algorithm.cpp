#include <bits/stdc++.h>
using namespace std;
#define int long long int
const int MX = 500 * 500 + 10, MXC = 26;
vector<vector<int>> Goto(MX, vector<int> (MXC, -1));
vector<int> failure(MX, -1);
bitset<510> output[MX];
struct {
   int occ;
   char s[MX];
}ar[510];

void build_automata(int n) {
    int st = 1;
    for (int i = 0; i < n; i++) {
        string word = ar[i].s;
        int cur_state = 0;
        for (char j: word) {
            int ch = j - 'a';
            if (Goto[cur_state][ch] == -1) {
                Goto[cur_state][ch] = st++;
            }
            cur_state = Goto[cur_state][ch];
        }
        output[cur_state].set(i + 1);
    }
    for (int i = 0; i < MXC; i++) {
        if (Goto[0][i] == -1) {
            Goto[0][i] = 0;
        }
    }
    queue<int> q;
    for (int i = 0; i < MXC; i++) {
        if (Goto[0][i] != 0 and Goto[0][i] != -1) {
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

void search_word(int n, string &text){
    build_automata(n);
    int present_state = 0;
    for(char i : text){
        present_state = get_next_state(present_state, i);
        if(output[present_state] == 0)continue;
            for(int j = 0; j < n; j++){
               if(output[present_state].test(j + 1))ar[j].occ++;
            }
    }
    for(int i = 0; i < n; i++){
        cout << ar[i].occ << '\n';
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt, idx = 1;
    cin >> tt;
    while (tt--){
        cout << "Case " << idx++ << ":" << '\n';
        Goto.assign(MX, vector<int> (MXC, -1));
        failure.assign(MX, -1);
        memset(output, 0, MX);
        int n;
        cin >> n;
        string s;
        cin >> s;
        for(int i = 0; i < n; i++){
            cin >> ar[i].s;
            ar[i].occ = 0;
        }
        search_word(n, s);
    }
    return 0;
}
