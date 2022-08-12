#include<bits/stdc++.h>
using namespace std;

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
            int bit = (num >> i) & 1;
            if(tmp -> t[bit] == 0){
                tmp -> t[bit] = new node();
            }
            tmp = tmp -> t[bit];
        }
     }

     int getMax(int num){
        node *tmp = root; int maxNum = 0;
        for(int i = 31; i >= 0; i--){
           int bit = (num >> i) & 1;
           if(tmp -> t[1 - bit] != 0){
            maxNum = maxNum | (1 << i);
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
    int n, x, maxi = 0;
    cin >> n >> x;
    vector<int> ar(n);
    for(int i = 0; i < n; i++){
      cin >> ar[i];
      tt.add(ar[i]);
    }
    cout << tt.getMax(x) << '\n';
    return 0;
}
