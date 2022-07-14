#include<bits/stdc++.h>
using namespace std;
const  int N = 1e6;
int totient[N + 10];

void precompute(){
    for(int i = 1; i <= N; i++){
      totient[i] = i;
   }
   /*Euler Totient Function Calculation Using Formula n * (1 - 1/p1) * .... * (1 - 1/ pk)
   Where p is All Prime Factor of n.
   */
   for(int i = 2; i <= N; i++){
      if(totient[i] == i){
         totient[i] = i - 1;
         for(int j = 2 * i; j <= N; j += i){
            totient[j] *= i - 1;
            totient[j] /= i;
         }
      }
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
     precompute();
     int n;
     cin >> n;
     cout << totient[n] << '\n';    
     cerr<<1.0 * (clock()-start)/CLOCKS_PER_SEC<<endl;
     return 0;
}
