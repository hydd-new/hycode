#include<bits/stdc++.h>
using namespace std;
int n,m,x,ans,tot[310];
bool vis[310];
queue<int> que[310];
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			scanf("%d",&x);
			if (j==1) tot[x]++;
			que[i].push(x);
		}
	}
	int mx=0,j=0;
	for (int i=1;i<=m;i++)
		if (tot[i]>mx){ mx=tot[i]; j=i;}
	ans=mx; vis[j]=true;
	for (int k=1;k<m;k++){
		for (int i=1;i<=n;i++)
			if (que[i].front()==j){
				que[i].pop();
				while (vis[que[i].front()]) que[i].pop();
				tot[que[i].front()]++;
			}
		mx=0; j=0;
		for (int i=1;i<=m;i++)
			if (!vis[i]&&tot[i]>mx){ mx=tot[i]; j=i;}
		ans=min(ans,mx); vis[j]=true;
	}
	printf("%d\n",ans);
	return 0;
}