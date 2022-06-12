#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int n,m,c,q,f[210000][19],g[210000][19],h[210000][19],lst[210000];
int p[210000],w[210000],pos[210000],dep[210000],Ans[210000];
int edgenum,vet[410000],Next[410000],Head[210000];
vector<int> vec[210000];
vector<pii> que[210000];
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
void addedge(int u,int v){
	vet[++edgenum]=v;
	Next[edgenum]=Head[u];
	Head[u]=edgenum;
}
int find(int x){
	if (x<1||x>m||vec[x].empty()) return 0;
	return vec[x].back();
}
void dfs(int u,int fa){
	if (pos[w[u]]) vec[pos[w[u]]].push_back(u);
	f[u][0]=fa; lst[u]=find(1); dep[u]=dep[fa]+1;
	g[u][0]=find(pos[w[u]]+1);
	h[u][0]=find(pos[w[u]]-1);
	
	for (int i=1;i<=18;i++){
		f[u][i]=f[f[u][i-1]][i-1];
		g[u][i]=g[g[u][i-1]][i-1];
		h[u][i]=h[h[u][i-1]][i-1];
	}
	for (int e=Head[u];e;e=Next[e])
		if (vet[e]!=fa) dfs(vet[e],u);
	if (pos[w[u]]) vec[pos[w[u]]].pop_back();
}
int LCA(int u,int v){
	if (dep[u]<dep[v]) swap(u,v);
	int d=dep[u]-dep[v];
	for (int i=0;i<=18;i++)
		if (d&(1<<i)) u=f[u][i];
	if (u==v) return u;
	for (int i=18;i>=0;i--)
		if (f[u][i]!=f[v][i]){
			u=f[u][i];
			v=f[v][i];
		}
	return f[u][0];
}
int jump1(int u,int x){
	int res=(dep[u]>=x);
	for (int i=18;i>=0;i--)
		if (dep[g[u][i]]>=x){
			u=g[u][i];
			res+=(1<<i);
		}
	return res;
}
int jump2(int u,int x){
	int res=(dep[u]>=x);
	for (int i=18;i>=0;i--)
		if (dep[h[u][i]]>=x){
			u=h[u][i];
			res+=(1<<i);
		}
	return res;
}
void dfs2(int u,int fa){
	if (pos[w[u]]) vec[pos[w[u]]].push_back(u);
	for (int i=0;i<(int)que[u].size();i++){
		int v=que[u][i].first,w=LCA(u,v);
		int x=jump1(lst[v],dep[w]);
		int l=x-1,r=c,mid;
		while (l<r){
			mid=(l+r+1)>>1;
			if (x+jump2(find(mid),dep[w]+1)>=mid) l=mid;
			else r=mid-1;
		}
		Ans[que[u][i].second]=l;
	}
	for (int e=Head[u];e;e=Next[e])
		if (vet[e]!=fa) dfs2(vet[e],u);
	if (pos[w[u]]) vec[pos[w[u]]].pop_back();
}
int main(){
	n=read(); m=read(); c=read();
	for (int i=1;i<=m;i++) pos[i]=-1;
	for (int i=1;i<=c;i++){
		p[i]=read();
		pos[p[i]]=i;
	}
	for (int i=1;i<=n;i++) w[i]=read();
	int u,v;
	for (int i=1;i<n;i++){
		u=read(); v=read();
		addedge(u,v); addedge(v,u);
	}
	dfs(1,0);
	q=read();
	for (int i=1;i<=q;i++){
		u=read(); v=read();
		que[v].push_back(pii(u,i));
	}
	dfs2(1,0);
	for (int i=1;i<=q;i++) printf("%d\n",Ans[i]);
	return 0;
}
