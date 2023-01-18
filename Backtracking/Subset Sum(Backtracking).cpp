#include<bits/stdc++.h>
using namespace std;
#define int long long int
int n, s;
vector<int> a;

bool backtrack(int i, int sum){
    if(i == n){
        if(sum == s)return true;
        return false;
    }
    bool sub1 = backtrack(i + 1, sum + a[i]);
    bool sub2 = backtrack(i + 1, sum);
    return sub1 || sub2;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> s;
    a.resize(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    if(backtrack(0, 0)){
        cout << "Found" << '\n';
    }else cout << "NOT FOUND" << '\n';
    return 0;
}
