#include<bits/stdc++.h>
using namespace std;

const int N = 2 * 1e5 + 9;
vector<int> ar(N);

class fenwick{
public:
    int n;
    long long *fen;
    void init(int n){
        this -> n = n;
        this -> fen = new long long[n + 10]{0};
    }
    void upd(int x){
        while(x <= n){
            fen[x] += 1;
            x += x & (-x);
        }
    }
    int get_ans(int x) const{
      x++; int sum = 0;
        while(x){
            sum += fen[x];
            x -= x & (-x);
        }
        return sum;
    }
    int get_ans(int l, int r){
        return get_ans(r) - get_ans(l - 1);
    }
}fn;

int32_t main(){
    int n, idx = 1;
    cin >> n;
    fn.init(n);
    string s, rev;
    cin >> s;
    rev = s;
    reverse(rev.begin(), rev.end());
    queue<int> q[26];
    for(int i = 0; i < n; i++){
        q[rev[i] - 'a'].push(idx++);
    }
    for(int i = 0; i < n; i++){
        ar[i] = q[s[i] - 'a'].front();
        q[s[i] - 'a'].pop();
    }
    long long ans = 0;
    for(int i = 0; i < n; i++){
        fn.upd(ar[i]);
        ans += fn.get_ans(ar[i],n - 1);
    }

    cout << ans << '\n';
    return 0;
}

