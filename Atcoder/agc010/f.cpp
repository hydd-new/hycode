#include<cstdio>
using namespace std;
int n,u,v,a[3100];
int edgenum,vet[6100],Next[6100],Head[3100];
void addedge(int u,int v){
	vet[++edgenum]=v;
	Next[edgenum]=Head[u];
	Head[u]=edgenum;
}
bool dfs(int u,int fa){
	for (int e=Head[u];e;e=Next[e])
		if (vet[e]!=fa&&!dfs(vet[e],u)&&a[vet[e]]<a[u]) return true;
	return false;
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<n;i++){
		scanf("%d%d",&u,&v);
		addedge(u,v); addedge(v,u);
	}
	for (int i=1;i<=n;i++)
		if (dfs(i,0)) printf("%d ",i);
	return 0;
}

