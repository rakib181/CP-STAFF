#include<bits/stdc++.h>
using namespace std;

bool isValid(char ch){
return isalpha(ch) || isdigit(ch);
}

bool isPalindrome(string s,int i,int j){
	if(i>j) return 1;

	if(!isValid(s[i])){
		return isPalindrome(s,i+1,j);
	}
	if(!isValid(s[j])){
		return isPalindrome(s,i,j-1);
	}

	if(s[i]==s[j]){
		return isPalindrome(s,i+1,j-1);
	}
	return 0;
}

int32_t main(){
	 ios_base::sync_with_stdio(0);
 	 cin.tie(0); 
 	 cout.tie(0);
 	 #ifndef ONLINE_JUDGE 
 	 freopen("input.txt","r",stdin); 
 	 freopen("output.txt","w",stdout); 
 	 #endif
 	 auto start=clock();
 	 string s;
 	 cin>>s;
 	 if(isPalindrome(s,0,s.size()-1)){
 	 	cout<<"YES\n";
 	 }else{
 	 	cout<<"NO\n";
 	 }
 	 cerr<<1.0 * (clock()-start)/CLOCKS_PER_SEC<<endl;
 	 return 0;
}
