#include<bits/stdc++.h>
using namespace std;
const int N=105;
vector<pair<int,int>>G[N];
bool vis[N];

int MST(){
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
	pq.push({0,0});int ans=0;
	while(!pq.empty()){
		pair<int,int>cur=pq.top();
         int v=cur.second;
         pq.pop();
         if(!vis[v]){
         	vis[v]=true;
         	ans+=cur.first;
         	for(auto it:G[v]){
         		if(!vis[it.second]){
         			pq.push(it);
         		}
         	}
         }
	}
	return ans;
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
      	int x,y,wt;
      	cin>>x>>y>>wt;
      	G[x].push_back({wt,y});
      	G[y].push_back({wt,x});
      }
      cout<<MST()<<endl;
 	 cerr<<1.0 * (clock()-start)/CLOCKS_PER_SEC<<endl;
 	 return 0;
}
