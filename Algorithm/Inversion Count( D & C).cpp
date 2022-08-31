#include<bits/stdc++.h>
using namespace std;

int merge(vector<int> &ar, int s, int e){
    int i = s, mid = (s + e) >> 1, j = mid + 1, cnt = 0;
     vector<int> tmp;
     while(i <= mid and j <= e){
        if(ar[i] <= ar[j]){
            tmp.push_back(ar[i]);
            i++;
        }else{
          cnt += (mid - i + 1);
          tmp.push_back(ar[j]);
          j++;
        }
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
     return cnt;
}

int inv_cnt(vector<int> &ar, int s, int e){
    if(s >= e)return 0;
    int mid = (s + e) >> 1;
    int c1 = inv_cnt(ar, s, mid);
    int c2 = inv_cnt(ar, mid + 1, e);
    int combine = merge(ar, s, e);
    return c1 + c2 + combine;
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
      cout << inv_cnt(ar, 0, n - 1) << '\n';
      cerr<<1.0 * (clock()-start)/CLOCKS_PER_SEC<<endl;
      return 0;
}
