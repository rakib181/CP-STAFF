#include<bits/stdc++.h>
using namespace std;
int num(int a, int b){
    if(a == b)return 1;
    int ways = 0;
    if(a + 1 <= b)ways += num(a + 1, b);
    if(a + 2 <= b)ways += num(a + 2, b);
    if(a + 3 <= b)ways += num(a + 3, b);
    return ways;
}

int32_t main(){
     ios_base::sync_with_stdio(0);
      cin.tie(0); 
      #ifndef ONLINE_JUDGE 
      freopen("input.txt","r",stdin); 
      freopen("output.txt","w",stdout); 
      #endif
      auto start=clock();
      int a, b;
      cin >> a >> b;
      cout << num(a, b) << '\n';
      cerr<<1.0 * (clock()-start)/CLOCKS_PER_SEC<<endl;
      return 0;
}
