#include<bits/stdc++.h>
using namespace std;
const int N=2e5+9;
int a[N];

void mergesort(int l,int r){
  if(l>=r) return;
  int mid=(l+r)/2;
  mergesort(l,mid);
  mergesort(mid+1,r);
  vector<int>L,R;
  for(int i=l;i<=mid;i++){
    L.push_back(a[i]);
  }
  for(int i=mid+1;i<=r;i++){
    R.push_back(a[i]);
  }
  int Lid=0,Rid=0,k=l;
  while(Lid<(int)L.size() || (int)Rid<R.size()){
   if(Rid==(int)R.size() || (Lid<(int)L.size() && L[Lid]<R[Rid])){
    a[k++]=L[Lid++];
   }else{
    a[k++]=R[Rid++];
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
    int n,x=0;
    while(cin >> n){
      a[++x]=n;
    }
    mergesort(1,x);
  for(int i=1;i<=x;i++){
    cout << a[i] << ' ';
  }
    cerr<<1.0 * (clock()-start)/CLOCKS_PER_SEC<<endl;
    return 0;
}
