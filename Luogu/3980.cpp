#include<bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
int n,m,s,t,dis[110000];
int edgenum=1,vet[810000],val[810000],flw[810000],Next[810000],Head[110000];
int head,tail,que[110000]; bool vis[110000];
void addedge(int u,int v,int f,int w){
    vet[++edgenum]=v; val[edgenum]=w; flw[edgenum]=f;
    Next[edgenum]=Head[u];
    Head[u]=edgenum;
}
void Add(int u,int v,int f,int w){
    addedge(u,v,f,w);
    addedge(v,u,0,-w);
}
bool spfa(){
	for (int i=s;i<=t;i++) vis[i]=false,dis[i]=INF;
    dis[t]=0;
    vis[t]=true;
    head=1; tail=1; que[1]=t;
    int u,v;
    while (head<=tail){
        u=que[head++]; vis[u]=false;
        for (int e=Head[u];e;e=Next[e]){
            v=vet[e];
            if (dis[v]>dis[u]+val[e^1]&&flw[e^1]){
                dis[v]=dis[u]+val[e^1];
                if (!vis[v]){
                    que[++tail]=v;
                    vis[v]=true;
                }
            }
        }
    }
    return dis[s]<INF;
}
int maxflow,sum,ans;
int dfs(int u,int flow){
	vis[u]=true;
	if (u==t){
		maxflow+=flow;
		return flow;
	}
	int used=0,v;
	for (int e=Head[u];e;e=Next[e]){
		v=vet[e];
		if ((!vis[v]||v==t)&&flw[e]&&dis[v]+val[e]==dis[u]){
			int tmp=dfs(v,min(flw[e],flow-used));
			ans+=val[e]*tmp; flw[e]-=tmp; flw[e^1]+=tmp; used+=tmp;
			if (used==flow) break;
		}
	}
	return used;
}
int mincostmaxflow(){
	while (spfa()){
		vis[t]=true;
		while (vis[t]){
			for (int i=s;i<=t;i++) vis[i]=false;
			dfs(s,INF);
		}
	}
	return ans;
}
int main(){
	scanf("%d%d",&n,&m);
	s=0; t=n+2;

	Add(s,1,INF,0); Add(n+1,t,INF,0);
	int u,v,c;
	for (int i=1;i<=n;i++){
		scanf("%d",&c);
		Add(i,i+1,INF-c,0);
	}
	for (int i=1;i<=m;i++){
		scanf("%d%d%d",&u,&v,&c);
		Add(u,v+1,INF,c);
	}
	printf("%d\n",mincostmaxflow());
	return 0;
}
