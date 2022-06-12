#include<bits/stdc++.h>
using namespace std;
int n,m,k,x,y;
vector<int> vec[210000];
int main(){
	scanf("%d%d%d",&n,&m,&k);
	for (int i=1;i<=k;i++){
		scanf("%d%d",&x,&y);
		vec[x].push_back(y);
	}
	x=1;
	for (int i=2;i<=n;i++){
		bool flag=true;
		for (int v:vec[i]){
			if (v>x+1) continue;
			if (v==x+1) flag=false;
			else{ printf("%d\n",i-1); return 0;}
		}
		x+=flag;
	}
	printf("%d\n",n);
	return 0;
}