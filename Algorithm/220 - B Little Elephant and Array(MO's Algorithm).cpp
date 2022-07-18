#include<bits/stdc++.h>
using namespace std;

const int N = 1e5;
int k, *a;

struct Q{
int l, r, idx;
};

Q *query;

bool compare(Q q1, Q q2){
   if(q1.l / k == q2.l / k){
      return q1.r > q2.r;
   }
   return q1.l / k < q2.l / k;
}

int32_t main(){
    ios_base::sync_with_stdio(0);
     cin.tie(0); 
     #ifndef ONLINE_JUDGE 
     freopen("input.txt","r",stdin); 
     freopen("output.txt","w",stdout); 
     #endif
     auto start=clock();
     int n, q;
     cin >> n >> q;
     k = sqrt(n);
     a = new int[n + 1];
     query = new Q[q + 1];
     for(int i = 1; i <= n; i++){
      cin >> a[i];
     }
     for(int i = 1; i <= q; i++){
      int l, r;
      cin >> l >> r;
      query[i].l = l;
      query[i].r = r;
      query[i].idx = i;
     }
     sort(query + 1, query + q, compare);
     vector<int> v(q + 1); vector<pair<int, bool>> freq(N + 1);
     int L = 1, R = 0, cur_l, cur_r, ans = 0;
     for(int i = 1; i <= q; i++){
       cur_l = query[i].l, cur_r = query[i].r;
       while(R < cur_r){
         R++;
         if(a[R] >= freq.size())continue;
         freq[a[R]].first++;
         if(freq[a[R]].first == a[R]){
            freq[a[R]].second = true;
            ans++;
         }else{
            if(freq[a[R]].second){
               ans--;
               freq[a[R]].second = false;
            }
         }
       }
       while(L > cur_l){
         L--;
          if(a[L] >= freq.size())continue;
          freq[a[L]].first++;
         if(freq[a[L]].first == a[L]){
            freq[a[L]].second = true;
            ans++;
         }else{
            if(freq[a[L]].second){
               freq[a[L]].second = false;
               ans--;
            }
         }
      }
       while(R > cur_r){
         if(a[R] >= freq.size())continue;
         freq[a[R]].first--;
            if(freq[a[R]].second){
               freq[a[R]].second = false;
               ans--;
            }
            if(freq[a[R]].first == a[R]){
                freq[a[R]].second = true;
                ans++;
            }
           R--;
       }
        while(L < cur_l){
         if(a[L] >= freq.size())continue;
         freq[a[L]].first--;
        if(freq[a[L]].second){
               freq[a[L]].second = false;
               ans--;
            }
            if(freq[a[L]].first == a[L]){
                freq[a[L]].second = true;
                ans++;
            }
         L++;
       }
       v[query[i].idx] = ans;
     }
    for(int i = 1; i <= q; i++){
      cout << v[i] << '\n';
    }
     cerr<<1.0 * (clock()-start)/CLOCKS_PER_SEC<<endl;
     return 0;
}
