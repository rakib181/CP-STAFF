#include<bits/stdc++.h>
using namespace std;
const int N = 105;
vector<int>G[N];
queue<int>q;
int indegree[N];
vector<int>v;
void bfs(int src,int n){
	for(int i=0;i<n;i++){
		if(indegree[i]==0){
			q.push(i);
		}
	}
	while(!q.empty()){
		int cur=q.front();q.pop();
        v.push_back(cur);
        for(auto it:G[cur]){
        	if(--indegree[it]==0){
        		q.push(it);
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
     int n,e;
     cin>>n>>e;
     for(int i=0;i<e;i++){
     	int x,y;
     	cin>>x>>y;
     	G[x].push_back(y);
     }    
    for(int i=0;i<n;i++){
    	for(auto it:G[i]){
    		indegree[it]++;
    	}
    }
    bfs(0,n);
    for(auto it:v){
    	cout<<it<<" ";
    }
    cout<<endl;
 	 cerr<<1.0 * (clock()-start)/CLOCKS_PER_SEC<<endl;
 	 return 0;
}
