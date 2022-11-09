#include <bits/stdc++.h>
using namespace std;

class Vertex{
public:
    int string_ends;
    vector<int> next;
    explicit Vertex(int k){
        this -> string_ends = 0;
        this -> next.resize(k, -1);
    }
};

class Trie{
public:
    int K;
    vector<Vertex> nodes;

    explicit Trie(int k){
        this -> K = k;
        this -> nodes.emplace_back(Vertex(K));
    }

    void add(const string& s){
        int cur = 0;
        for(auto ch : s){
            if(nodes[cur].next[ch - 'a'] == -1){
                nodes[cur].next[ch - 'a'] = (int) nodes.size();
                nodes.emplace_back(Vertex(K));
            }
            cur = nodes[cur].next[ch - 'a'];
        }
        nodes[cur].string_ends++;
    }

    bool search(const string& s){
        int cur = 0;
        for(auto ch : s){
            if(nodes[cur].next[ch - 'a'] == -1){
                return false;
            }
            cur = nodes[cur].next[ch - 'a'];
        }
        return nodes[cur].string_ends > 0;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Trie T(26);
    int n, q;
    cin >> n >> q;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        T.add(s);
    }
    while(q--){
        string s;
        cin >> s;
        if(T.search(s)){
            cout << "FOUND !" << '\n';
        }else cout << "NOT FOUND !" << '\n';
    }
    return 0;
}
