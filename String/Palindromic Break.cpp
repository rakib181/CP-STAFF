#include<bits/stdc++.h>
using namespace std;

int32_t main(){
     ios_base::sync_with_stdio(0);
      cin.tie(0); 
      #ifndef ONLINE_JUDGE 
      freopen("input.txt","r",stdin); 
      freopen("output.txt","w",stdout); 
      #endif
      auto start=clock();
      string pal;
      cin >> pal;
      if(pal.size() == 1) {
        cout << "" << '\n';
        return 0;
      }
      map<int, vector<int>> mp; int firtsOcc = -1;
      for(int i = 0; i < pal.size(); i++){
        mp[pal[i] - 'a'].push_back(i);
        if(firtsOcc == -1 && pal[i] != 'a'){
            firtsOcc = i;
        }
      }
      if(mp[0].size() >= pal.size() - 1){
        pal[mp[0][mp[0].size() - 1]] = 'b';
      }else pal[firtsOcc] = 'a';
      cout << pal << '\n';
      cerr<<1.0 * (clock()-start)/CLOCKS_PER_SEC<<endl;
      return 0;
}
