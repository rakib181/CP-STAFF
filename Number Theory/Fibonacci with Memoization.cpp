#include<bits/stdc++.h>
using namespace std;

long long save[100];
long long fibo(int n){
	if(n==0)return 0;
	if(n==1)return 1;

	if(save[n] != -1){
		return save[n];
	}
	//return with memoization
	return save[n] = fibo(n-1)+fibo(n-2);
}

int32_t main(){
	 ios_base::sync_with_stdio(0);
 	 cin.tie(0); 
 	 cout.tie(0);
 	 #ifndef ONLINE_JUDGE 
 	 freopen("input.txt","r",stdin); 
 	 freopen("output.txt","w",stdout); 
 	 #endif
 	 auto start=clock();
 	 int n;
 	 cin>>n;
 	 memset(save,-1,sizeof save);
     cout<<fibo(n)<<'\n';
 	 cerr<<1.0 * (clock()-start)/CLOCKS_PER_SEC<<endl;
 	 return 0;
}
