#include<bits/stdc++.h>
using namespace std;
int n, k;
const int N = 2e5 + 9, MX = 26;
char ch[N];
vector<int> P(MX);

void brute_force(char c){
    for(int i = 0; i < n; i++){
        if(ch[i] == c){
            ch[i] = c - 1;
        }
    }
}

int find(int x){
    if(P[x] == x)return x;

    return P[x] = find(P[x]);
}

void ok_lets_try(char c){
    int x = c - 'a';
    if(P[x] == x){
        P[x] = x - 1;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--){
        cin >> n >> k >> ch;
        int c = ch[0];
        int nxt = c - 'a';
        if(nxt >= k){
            for(int i = 0; i < k; i++){
                brute_force(c--);
            }
        }else{
            for(int i = 0; i < 26; i++)P[i] = i;
            k = min(k, 25);
            for(int i = 0; i < n; i++){
                ch[i] = find(ch[i] - 'a') + 'a';
                while (ch[i] != 'a' and k != 0){
                    --k;
                    ok_lets_try(ch[i]);
                    --ch[i];
                    ch[i] =  find(ch[i] - 'a') + 'a';
                }
            }
        }
        cout << ch << '\n';
    }
    return 0;
}
