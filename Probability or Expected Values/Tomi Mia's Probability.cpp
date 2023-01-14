#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N = 15;
int fact[N + 1];
void cal(){
    fact[0] = 1;
    for(int i = 1; i <= N; i++){
        fact[i] = fact[i - 1] * i;
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cal();
    int tt;
    cin >> tt; map<string, int> st;
    cin.ignore();
    while (tt--){
       string str;
        getline(cin, str);
        stringstream s(str);
        string word; int cnt = 0;
        while (s >> word){
            cnt++;
            st[word]++;
        }
        int ans = fact[cnt];
        for(const auto& x : st){
           ans /= fact[x.second];
        }
        cout << "1/" << ans << '\n';
        st.clear();
    }
    return 0;
}
