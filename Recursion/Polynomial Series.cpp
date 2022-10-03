#include <bits/stdc++.h>
using namespace std;

void rec(int n){
  if(n == 0){
      cout << "1 ";
      return;
  }
  rec(n - 1);
  if(n != 1)cout << "+ x" << "^" << n << ' ';
  else cout << "+ x ";
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    rec(n - 1);
    return 0;
}
