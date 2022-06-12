#include<bits/stdc++.h>
using namespace std;
int n,m,u[210000],v[210000],ans,Ans[210000];
bool connect1[1100][1100],connect2[1100][1100];
int edgenum,vet1[210000],Next1[210000],Head1[1100],vet2[210000],Next2[210000],Head2[1100];
void addedge(int u,int v){
	edgenum++;
	
	vet1[edgenum]=v;
	Next1[edgenum]=Head1[u];
	Head1[u]=edgenum;
	
	vet2[edgenum]=u;
	Next2[edgenum]=Head2[v];
	Head2[v]=edgenum;
}
void dfs1(int u,int bel){
	if (u<bel||connect1[bel][u]) return;
	connect1[bel][u]=true;
	if (connect2[bel][u]) ans++;
	for (int e=Head1[u];e;e=Next1[e]) dfs1(vet1[e],bel);
}
void dfs2(int u,int bel){
	if (u<bel||connect2[bel][u]) return;
	connect2[bel][u]=true;
	if (connect1[bel][u]) ans++;
	for (int e=Head2[u];e;e=Next2[e]) dfs2(vet2[e],bel);
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++) scanf("%d%d",&u[i],&v[i]);
	for (int i=1;i<=n;i++){
		connect1[i][i]=true;
		connect2[i][i]=true;
	}
	ans=n; Ans[m]=ans;
	for (int i=m;i>=1;i--){
		for (int s=1;s<=n;s++){
			if (connect1[s][u[i]]) dfs1(v[i],s);
			if (connect2[s][v[i]]) dfs2(u[i],s);
		}
		addedge(u[i],v[i]);
		Ans[i-1]=ans;
	}
	for (int i=0;i<=m;i++) printf("%d ",Ans[i]);
	return 0;
}
