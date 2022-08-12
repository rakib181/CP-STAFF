#include<bits/stdc++.h>
using namespace std;

struct node
{
node *t[26];
};

class Trie{
  private : node *root;

  public :
    Trie(){
        root = new node();
    }

    int countDistinctSub(string s){
        int cnt = 0;
        for(int i = 0; i < s.size(); i++){
            node *tmp = root;
            for(int j = i; j < s.size(); j++){
                if(tmp -> t[s[i] - 'a'] == 0){
                    cnt++;
                    tmp -> t[s[i] - 'a']  = new node();
                }
                tmp = tmp -> t[s[i] - 'a'];
            }
        }
        return cnt + 1;
    }
}tt;

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    cout << tt.countDistinctSub(s) << '\n';
    return 0;
}
