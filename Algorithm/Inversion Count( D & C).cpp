#include<bits/stdc++.h>
using namespace std;

int merge_(int l, int mid, int h, vector<int> &ar){
    vector<int> left, right;
    for(int i = l; i <= mid; i++){
        left.push_back(ar[i]);
    }
     for(int i = mid + 1; i <= h; i++){
        right.push_back(ar[i]);
    }
   int i = 0, j = 0, k = l, cnt = 0;
   while(i < left.size() && j < right.size()){
      if(left[i] <= right[j]){
        ar[k++] = left[i++];
      }else{
        cnt += (mid - l + 1);
        ar[k++] = right[j++];
      }
   }
   while(i < left.size()){
    ar[k++] = left[i++];
   }
    while(j < right.size()){
    ar[k++] = right[j++];
   }
return cnt;
}

int INV_CNT(int l, int h, vector<int> &ar){
    if(l >= h)return 0;
    int mid = (l + h) >> 1;
    int c1 = INV_CNT(l, mid, ar);
    int c2 =  INV_CNT(mid + 1, h, ar);
    int c3 =  merge_(l, mid, h, ar);
    return c1 + c2 + c3;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> ar(n);
    for(int i = 0; i < n; i++){
        cin >> ar[i];
    }
    int ans = INV_CNT(0, n - 1, ar);
    cout << ans << '\n';
    return 0;
}
