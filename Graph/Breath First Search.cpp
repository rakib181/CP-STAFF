#include<bits/stdc++.h>
using namespace std;
const int N=105;
vector<int>G[N];
int lvl[N];
bool vis[N];

void bfs(int src){
	queue<int>q;
	q.push(src);
	vis[src]=true;
	lvl[src]=0;
	while(!q.empty()){
		int v=q.front();
		cout<<v<<" ";
		vis[v]=true;
		q.pop();
	   for(auto it:G[v]){
	   	if(!vis[it]){
	   		lvl[it]=lvl[v]+1;
	   		q.push(it);
	      }
	    }
	}
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
      int n,e;
      cin>>n>>e;
      for(int i=0;i<e;i++){
      	int x,y;
      	cin>>x>>y;
      	G[x].push_back(y);
      }
      bfs(2);
      cout<<endl;
      for(int i=0;i<n;i++){
      	cout<<lvl[i]<<" ";
      }
 	 cerr<<1.0 * (clock()-start)/CLOCKS_PER_SEC<<endl;
 	 return 0;
}
