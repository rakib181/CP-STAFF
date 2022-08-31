#include <bits/stdc++.h>
using namespace std;

int find_max(int ar[], int n){
    int mx = ar[0];
    for(int i = 1; i < n; i++){
        if(mx < ar[i]) mx = ar[i];
    }
    return mx;
}

void letsTry(int ar[], int n, int d){
   int cnt[10], output[n + 1];
   for(int i = 0; i < 10; i++)cnt[i] = 0;
    for(int i = 0; i < n; i++){
        cnt[(ar[i] / d) % 10]++;
    }
    for(int i = 1; i <= 10; i++){
        cnt[i] += cnt[i - 1];
    }
    for(int i = n - 1; i >= 0; i--){
        output[--cnt[(ar[i] / d ) % 10]] = ar[i];
    }
    for(int i = 0; i < n; i++){
        ar[i] = output[i];
    }
}
 void radix_sort(int ar[], int n){
    int mx = find_max(ar, n);
    int d = 1;
    while(mx / d){
        letsTry(ar, n, d);
        d *= 10;
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int ar[n];
    for(int i = 0; i < n; i++){
        cin >> ar[i];
    }
    radix_sort(ar, n);
    for(int i = 0; i < n; i++){
        cout << ar[i] << ' ';
    }
    return 0;
}


// Radix Sort Using Vector 

#include<bits/stdc++.h>
using namespace std;

void counting_sort(vector<int> &ar, int n, int d){
    vector<int> container(10, 0), output(n);
    for(int i = 0; i < n; i++){
       container[(ar[i] / d) % 10]++;
    }
    for(int i = 1; i < 10; i++){
        container[i] += container[i - 1];
    }
    for(int i = n - 1; i >= 0; i--){
        output[--container[(ar[i] / d ) % 10]] = ar[i];
    }
    for(int i = 0; i < n; i++){
     ar[i] = output[i];
   }

}

void radix_sort(vector<int> &ar, int n){
    int mx = *max_element(ar.begin(), ar.end());
    int d = 1;
    while(mx / d){
        counting_sort(ar, n, d);
        d *= 10;
    }
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
      radix_sort(ar, n);
      for(int i = 0; i < n; i++)cout << ar[i] << ' ';
      cerr<<1.0 * (clock()-start)/CLOCKS_PER_SEC<<endl;
      return 0;
}
