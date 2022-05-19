#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t; 
    cin>>t;
    while(t--){
    	long long a,b,c;
    	cin>>a>>b>>c;
    	cout<<a+(c*b)<<' '<<b<<' '<<c<<endl;
    }
	return 0;
}