#include<bits/stdc++.h>
using namespace std;
#define int long long int

int cal(vector<int> &a, vector<int> &b, int n, int m, int s, int A, int B){
    int i = 0, j = 0, sum = 0, w = 0, ans = 0;
    while (i < n){
        if(w + A <= s){
            sum += a[i];
            w += A;
            ans = max(ans, sum);
        }else{
            break;
        }
        i++;
    }
    i--;
    while (j < m){
        if(w + B <= s){
            sum += b[j];
            w += B;
        }else{
            int k = i;
            while (k >= 0 and w + B > s){
                sum -= a[k];
                k--;
                w -= A;
            }
            if(w + B <= s){
                w += B;
                sum += b[j];
            }
            i = k;
        }
        ans = max(ans, sum);
        j++;
    }
    return ans;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, s, A, B;
    cin >> n >> m >> s >> A >> B;
    vector<int> a(n), b(m);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < m; i++){
        cin >> b[i];
    }
    sort(a.rbegin(), a.rend());
    sort(b.rbegin(), b.rend());
    int a1 = cal(a, b, n, m, s, A, B);
    int a2 = cal(b, a, m, n, s, B, A);
    cout << max(a1, a2)  << '\n';
    return 0;
}
