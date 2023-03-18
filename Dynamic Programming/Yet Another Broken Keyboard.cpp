//Recursive
#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N = 2e5 + 9; int n, k;
vector<bool> type(26, false); vector<int> A(N);
int dp[N];

void f(int i){
    if(i == 0){
        dp[i] = (A[i] == 1);
        return;
    }
    f(i - 1);
    if(A[i] != 0) dp[i] = dp[i - 1] + (A[i] == 1);
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    string s;
    cin >> s;
    for(int i = 0; i < k; i++){
        char c;
        cin >> c;
        type[c - 'a'] = true;
    }
    for(int i = 0; i < n; i++){
        if(type[s[i] - 'a']) A[i] = 1;
        else A[i] = 0;
    }
    f(n - 1);
    cout << accumulate(dp, dp + n, 0LL) << '\n';
    return 0;
}
//Iterative
#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N = 2e5 + 9; int n, k;
vector<bool> type(26, false); vector<int> A(N);
int dp[N];

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    string s;
    cin >> s;
    for(int i = 0; i < k; i++){
        char c;
        cin >> c;
        type[c - 'a'] = true;
    }
    for(int i = 0; i < n; i++){
        if(type[s[i] - 'a']) A[i] = 1;
        else A[i] = 0;
    }
    dp[0] = (A[0] == 1);
    for(int i = 1; i < n; i++){
        if(A[i])dp[i] = dp[i - 1] + 1;
    }
    cout << accumulate(dp, dp + n, 0LL) << '\n';
    return 0;
}
