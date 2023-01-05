#include<bits/stdc++.h>
using namespace std;
#define int long long int

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    auto possible = [&] (int x){
        if(2 * x + 1 > n)return false;
        vector<int> t;
        int id1 = 0, id2 = n - (x + 1);
        for(int i = 0; i < 2 * x + 1; i++){
          if(!(i & 1))t.push_back(a[id2++]);
          else t.push_back(a[id1++]);
        }
        for(int i = 1; i < (int) t.size(); i += 2){
            if((t[i] >= t[i - 1]) or (t[i] >= t[i + 1]))return false;
        }
        return true;
    };
    int l = 0, r = n + 1, idx = 0;
    while (l <= r){
        int mid = (l + r) >> 1;
        if(possible(mid)){
            idx = mid;
            l = mid + 1;
        }else r = mid - 1;
    }
    vector<int> fin;
    int id1 = 0, id2 = n - (idx + 1);
    for(int i = 0; i < 2 * idx + 1; i++){
        if(i & 1)fin.push_back(a[id1++]);
        else fin.push_back(a[id2++]);
    }
    while (id1 < n - (idx + 1)){
        fin.push_back(a[id1++]);
    }
    cout << idx << '\n';
    for(auto x : fin){
        cout << x << ' ';
    }
    return 0;
}
