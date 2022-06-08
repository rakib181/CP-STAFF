#include<bits/stdc++.h>
using namespace std;
const int N=100;
int prefix_sum[N][N];

int32_t main(){
   ios_base::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);
    #ifndef ONLINE_JUDGE 
    freopen("input.txt","r",stdin); 
    freopen("output.txt","w",stdout); 
    #endif
    auto start=clock();
    int n,m;
    cin >>n >>m;
    int ar[n+1][m+1];
    for(int i=1;i<=n;i++){
      for(int j=1;j<=m;j++){
         cin>>ar[i][j];
      }
    }
    prefix_sum[1][1]=ar[1][1];
    for(int i=2;i<=n;i++){
      prefix_sum[1][i]+=(prefix_sum[1][i-1]+ar[1][i]);
    }
    for(int i=2;i<=n;i++){
      prefix_sum[i][1]+=(prefix_sum[i-1][1]+ar[i][1]);
    }
    for(int i=2;i<=n;i++){
      for(int j=2;j<=m;j++){
        prefix_sum[i][j]+=((prefix_sum[i-1][j]+prefix_sum[i][j-1]+ar[i][j])-prefix_sum[i-1][j-1]);
      }
    }
    int q;
    cin >> q;
    while(q--){
      int from_row,from_col,to_row,to_col;
      cin >> from_row >> from_col >> to_row >> to_col;

      cout << prefix_sum[to_row][to_col]-prefix_sum[from_row-1][to_col]-prefix_sum[to_row][from_col-1]+prefix_sum[from_row-1][from_col-1] << '\n';
    }
    for(int i=1;i<=n;i++){
      for(int j=1;j<=m;j++){
        cout << prefix_sum[i][j] << ' ';
      }
      cout << '\n';
    }
    cerr<<1.0 * (clock()-start)/CLOCKS_PER_SEC<<endl;
    return 0;
}
