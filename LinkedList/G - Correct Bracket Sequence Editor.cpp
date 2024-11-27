#include <bits/stdc++.h>
using namespace std;
#define long long long

struct node{
    char ch{}; int index;
    node *prev{}, *next{};
    node()= default;
    explicit node(char ch, int index){
        this -> ch = ch;
        this -> index = index;
        this -> prev = nullptr;
        this -> next = nullptr;
    }
};

struct LinkedList{
    node *head, *tail;
     void add(char ch, int i){
        node *new_node = new node(ch, i);
        if(head == nullptr){
            head = tail = new_node;
            return;
        }
        new_node -> prev = tail;
        tail -> next = new_node;
        tail = new_node;
    }
};

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, p;
    cin >> n >> m >> p;
    string s, ins;
    cin >> s >> ins;
    s = '$' + s;
    ins = '$' + ins;
    LinkedList ls{};
    ls.add('$', 0);
    stack<node *> st;
    node *pt;
    vector<node *> prev(n + 1), next(n + 1);
    for(int i = 1; i <= n; i++){
        ls.add(s[i], i);
        if(s[i] == '('){
            st.emplace(ls.tail);
        }else{
            prev[i] = st.top();
            st.pop();
        }
        if(i == p){
            pt = ls.tail;
        }
    }
    node *t = ls.tail;
    for(int i = n; i >= 1; i--){
        if(s[i] == ')'){
            st.emplace(t);
        }else{
            next[i] = st.top();
            st.pop();
        }
        t = t -> prev;
    }
    ls.add('$', n);
    for(int i = 1; i <= m; i++){
         if(ins[i] == 'L'){
             if(pt -> prev -> ch != '$') {
                 pt = pt->prev;
             }
         }else if(ins[i] == 'R'){
             if(pt -> next -> ch != '$') {
                 pt = pt->next;
             }
         }else{
             if(pt -> ch == '('){
                 node *x = pt -> prev;
                 int j = pt -> index;
                 node *y = next[j] -> next;
                 x -> next = y;
                 y -> prev = x;
                 if(y -> ch == '$'){
                     pt = x;
                 }else{
                     pt = y;
                 }
             }else{
                 node *y = pt -> next;
                 int j = pt -> index;
                 node *x = prev[j] -> prev;
                 x -> next = y;
                 y -> prev = x;
                 if(y -> ch == '$'){
                     pt = x;
                 }else{
                     pt = y;
                 }
             }
         }
    }
    pt = ls.head;
    while (pt != nullptr){
        if(pt -> ch != '$'){
            cout << pt -> ch;
        }
        pt = pt -> next;
    }
    return 0;
}
