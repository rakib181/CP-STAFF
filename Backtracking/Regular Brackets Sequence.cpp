#include<bits/stdc++.h>
using namespace std;

void regularseq(string output, int n, int open, int close, int i){
  if(i == 2 * n){
    cout << output << '\n';
    return;
  }
   if(open < n){
  regularseq(output += '(', n, open + 1, close, i + 1);
  output.pop_back();
 }
 if(close < open){
  regularseq(output += ')', n, open, close + 1, i + 1);
  output.pop_back();
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
    int n;
    cin >> n;
    string ot;
    regularseq(ot, n, 0, 0 , 0);
    cerr<<1.0 * (clock()-start)/CLOCKS_PER_SEC<<endl;
    return 0;
}
