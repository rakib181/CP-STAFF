#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N = 1e5 + 9, MOD = 1e9 + 7;
vector<int> PW(N);

void cal(){
 PW[0] = 1;
 for(int i = 1; i < N; i++){
     PW[i] = (2 * PW[i - 1]) % MOD;
 }
}
class DSU{
public:
    vector<int> P, SZ;
    void init(int n){
        P.resize(n);
        SZ.resize(n, 1);
        iota(P.begin(), P.end(), 0);
    }

    int FIND(int v){
        if(P[v] == v)return v;
        return P[v] = FIND(P[v]);
    }

    void UNION(int u, int v){
        u = FIND(u), v = FIND(v);
        if(u == v)return;

        if(SZ[u] > SZ[v]){
            swap(u, v);
        }
        P[v] = u;
        SZ[u] += SZ[v];
    }
}DS;


int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cal();
    int tt;
    cin >> tt;
    while (tt--){
       int n;
       cin >> n;
       vector<int> a(n), b(n), c(n);
       for(int i = 0; i < n; i++){
           cin >> a[i];
       }
       for(int i = 0; i < n; i++){
           cin >> b[i];
       }
       for(int i = 0; i < n; i++){
           cin >> c[i];
       }
       DS.init(n + 2);
       for(int i = 0; i < n; i++){
           DS.UNION(a[i], b[i]);
       }
       set<int> st;
       for(int i = 1; i <= n; i++){
           st.insert(DS.FIND(i));
       }
       for(int i = 0; i < n; i++){
           if(c[i]){
               st.erase(DS.FIND(c[i]));
           }
       }
       int pw = 0;
       for(auto x : st){
          if(DS.SZ[DS.FIND(x)] > 1){
              pw++;
          }
       }
       cout << PW[pw] % MOD << '\n';
       DS.P.clear(), DS.SZ.clear();
    }
    return 0;
}
