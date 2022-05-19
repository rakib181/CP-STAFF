#include<bits/stdc++.h>
using namespace std;

int check(string &s){
	int min=100000007;
	for(int i=0;i<s.size();i++){
		int k=s[i]-'0';
         if(k<min){
         	min=k;
         }
	}
	return min;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
   // freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int t; 
    cin>>t;
    while(t--){
    	string s;
    	cin>>s;
    	if(s.size()==2){
    		cout<<s[1]<<endl;
    	}else{
    		cout<<check(s)<<endl;
    	}
    }
   
	return 0;
}
