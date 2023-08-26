#include<bits/stdc++.h>
using namespace std;
using ll = long long;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    int a[n + 1];
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    deque<int> d; vector<int> res;
    for(int i = 1; i <= min(n, k); i++){
        int val = a[i];
        while(!d.empty() and val <= a[d.back()]){
            d.pop_back();
        }
        d.push_back(i);
    }
    res.push_back(a[d.front()]);
    for(auto v : d){
        cout << v << ' ';
    }
    cout << "\n";
    for(int i = k + 1; i <= n; i++){
        int val = a[i];
        while(!d.empty() and val <= a[d.back()]){
            d.pop_back();
        }
        d.push_back(i);
        while(!d.empty() and i - k + 1 > d.front()){
            d.pop_front();
        }
        res.push_back(a[d.front()]);
    }
    for(int re : res){
        cout << re << ' ';
    }
    return 0;
}
