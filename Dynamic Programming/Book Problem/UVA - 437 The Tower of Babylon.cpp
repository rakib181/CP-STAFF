#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 100;
struct node{
    int x, y, h;

    bool operator < (node &other) const{
        if(x == other.x){
            return y < other.y;
        }
        return x < other.x;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, cs = 1;
    while(cin >> n and n > 0){
        vector<node> block;
        for(int i = 1; i <= n; i++){
            int x, y, h;
            cin >> x >> y >> h;
            if(x > y) swap(x, y);
            if(x > h)swap(x, h);
            if(y > h)swap(y, h);
            block.push_back({x, y, h});
            block.push_back({x, h, y});
            block.push_back({y, h, x});
        }
        sort(block.begin(), block.end());
        int sz = (int) block.size();
        vector<int> dp(sz, 0);
        for(int i = 0; i < sz; i++){
            dp[i] = block[i].h;
        }
        for(int i = 0; i < sz; i++){
            for(int j = i + 1; j < sz; j++){
                if(block[i].x < block[j].x and block[i].y < block[j].y){
                    dp[j] = max(dp[j], dp[i] + block[j].h);
                }
            }
        }
        cout << "Case " << cs++ << ": maximum height = " << *max_element(dp.begin(), dp.end()) << '\n';
    }
    return 0;
}
