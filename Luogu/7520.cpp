#include<bits/stdc++.h>
using namespace std;
int n,m,q;
bool vis[3100],connect[3100][3100];
vector<int> vec[3100];
char Getchar(){
	static char now[1<<20],*S,*T;
	if (T==S){
		T=(S=now)+fread(now,1,1<<20,stdin);
		if (T==S) return EOF;
	}
	return *S++;
}
int read(){
	int x=0,f=1;
	char ch=Getchar();
	while (ch<'0'||ch>'9'){
		if (ch=='-') f=-1;
		ch=Getchar();
	}
	while (ch>='0'&&ch<='9') x=x*10+ch-'0',ch=Getchar();
	return x*f;
}
void dfs(int u,int ban){
	if (u==ban||vis[u]) return; vis[u]=true;
	for (int i=0;i<(int)vec[u].size();i++) dfs(vec[u][i],ban);
}
void work(){
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++) vis[j]=false;
		dfs(1,i);
		for (int j=1;j<=n;j++) connect[i][j]=vis[j];
	}
}
void dfs2(int u,int bel){
	if (u==bel) return;
	vis[u]=true;
	for (int i=0;i<(int)vec[u].size();i++)
		if (!connect[bel][vec[u][i]]&&!vis[vec[u][i]]) dfs2(vec[u][i],bel);
}
int main(){
	n=read(); m=read(); q=read();
	int u,v;
	for (int i=1;i<=m;i++){
		u=read(); v=read();
		vec[u].push_back(v);
	}
	work();
	for (int i=1;i<=q;i++){
		u=read(); v=read();
		for (int j=1;j<=n;j++) vis[j]=false;
		for (int j=1;j<=n;j++)
			if (j!=v&&connect[j][u]&&!connect[j][v]) dfs2(v,j);
		int ans=0;
		for (int j=1;j<=n;j++)
			if (vis[j]) ans++;
		printf("%d\n",ans);
	}
	return 0;
}
