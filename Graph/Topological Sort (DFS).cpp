#include<bits/stdc++.h>
using namespace std;
const int N = 105;
vector<int>G[N];
stack<int>st;
bool vis[N+1];

void dfs(int src){
	vis[src]=1;
	for(auto it:G[src]){
		if(!vis[it]){
		dfs(it);
	  }
	}
	st.push(src);
}

int32_t main(){
	 ios_base::sync_with_stdio(0);
 	 cin.tie(0); 
 	 #ifndef ONLINE_JUDGE 
 	 freopen("input.txt","r",stdin); 
 	 freopen("output.txt","w",stdout); 
 	 #endif
 	 auto start=clock();
     int n,e;
     cin>>n>>e;
     for(int i=0;i<e;i++){
     	int x,y;
     	cin>>x>>y;
     	G[x].push_back(y);
     }
     for(int i=0;i<n;i++){
     	if(!vis[i]){
     	dfs(i);
     }
     }
     while(!st.empty()){
     	cout<<st.top()<<" ";
     	st.pop();
     }
 	 cerr<<1.0 * (clock()-start)/CLOCKS_PER_SEC<<endl;
 	 return 0;
}
