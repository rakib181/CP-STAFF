#include<bits/stdc++.h>
using namespace std;

const int MX=1e8+5;
int bitWise[MX/32+5];
vector<int>primeGen;

bool _check(int n,int i){
   if(n&(1<<i)){
      return 0;
   }
   return 1;
}
int _mark(int n,int i){
   return n | (1<<i);
}

void  _bitWise(){
   for(int i=3;i*i<=MX;i+=2){
      if(_check(bitWise[i>>5] , i&31)){
         for(int j=i*i;j<=MX;j+=i){
            bitWise[j>>5]=_mark(bitWise[j>>5],j&31);
         }
      }
   }
   primeGen.push_back(2);
   for(int i=3;i<=MX;i+=2){
      if(_check(bitWise[i>>5],i&31)){
         primeGen.push_back(i);
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
    auto st=clock();
      _bitWise();
      for(int i=0;i<primeGen.size();i++){
         cout<<primeGen[i]<<' ';
      }
   cerr<< 1.0 * (clock()-st)/CLOCKS_PER_SEC<<'\n';
   return 0;
}


// Again

#include<bits/stdc++.h>
using namespace std;
const int N = 1e8;
int status[(N >> 5)];

bool check(int n, int pos){
return  (n & (1 << pos)) < 1;
}
int Set(int n, int pos){
    return n = n | (1 << pos);
}

void bitSieve(){
    for(int i = 3; i * i <= N; i += 2){
        if(check(status[(i >> 5)], (i & 31))){
            for(int j = i * i; j <= N; j += i){
                status[(j >> 5)] = Set(status[(j >> 5)], (j & 31));
            }
        }
    }
    cout << "2 " ;
    for(int i = 3; i <= N; i += 2){
        if(check(status[(i >> 5)], (i & 31))){
           cout << i << ' ';
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
      bitSieve();
      cerr<<1.0 * (clock()-start)/CLOCKS_PER_SEC<<endl;
      return 0;
}

