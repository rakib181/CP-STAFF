#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int ask(int i, int j){
    cout << "? " << i << ' ' << j << endl;
    int x;
    cin >> x;
    return x;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int second_max = ask(1, n);
    if(second_max != 1 and ask(1, second_max) == second_max){
        int l = 1, r = second_max;
        while((r - l) > 1){
            int m = (l + r) >> 1;
            int pos = ask(m, second_max);
            if(pos == second_max){
                l = m;
            }else{
                r = m;
            }
        }
        cout << "! " << l << endl;
    }else{
        int l = second_max, r = n;
        while((r - l) > 1){
            int m = (l + r) >> 1;
            int pos = ask(second_max, m);
            if(pos == second_max){
                r = m;
            }else{
                l = m;
            }
        }
        cout << "! " << r << endl;
    }
    return 0;
}
