#include<bits/stdc++.h>
using namespace std;

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
     int ar[n+1];
     int p_sum[n+1];
     for(int i=1;i<=n;i++){
     	cin>>ar[i];
     }
     p_sum[0]=0;
     for(int i=1;i<=n;i++){
     	p_sum[i]=ar[i]+p_sum[i-1];
     }
     int q;
     cin>>q;
     while(q--){
     	int l,r;
     	cin>>l>>r;
     	cout<<p_sum[r]-p_sum[l-1]<<'\n';
     }  
 	 cerr<<1.0 * (clock()-start)/CLOCKS_PER_SEC<<endl;
 	 return 0;
}
