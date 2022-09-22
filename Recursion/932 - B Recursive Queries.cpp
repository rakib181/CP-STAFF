#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 1;
vector<vector<int>> func(10, vector<int> (N, 0));

int rec(int x){
  if(x < 10)return x;
  int y = 1;
  while(x){
    if(x % 10) y *= x % 10;
    x /= 10;
  }
  return rec(y);
}

int32_t main(){
   ios_base::sync_with_stdio(0);
    cin.tie(0); 
    #ifndef ONLINE_JUDGE 
    freopen("input.txt","r",stdin); 
    freopen("output.txt","w",stdout); 
    #endif
    auto start=clock();
    for(int i = 1; i < N; i++){
       func[rec(i)][i]++;
    }
    for(int i = 1; i < 10; i++){
      for(int j = 1; j < N; j++){
        func[i][j] += func[i][j - 1];
      }
    }
    int q;
    cin >> q;
    while(q--){
      int l, r, k;
      cin >> l >> r >> k;
      cout << func[k][r] - func[k][l - 1] << '\n';
    }
    cerr<<1.0 * (clock()-start)/CLOCKS_PER_SEC<<endl;
    return 0;
}
