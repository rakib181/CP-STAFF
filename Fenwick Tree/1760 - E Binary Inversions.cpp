#include <bits/stdc++.h>
using namespace std;

#define int long long int

struct fenwick
{
    vector<int>fn;
    int n;
    fenwick(){}
    fenwick(int n){
        init(n);
    }
    void init(int _n){
        n=_n+10;
        fn.clear();
        fn.resize(n,0);
    }
    void add(int x,int val){
        x++;
        while(x<n){
            fn[x]+=val;
            x +=x & (-x);
        }
    }
    int sum(int x){
        x++;int sum=0;
        while(x){
            sum+=fn[x];
            x-=x&(-x);
        }
        return sum;
    }
    int sum(int l,int r){
        return sum(r)-sum(l-1);
    }
};

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        fenwick tree1(n + 1), tree2(n + 1), tree3(n + 1);
        vector<pair<int, int>> ar(n), br(n), cr(n);
        for(int i = 0; i < n; i++){
            cin >> ar[i].first;
            ar[i].second = i;
        }
        br = ar;
        cr = ar;
        for(int i = 0; i < n; i++){
            if(!ar[i].first){
                ar[i].first = 1;
                break;
            }
        }
        for(int i = n - 1; i >= 0; i--){
            if(br[i].first){
                br[i].first = 0;
                break;
            }
        }
        sort(ar.begin(), ar.end());
        sort(br.begin(), br.end());
        sort(cr.begin(), cr.end());
        int inv_cnt1 = 0, inv_cnt2 = 0, inv_cnt3 = 0;
        for(int i=0;i<n;i++){
            int idx=ar[i].second;
            inv_cnt1 += tree1.sum(idx+1,n-1);
            tree1.add(idx,1);
        }
        for(int i=0;i<n;i++){
            int idx=br[i].second;
            inv_cnt2 += tree2.sum(idx+1,n-1);
            tree2.add(idx,1);
        }
        for(int i=0;i<n;i++){
            int idx=cr[i].second;
            inv_cnt3 += tree3.sum(idx+1,n-1);
            tree3.add(idx,1);
        }
        cout << max({inv_cnt1, inv_cnt2, inv_cnt3}) << '\n';
    }
    return 0;
}
