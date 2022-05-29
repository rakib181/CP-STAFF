#include<bits/stdc++.h>
using namespace std;

vector<int> createLps(string pattern){
   vector<int>lps(pattern.size());
   int index=0;
   for(int i=1;i<pattern.size();){
   	 if(pattern[index]==pattern[i]){
   	 	lps[i]=index+1;
   	 	index++;i++;
   	 }else{
   	 	if(index != 0) index=lps[index-1];
   	 	else lps[index]=index,i++;
   	 }
   }
   return lps;
}

void KMP(string text,string pattern){
	vector<int>lps=createLps(pattern);
	int i=0,j=0;bool ok=false;
	while(i<text.size()){
		if(text[i]==pattern[j]){
			i++;j++;
		}else{
			if(j != 0) j=lps[j-1];
			else i++;
		}
		if(j==pattern.size()){
           cout<<"Found ! at -> "<<(i-pattern.size()+1)<<'\n';
           ok=true;
	}
}
	if(!ok)cout<<"Not Found !"<<'\n';
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
     string text,pattern;
     getline(cin,text);
     getline(cin,pattern);
     KMP(text,pattern);
     cerr<<1.0 * (clock()-start)/CLOCKS_PER_SEC<<endl;
 	 return 0;
}

