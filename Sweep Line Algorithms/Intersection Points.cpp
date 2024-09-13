#include<bits/stdc++.h>
using namespace std;
#define long long long int

const int inf = 1e6, N = 2e6 + 9;
int f[N];

void add(int i, int v){
    while(i < N){
        f[i] += v;
        i += (i & -i);
    }
}

int query(int i){
    int sum = 0;
    while(i > 0){
        sum += f[i];
        i -= (i & -i);
    }
    return sum;
}

int query(int l, int r){
    return query(r) - query(l - 1);
}

struct item{
    int type, a, l, r;
    bool operator < (item &other) const{
        return this -> a < other.a;
    }
};
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<item> a;
    for(int i = 0; i < n; i++){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if(x1 == x2){
            a.push_back({1, y1, x1 + inf, inf});
            a.push_back({2, y2, x1 + inf, inf});
        }else{
            a.push_back({3, y1, x1 + inf, x2 + inf});
        }
    }
    long ans = 0;
    sort(a.begin(), a.end());
    for(auto [type, _, l, r] : a){
        if(type == 1){
            add(l, +1);
        }else if(type == 2){
            add(l, -1);
        }else{
            ans += query(l, r);
        }
    }
    cout << ans;
    return 0;
}
