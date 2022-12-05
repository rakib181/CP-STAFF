#include<bits/stdc++.h>
using namespace std;

#define int long long int

struct fenwick
{
    vector<int> fn;
    int n{}, MOD = 1e9 + 7;
    void init(int _n){
        this -> n = _n;
        fn.resize(this -> n,0);
    }
    int update(int i, int val)
    {

        while(i <= n) {
            fn[i] = (fn[i] + val) % MOD;
            i += (i & -i);	}

    }

    int query(int i)
    {
        int result = 0;
        while(i) {
            result =  (result + fn[i]) % MOD;
            i -= (i & -i);
        }
        return result;
    }
};


int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt, cs = 1;
    cin >> tt;
    while (tt--){
        cout << "Case " << cs++ << ": ";
        fenwick fn;
        int n;
        cin >> n;
        fn.init(n + 10);
        vector<int> a (n + 1), b (n + 1);
        map<int, int> mp;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }
        b = a;
        sort(b.begin() + 1, b.end());
        for(int i = 1; i <= n; i++){
            if(!mp.count(b[i])){
                mp[b[i]] = i;
            }
        }
        for(int i = 1; i <= n; i++){
            int x = mp[a[i]];
            int cnt = fn.query(x - 1) % fn.MOD;
            fn.update(x, cnt + 1);
        }
        cout << fn.query(n) % fn.MOD << '\n';
    }
    return 0;
}
