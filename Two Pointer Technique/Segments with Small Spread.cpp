#include <bits/stdc++.h>
using namespace std;
#define int long long int

int k;
class Stack{
public:
    vector<int> s, s_min = {LONG_LONG_MAX}, s_max = {LONG_LONG_MIN};
    void push(int x){
        s.push_back(x);
        s_min.push_back(min(s_min.back(), x));
        s_max.push_back(max(s_max.back(), x));
    }
    int pop(){
        int res = s.back();
        s.pop_back();
        s_min.pop_back();
        s_max.pop_back();
        return res;
    }
    bool isEmpty() const{
        return s.empty();
    }
    int get_min(){
        return s_min.back();
    }
    int get_max(){
        return s_max.back();
    }
};

Stack s1, s2;

void ADD(int x){
   s2.push(x);
}
void REMOVE(){
    if(s1.isEmpty()){
        while (!s2.isEmpty()){
            s1.push(s2.pop());
        }
    }
    s1.pop();
}
bool GOOD(){
    int mn = min(s1.get_min(), s2.get_min());
    int mx = max(s1.get_max(), s2.get_max());
    return mx - mn <= k;
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
            REMOVE();
            l++;
        }
        ans += r - l + 1;
    }
    cout << ans << '\n';

    return 0;
}
