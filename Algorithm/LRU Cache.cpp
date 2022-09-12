#include<bits/stdc++.h>
using namespace std;

class Node{
  public :
  string key;
  int value;
  Node(string key, int value){
    this -> key = key;
    this -> value = value;
  }
};

class LRU{
  public :
  int maxSize;
  list<Node> l;
  unordered_map<string, list<Node> :: iterator> m;
  LRU(int maxSize){
    this -> maxSize = maxSize > 1 ? maxSize : 1;
  }

  void insertKeyVal(string key, int value){
      if(m.count(key) != 0){
        auto it = m[key];
        it -> value = value;
      }else{
        if(l.size() == maxSize){
            Node x = l.back();
            l.pop_back();
             m.erase(x.key);
        }
        Node nw(key, value);
        l.push_front(nw);
        m[key] = l.begin();
      }
  }
  int* getValue(string key){
       if(m.count(key) != 0){
        auto it = m[key];
        l.push_front(*it);
        l.erase(it);
        m[key] = l.begin();
        return &l.begin() -> value;
       }
       return NULL;
  }
  string mostRecentKey(){
      return l.front().key;
  }
};

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    LRU lru(3);
    lru.insertKeyVal("Mango", 10);
    lru.insertKeyVal("Apple", 20);
    lru.insertKeyVal("Guava", 30);
    cout << lru.mostRecentKey() << '\n';
    lru.insertKeyVal("Banana", 20);
    if(lru.getValue("Mango") == NULL){
        cout << "Mango doesn't exist !" << '\n';
    }else cout << *lru.getValue("Mango") << '\n';
    return 0;
}
