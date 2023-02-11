#include <bits/stdc++.h>
using namespace std;
#define int long long int

class Mex{
public:
    map<int, int> frequency;
    set<int> missing_number;
public:
    explicit Mex(int n, vector<int> &aa){
        for(int i = 1; i <= n + 1; i++){
            missing_number.insert(i);
        }
        for(auto x : aa){
            ++frequency[x];
            missing_number.erase(x);
        }
    }
    void UPD(int x){
        frequency[x]++;
        missing_number.erase(x);
    }
    int MEX() const{
        return *missing_number.begin();
    }
};

void print(stack<int> &st){
    if(st.empty()) return;
    int x = st.top();
    st.pop();
    print(st);
    cout << x << ' ';
}

signed main(){
    int tt = 1, cs = 1;
    //cin >> tt;
    while (tt--){
        int n, m;
        cin >> n >> m;
        vector<int> a(m);
        for(int i = 0; i < m; i++){
            cin >> a[i];
        }
        Mex mx(n, a); vector<bool> used(n + 2, false);
        stack<int> st;
        while (true){
            int i = mx.MEX();
            if(i == n + 1){
                i--;
                while (i >= 1 and !used[i]){
                    used[i] = true;
                    st.push(i);
                    i--;
                }
                break;
            }else{
                mx.UPD(i);
                while (i >= 1 and !used[i]){
                    used[i] = true;
                    st.push(i);
                    i--;
                }
            }
        }
        print(st);
    }
    return 0;
}
