#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 9;
int parent[N], Rank[N];

void init(int n){
    for(int i = 1; i <= n; i++){
        parent[i] = i;
        Rank[i] = 1;
    }
}

int find(int v){
   if(parent[v] == v)return v;

   return parent[v] = find(parent[v]);
}

void m_union(int u, int v){
    u = find(u), v = find(v);
    if(u == v)return;

    if(Rank[u] > Rank[v]){
        parent[v] = u;
    }else if(Rank[v] > Rank[u]){
        parent[u] = v;
    }else{
        parent[v] = u;
        Rank[v]++;
    }
}

int32_t main(){
     ios_base::sync_with_stdio(0);
      cin.tie(0); 
      #ifndef ONLINE_JUDGE 
      freopen("input.txt","r",stdin); 
      freopen("output.txt","w",stdout); 
      #endif
      auto start=clock();
      int tt;
      cin >> tt;
      while(tt--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        n <<= 1;
        init(n);
        stack<pair<char, int>> st;
        for(int i = 0; i < n; i++){
            if(s[i] == '('){
                st.push({s[i], i + 1});
            }else{
                auto u = st.top();
                int t = u.second;
                m_union(i + 1, t);
                st.pop();
            }
        }
        for(int i = 0; i < n - 1; i++){
            if(s[i] == ')' and s[i + 1] == '('){
                m_union(i + 1, i + 2);
            }
        }
        int cnt = 0;
        for(int i = 1; i <= n; i++){
            if(find(i) == i)cnt++;
        }
        cout << cnt << '\n';
      }
      cerr<<1.0 * (clock()-start)/CLOCKS_PER_SEC<<endl;
      return 0;
}
