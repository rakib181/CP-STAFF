#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 50;
vector<int> prime;

bool is_prime(int n){
    for(int i = 2; i * i <= n; i++){
        if(n % i == 0)return false;
    }
    return true;
}

void cal(){
    for(int i = 2; i < N; i++){
        if(is_prime(i))prime.emplace_back(i);
    }
}

int ask(int x){
    cout << x << endl;
    string s;
    cin >> s;
    return s == "yes";
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cal();
    int d = 0;
    if(ask(2 * 2) or ask(3 * 3) or ask(5 * 5) or ask(7 * 7)){
        cout << "composite" << endl;
    }
    for(auto p : prime){
          d += ask(p);
    }
    if(d <= 1)cout << "prime" << endl;
    else cout << "composite" << endl;
    return 0;
}
