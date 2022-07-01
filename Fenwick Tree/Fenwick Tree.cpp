#include<bits/stdc++.h>
using namespace std;
 struct fenwick
{
  vector<int>fn;
  int n;
  void init(int n){
   this->n=n;
   fn.resize(this->n,0);
  } 

  void add(int x,int val){
   ++x;
   while(x<n){
      fn[x]+=val;
      x +=x & (-x);
   }
  }
  int sum(int x){
   ++x;int sum=0;
   while(x){
     sum+=fn[x];
     x-=x&(-x);
   }
   return sum;
  }
  int sum(int l,int r){
   l--;r--;
   return sum(r)-sum(l-1);
  }
};
int32_t main(){
   ios_base::sync_with_stdio(0);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    auto st=clock();
    vector<int> fen={10,2,3,4,51,6,7,8,9,10};
     fenwick tree;
     tree.init(fen.size());
   for(int i=0;i<fen.size();i++){
      tree.add(i,fen[i]);
    }
   cout<<tree.sum(3,7);
   cerr<< 1.0 * (clock()-st)/CLOCKS_PER_SEC<<'\n';
   return 0;
}
