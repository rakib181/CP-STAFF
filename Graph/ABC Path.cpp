#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N = 55;
vector<vector<char>> grid(N, vector<char> (N));
vector<vector<bool>> vis(N, vector<bool> (N));
int n, m, sz;

void CLEAR(){
    for(int i = 1; i < N; i++){
        for(int j = 1; j < N; j++){
            vis[i][j] = false;
        }
    }
}

bool valid(int x, int y, char ch){
    return x >= 1 and x <= n and y >= 1 and y <= m and grid[x][y] == ch + 1 and !vis[x][y];
}
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1}, dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
set<int> st;
void DFS(int x, int y, char ch = 'A'){
    vis[x][y] = true;
    sz++;
    for(int i = 0; i < 8; i++){
        int xx = x + dx[i], yy = y + dy[i];
        if(valid(xx, yy, ch)){
            DFS(xx, yy, ch + 1);
        }
    }
    st.insert(sz);
    sz--;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int cs = 1;
    while (true) {
        cin >> n >> m;
        if(!n and !m)break;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                grid[i][j] = '\0';
            }
        }
        cout << "Case " << cs++ << ": ";
        vector<pair<int, int>> loc;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> grid[i][j];
                if(grid[i][j] == 'A'){
                    loc.emplace_back(i, j);
                }
            }
        }
        st.insert(0);
        for(auto x : loc){
            CLEAR();
            sz = 0;
            DFS(x.first, x.second);
        }
        auto it = st.end();
        it--;
        cout << *it << '\n';
        st.clear();
    }
    return 0;
}
