#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 25;
int n, board[N][N];

void print(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }
}

bool can_place(int x, int y){
    for(int i = 0; i < x; i++){
        if(board[i][y])return false;
    }
    int i = x - 1, j = y - 1;
    while(i >= 0 and j >= 0){
        if(board[i][j])return false;
        i -= 1, j -= 1;
    }
    i = x - 1, j = y + 1;
    while(i >= 0 and j < n){
        if(board[i][j])return false;
        i -= 1, j += 1;
    }
    return true;
}

bool N_QUEEN(int i){
    if(i == n){
        print();
        cout << '\n';
        return true;
    }
    for(int j = 0; j < n; j++){
        if(can_place(i, j)){
            board[i][j] = 1;
            if(N_QUEEN(i + 1)){
                return true;
            }
            board[i][j] = 0;
        }
    }
    return false;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    N_QUEEN(0);
    return 0;
}
