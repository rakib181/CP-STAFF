#include <bits/stdc++.h>
using namespace std;

int find_max(vector<int> ar, int n){
    int mx = ar[0];
    for(int i = 1; i < n; i++){
        if(mx < ar[i])mx = ar[i];
    }
    return mx;
}

vector<int> counting_sort(vector<int> ar, int n){
    vector<int> ans (n);
    int mx = find_max(ar, n);
    vector<int> c(mx + 1, 0);
    for(int i = 0; i < n; i++){
        c[ar[i]]++;
    }
    for(int  i = 1; i <= mx; i++){
        c[i] += c[i - 1];
    }
    for(int i = n - 1; i >= 0; i--){
      ans[--c[ar[i]]] = ar[i];
    }
   return ans;
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
    vector<int> ok = counting_sort(ar, n);
    for(int i = 0; i < n; i++){
        cout << ok[i] << ' ';
    }
    return 0;
}
