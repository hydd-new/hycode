#include<bits/stdc++.h>
using namespace std;
typedef pair<string,string> pii;
int n;
pii solve(char c,int n){
	if (n==1) return pii("",string(1,c));
	if (n==2) return pii(string(1,c),string(1,c));
	if (n&1){
		pii res=solve(c+1,(n-1)>>1);
		return pii(res.first+c+c,res.second+c);
	}
	if (!(n&1)){
		pii res=solve(c+1,(n-2)>>1);
		return pii(c+res.first+c+c,res.second+c);
	}
}
int main(){
	cin>>n; pii ans=solve('a',n);
	cout<<ans.second<<ans.first<<' '<<ans.second<<endl;
	return 0;
}
