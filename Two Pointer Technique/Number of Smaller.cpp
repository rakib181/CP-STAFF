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
    int n,m;
    cin>> n >> m;
   vector<int> a(n);
   vector<int> b(m);
    for(int i=0;i<n;i++){
      cin>> a[i];
    }
    for(int i=0;i<m;i++){
      cin>> b[i];
    }
   vector<int> res(m);
    int i=0,j=0,k=0;
    while(i<n || j<m){
      if(j==m || (i<n && a[i]<b[j])){
        k++;i++;
      }else{
        res[j]=i;
       k++;j++;
      }
    }
    for(int x : res){
      cout<< x <<" ";
    }
    cerr<<1.0 * (clock()-start)/CLOCKS_PER_SEC<<endl;
    return 0;
}

// Another Approach
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
    int n,m;
    cin>> n >> m;
   vector<int> a(n);
   vector<int> b(m);
    for(int i=0;i<n;i++){
      cin>> a[i];
    }
    for(int i=0;i<m;i++){
      cin>> b[i];
    }
   vector<int> res(m);
    int i=0;
    for(int j=0;j<m;j++){
      while(i<n && a[i]<b[j]){
        i++;
      }
      res[j]=i;
    }    
    for(int x : res){
      cout<< x <<" ";
    }
    cerr<<1.0 * (clock()-start)/CLOCKS_PER_SEC<<endl;
    return 0;
}

