#include<bits/stdc++.h>
using namespace std;

struct info
{
    int xi, ai, idx;

    bool operator < (info p) const{
         return ai <= p.ai;
    } 
};

struct node{
    node *t[2];
};

class Trie{
    private : node *root;

    public :
    Trie(){
        root = new node();
    }

    void add(int num){
        node *tmp = root;
        for(int i = 31; i >= 0; i--){
            int bit = (num >> i ) & 1;
            if(tmp -> t[bit] == 0){
                tmp -> t[bit] = new node();
            }
            tmp = tmp -> t[bit];
        }
    }
    int getMax(int num){
        node *tmp = root;
        int maxNum = 0;
        for(int i = 31; i >= 0; i--){
            int bit = (num >> i) & 1;
            if(tmp -> t[1 - bit] != 0){
                maxNum |= (1 << i);
                tmp = tmp -> t[1 - bit];
            }else{
                tmp = tmp -> t[bit];
            }
        }
        return maxNum;
    }

}tt;

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    vector<int> ar(n);
    for(int i = 0; i < n; i++){
        cin >> ar[i];
    }
    sort(ar.begin(), ar.end());
    vector<info> query(q);
    for(int i = 0; i < q; i++){
        int xi, ai;
        cin >> xi >> ai;
        query[i].xi = xi;
        query[i].ai = ai;
        query[i].idx = i;
    }
    sort(query.begin(), query.end());
    int k = 0;
    vector<int> ans(q);
    for(int i = 0; i < q; i++){
       while(k < n && ar[k] <= query[i].ai){
        tt.add(ar[k]);
        k++;
       }
       if(k == 0)ans[query[i].idx] = -1;
       else ans[query[i].idx] = tt.getMax(query[i].xi);
    }
    for(int i = 0; i < q; i++){
        if(!ans[i])cout << "-1" << ' ';
        else cout << ans[i] << ' ';
    }
    cout << '\n';
    return 0;
}
