#include<bits/stdc++.h>
using namespace std;

vector<string> ans;
void helper(string &s, int idx){
    if(idx == s.size()){
       ans.push_back(s);
       return;
    }
    for(int i = idx; i < s.size(); i++){
        swap(s[i], s[idx]);
        helper(s, idx + 1);
        swap(s[i], s[idx]);
    }
}

vector<string> findSortedPermutations(string s){
     ans.clear();
     helper(s, 0);
     set<string> st;
     for(auto x : ans){
       st.insert(x);
     }
     ans.clear();
     for(auto x : st)ans.push_back(x);
  return ans;
}

int main(){
    string s = "abc";
    vector<string> ans = findSortedPermutations(s);
    for(auto x : ans){
        cout << x << ' ';
    }
}
