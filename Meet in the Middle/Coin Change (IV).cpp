#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N = 20;
vector<int> comb_1, a, b;
map<int, bool> comb_2;

void backTrack(int pos, int sum, int cs){
    if(pos >= (int) a.size() and cs == 1){
        comb_1.push_back(sum);
        return;
    }
    if(pos >= (int) b.size() and cs == 2){
        comb_2[sum] = true;
        return;
    }
    int num;
    if(cs == 1){
        num = a[pos];
    }else num = b[pos];

    backTrack(pos + 1, sum, cs);
    backTrack(pos + 1, sum + num, cs);
    backTrack(pos + 1, sum + 2 * num, cs);
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt, cs = 1;
    cin >> tt;
    while (tt--){
        cout << "Case " << cs++ << ": ";
        int n, k;
        cin >> n >> k;
        for(int i = 0; i < n / 2; i++){
            int x;
            cin >> x;
            a.push_back(x);
        }
        for(int i = n / 2; i < n; i++){
            int x;
            cin >> x;
            b.push_back(x);
        }
        backTrack(0, 0, 1);
        backTrack(0, 0, 2);
        bool ok = false;
        for(int i = 0; i < (int) comb_1.size(); i++){
            int x = comb_1[i];
            int need = k - x;
            if(comb_2[need]){
               ok = true;
               break;
            }
        }
        cout << (ok ? "Yes" : "No") << '\n';
        a.clear();
        b.clear();
        comb_1.clear();
        comb_2.clear();
    }
    return 0;
}
