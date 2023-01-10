#include <bits/stdc++.h>
using namespace std;

const int N = 30005, SZ = 1e5;
const int coins[6]={1,5,10,25,50};
long long dp[SZ];
int m;

int main(){
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for (int i = 0; i < 5; i++){
        for (int j = coins[i]; j <= N; j++){
            if(dp[j - coins[i]]) dp[j] += dp[j - coins[i]];
        }
    }
    while (~scanf("%d",&m))
    {
        if (dp[m] == 1){
            printf("There is only 1 way to produce %d cents change.\n", m);
        }
        else{
            printf("There are %lld ways to produce %d cents change.\n", dp[m], m);
        }
    }
    return 0;
}
