#include<bits/stdc++.h>
using namespace std;

int partition(vector<int> &ar, int s, int e){
    int pivot = ar[e];
    int i = s - 1;
    for(int k = s; k <= e; k++){
        if(ar[k] < pivot){
            swap(ar[++i], ar[k]);
        }
    }
    swap(ar[i + 1], ar[e]);
    return i + 1;
}

void quick_sort(vector<int> &ar, int s, int e){
    if(s >= e)return;

    int p = partition(ar, s, e);
    quick_sort(ar, s, p - 1);
    quick_sort(ar, p, e);
}

int32_t main(){
     ios_base::sync_with_stdio(0);
      cin.tie(0); 
      #ifndef ONLINE_JUDGE 
      freopen("input.txt","r",stdin); 
      freopen("output.txt","w",stdout); 
      #endif
      auto start=clock();
      int n;
      cin >> n;
      vector<int> ar(n);
      for(int i = 0; i < n; i++){
        cin >> ar[i];
      }    
      quick_sort(ar, 0, n - 1);
      for(int i = 0; i < n; i++){
        cout << ar[i] << ' ';
      }
      cerr<<1.0 * (clock()-start)/CLOCKS_PER_SEC<<endl;
      return 0;
}
