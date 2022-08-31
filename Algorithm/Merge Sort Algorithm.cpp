#include<bits/stdc++.h>
using namespace std;

void merge(vector<int> &ar, int s, int e){
    int i = s;
    int mid = (s + e) >> 1;
    int j = mid + 1;
    vector<int> tmp;
    while(i <= mid && j <= e){
        if(ar[i] < ar[j])tmp.push_back(ar[i++]);
        else tmp.push_back(ar[j++]);
    }
    while(i <= mid){
        tmp.push_back(ar[i++]);
    }
    while(j <= e){
        tmp.push_back(ar[j++]);
    }

    int k = 0;
    for(int idx = s; idx <= e; idx++){
        ar[idx] = tmp[k++];
    }
}

void merge_sort(vector<int> &ar, int s, int e){
    if(s >= e){
      return;
    }
    int mid = (s + e) >> 1;
    merge_sort(ar, s, mid);
    merge_sort(ar, mid + 1, e);
    return merge(ar, s, e);
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
      merge_sort(ar, 0, n - 1);
      for(int i = 0; i < n; i++){
        cout << ar[i] << ' ';
      }
      cerr<<1.0 * (clock()-start)/CLOCKS_PER_SEC<<endl;
      return 0;
}
