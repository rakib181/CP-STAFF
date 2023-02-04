#include<bits/stdc++.h>
using namespace std;

const int MX=100+2;

int cnt[MX];

void Bubblesort(vector<int>& v,int n){
  for(int i=0;i<n;i++){
      for(int j=0;j<n-i-1;j++){
        if(v[j]>v[j+1]){
          swap(v[j],v[j+1]);
        }
      }
    }
    for(int i=0;i<n;i++){
      cout<< v[i] << ' ';
    }
    cout << '\n';
 }

 void Countingsort(vector<int>& v,int n){
  for(int i=0;i<n;i++){
    cnt[v[i]]++;
  }
  for(int i=0;i<MX;i++){
     for(int j=0;j<cnt[i];j++){
      cout<<i<<' ';
     }
   }
   cout << '\n';
 }

 void Selectionsort(vector<int>& v,int n){
  for(int i=0;i<n-1;i++){
    int min_idx=i;
    for(int j=i+1;j<n;j++){
      if(v[min_idx]>v[j]){
        min_idx=j;
      }
         swap(v[i],v[min_idx]);
    }
  }
    for(int i=0;i<n;i++){
      cout<< v[i] << ' ';
    }
    cout << '\n';
 }

 void Insertionsort(vector<int>& v,int n){
  for(int i=1;i<n;i++){
    int key=v[i];
    int j=i-1;
    while(j>=0 && v[j] > key){
        v[j+1]=v[j];
        j--;
    }
    v[j+1]=key;
  }
   for(int i=0;i<n;i++){
      cout<< v[i] << ' ';
    }
    cout << '\n';
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
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    //Bubble Sort Easy Way to Implement O(N^2)
    // Bubblesort(v,n);
    // Countingsort(v,n);
    //Selectionsort(v,n);
      Insertionsort(v,n);
    cerr<<1.0 * (clock()-start)/CLOCKS_PER_SEC<<endl;
    return 0;
}
