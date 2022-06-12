#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> vec[210000];
int dfs(int u,int f){
	int res=0;
	for (int v:vec[u]){
		if (v==f) continue;
		res^=dfs(v,u)+1;
	}
	return res;
}
int main(){
	scanf("%d",&n); int u,v;
	for (int i=1;i<n;i++){
		scanf("%d%d",&u,&v);
		vec[u].push_back(v);
		vec[v].push_back(u);
	}
	puts(dfs(1,0)?"Alice":"Bob");
	return 0;
}