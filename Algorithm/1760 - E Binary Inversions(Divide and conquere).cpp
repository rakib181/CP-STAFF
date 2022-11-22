#include <bits/stdc++.h>
using namespace std;
#define int long long int

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
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
       int n;
       cin >> n;
       vector<int> ar(n), br(n), cr(n);
       for(int i = 0; i < n; i++){
           cin >> ar[i];
       }
       br = ar;
       cr = ar;
       for(int i = 0; i < n; i++){
           if(!ar[i]){
               ar[i] = 1;
               break;
           }
       }
       for(int i = n - 1; i >= 0; i--){
           if(br[i]){
               br[i] = 0;
               break;
           }
       }
       int inv_1 = inv_cnt(ar, 0, n - 1);
       int inv_2 = inv_cnt(br, 0, n - 1);
       int inv_3 = inv_cnt(cr, 0, n - 1);
       cout << max({inv_1, inv_2, inv_3}) << '\n';
    }
    return 0;
}
