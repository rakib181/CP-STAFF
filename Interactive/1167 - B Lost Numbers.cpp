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
    vector<int> p = {4, 8, 15, 16, 23, 42};
    vector<int> ans(6);
    for(int i = 0; i < 4; i++){
        ans[i] = ask(i + 1, i + 2);
    }
    do{
        bool fine = true;
       for(int i = 0; i < 4; i++){
           fine &= (p[i] * p[i + 1]) == ans[i];
       }
       if(fine)break;
    }while(next_permutation(p.begin(), p.end()));
    cout << "! ";
    for(int i = 0; i < 6; i++){
        cout << p[i] << ' ';
    }
    cout << endl;
    return 0;
}
