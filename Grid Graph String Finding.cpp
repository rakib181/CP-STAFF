#include<bits/stdc++.h>
using namespace std;
int dx[8]={-1, 1, 0, 0, -1, -1, 1, 1};
int dy[8]={0, 0, -1, 1, -1, 1, -1, 1};
bool vis[3][4];  bool ok = false;
void dfs(string s, char ch[3][4], int x, int y , int k = 1, int ans = 0){
  if(x<0 || x>=3) return;
  if(y<0 || y>=4) return;
  if(!vis[x][y]){
    vis[x][y] = true;
    ans++;
    for(int i=0;i<8;i++){  
      int _x = x + dx[i]; int _y = y + dy[i];
      if(!vis[_x][_y] && s[k] == ch[_x][_y]){
        dfs(s, ch, _x, _y, k+1, ans);
      }
    }
  }
  vis[x][y] = false;
  if(ans == s.size()){ok = true;}
  return;
}

bool found(string s, char ch[3][4]){
 bool fou = false, br= false;
 for(int i = 0;i < 3; i++){
  for(int j = 0;j < 4; j++){
    if(ch[i][j] == s[0]){
     dfs(s, ch, i, j);
     br = true;
     break;
    }
  }
  if(ok){fou = true;break;}
}
 ok = false;
 return fou;
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
    string s[8] = {"SNAKE", "FOR", "QUEZ", "SNACK", "SNACKS", "SENS", "TUNES", "CAT"};
    char ch[3][4] = {{'S', 'E', 'R', 'T'}, {'U', 'N', 'K', 'S'}, {'T', 'C', 'A', 'T'}};
    for(int i = 0;i < 8; i++){
      if(found(s[i], ch)){
        cout << s[i] << ' ';
      }
    }
    cerr<<1.0 * (clock()-start)/CLOCKS_PER_SEC<<endl;
    return 0;
}
