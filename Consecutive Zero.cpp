#include<bits/stdc++.h>
using namespace std;

int *a,n;

int letsTry(){
  int prevCnt=0,curCnt=1,maxLen=0;bool ok =false;
  for(int i=1;i<n;i++){
    if(a[i]==0 && a[i-1]==0){
      ok=true;
      curCnt++;
    }else{
      prevCnt=curCnt;
      curCnt=1;
    }
    maxLen=max(maxLen,prevCnt);
  }
  if(!ok)return 0;
  return max(maxLen,curCnt);
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
    cin >> n;
    a=new int[n];
    for(int i=0;i<n;i++)cin >> a[i];
      cout << letsTry() <<'\n';
    cerr<<1.0 * (clock()-start)/CLOCKS_PER_SEC<<endl;
    return 0;
}
