#include <bits/stdc++.h>
using namespace std;
#define int long long int

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, s;
    cin >> n >> s;
    vector<int> ar(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> ar[i];
    }
    int ans = 0, l = 1; map<int, int> mp;
    for(int r = 1; r <= n; r++){
        mp[ar[r]]++;
        while ((int) mp.size() > s){
             mp[ar[l]]--;
             if(!mp[ar[l]]){
                 mp.erase(ar[l]);
             }
             l++;
        }
        ans += (r - l + 1);
    }
    cout << ans << '\n';

    return 0;
}

// ANOTHER WAY
#include <bits/stdc++.h>
using namespace std;
#define int long long int
const int N = 1e5 + 9;
vector<int> cnt(N, 0);
int num = 0, k;

void ADD(int x){
   cnt[x]++;
   if(cnt[x] == 1){
       num++;
   }
}
void REMOVE(int x){
   cnt[x]--;
   if(!cnt[x])num--;
}
bool GOOD(){
    return  num <= k;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n >> k;
    vector<int> ar(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> ar[i];
    }
    int l = 1, ans = 0;
    for(int r = 1; r <= n; r++){
        ADD(ar[r]);
        while (!GOOD()){
            REMOVE(ar[l++]);
        }
        ans += r - l + 1;
    }
    cout << ans << '\n';

    return 0;
}
