#include<bits/stdc++.h>
using namespace std;

const int N = 5000000;
int tot[N + 5];
unsigned long long prefix[N + 5];

void totient(){
   for(int i = 2; i <= N; i++)tot[i] = i;

   for(int i = 2; i <= N; i++){
      if(tot[i] == i){
        for(int j = i; j <= N; j += i){
            tot[j] -= tot[j] / i;
        }
      }
   }
}

int main(){
      totient();
      prefix[1] = 0;
      for(int i = 2; i <= N; i++){
        prefix[i] = ((unsigned long long)tot[i] * (unsigned long long)tot[i]);
        prefix[i] += prefix[i - 1];
      }
      int tt, idx = 1;
      scanf("%d", &tt);
      while(tt--){
        cout << "Case " << idx++ << ": ";
        int l, r;
        scanf("%d %d", &l, &r);
        unsigned long long x = (unsigned long long) prefix[r] - (unsigned long long)prefix[l - 1];
        printf("%llu\n", x);
      }
      return 0;
}
