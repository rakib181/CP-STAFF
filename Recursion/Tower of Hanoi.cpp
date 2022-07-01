#include<bits/stdc++.h>
using namespace std;

void TowerOfHanoi(int n, char from, char helper, char to){
  if(n == 0)return;
  TowerOfHanoi(n - 1, from, to, helper);
  cout << from << "-->" << to << '\n';
  TowerOfHanoi(n - 1, helper, from, to);
}

int32_t main(){
   ios_base::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);
    #ifndef ONLINE_JUDGE 
    freopen("input.txt","r",stdin); 
    freopen("output.txt","w",stdout); 
    #endif
    auto start=clock();
    int n;
    cin >> n;
    TowerOfHanoi(n, 'A', 'B', 'C');
    cerr<<1.0 * (clock()-start)/CLOCKS_PER_SEC<<endl;
    return 0;
}
