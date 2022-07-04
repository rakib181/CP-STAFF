#include<bits/stdc++.h>
using namespace std;

void findSubset(char *input, char *output, int i, int j){
  if(input[i] == '\0'){                                                                                                                                                                                                                                                     
    output[j] = '\0';
    if(output[0] == '\0'){
      cout << "NULL" << '\n';
    }else{
    cout << output << '\n';
  }
    return;
  }
  output[j] = input[i];        
  findSubset(input, output, i + 1, j + 1);
  findSubset(input, output, i + 1, j);
}

int32_t main(){
   ios_base::sync_with_stdio(0);
    cin.tie(0); 
    #ifndef ONLINE_JUDGE 
    freopen("input.txt","r",stdin); 
    freopen("output.txt","w",stdout); 
    #endif
    auto start=clock();
    char input[100], output[100];
    cin >> input;

    findSubset(input, output, 0, 0);
    cerr<<1.0 * (clock()-start)/CLOCKS_PER_SEC<<endl;
    return 0;
}
