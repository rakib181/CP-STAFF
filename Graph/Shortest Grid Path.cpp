#include<bits/stdc++.h>
using namespace std;

int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};

bool valid(int x, int y, int n, int m){
    if(x < 0 || y < 0 || x >= n || y >= m)return false;
    else return true;
}

class Node{
   public :
   int x, y, dist;
   Node(int x, int y, int dist){
       this -> x = x;
       this -> y = y;
       this -> dist = dist;
   }
};

class compare{
    public :
    bool operator()(const Node &a, const Node &b){
        return a.dist <= b.dist;
    }
};

int shortest_path(vector<vector<int> > grid){
    int n = grid.size(), m = grid[0].size();
    vector<vector<int> > path(n, vector<int>(m, INT_MAX));
    path[0][0] = grid[0][0];
    set<Node, compare> st;
    st.insert(Node(0, 0, path[0][0]));

    while(!st.empty()){
        auto cur = st.begin();
        int cx = cur -> x, cy = cur -> y, cd = cur -> dist;
        st.erase(cur);
        for(int i = 0; i < 4; i++){
            int nx = cx + dx[i], ny = cy + dy[i];
            if(valid(nx, ny, n, m) and cd + grid[nx][ny] < path[nx][ny]){
                Node tmp(nx, nx, path[nx][ny]);
                if(st.find(tmp) != st.end()){
                    st.erase(st.find(tmp));
                }
                path[nx][ny] = cd + grid[nx][ny];
                st.insert(Node(nx, ny, cd + grid[nx][ny]));
            }
        }
    }
    return path[n - 1][m - 1];
}

int main(){
    vector<vector<int>> grid = 
  {
      {31, 100, 64, 12, 18},
      {10, 13, 47, 157, 6},
      {100, 113, 174, 11, 33},
      {88, 124, 41, 20, 140},
      {99, 32, 111, 41, 20}
  };
  cout << shortest_path(grid) << '\n';
}
