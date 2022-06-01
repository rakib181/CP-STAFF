#include<bits/stdc++.h>
using namespace std;

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
    vector<int> v(n);
    for(int i=0;i<n;i++){
      cin >> v[i];
    }
    for(int i=1;i<n;i++){
      int j=i;
      while(j>0 && v[j]<v[j-1]){
         swap(v[j],v[j-1]);
         j--;
      }
    }
    for(int i=0;i<n;i++){
       cout << v[i] << " ";
    }
    cerr<<1.0 * (clock()-start)/CLOCKS_PER_SEC<<endl;
    return 0;
}
