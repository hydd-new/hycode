#include<bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> pii;
int T,n,m,dis[2][210000];
int head,tail; pii que[210000];
int cnt; pii s[210000];
vector<int> vec[110000];
map<int,int> tot[110000],num[110000];
void bfs(){
	for (int i=1;i<=n;i++) dis[0][i]=dis[1][i]=INF;
	head=1; tail=1; que[1]=pii(1,0); dis[0][1]=0;
	int u,d;
	while (head<=tail){
		u=que[head].first; d=que[head].second; head++;
		for (int v:vec[u])
			if (dis[d^1][v]>dis[d][u]+1){
				dis[d^1][v]=dis[d][u]+1;
				que[++tail]=pii(v,d^1);
			}
	}
}
int main(){
	scanf("%d",&T);
	while (T--){
		scanf("%d%d",&n,&m); int u,v;
		for (int i=1;i<=m;i++){
			scanf("%d%d",&u,&v);
			vec[u].push_back(v);
			vec[v].push_back(u);
		}
		bfs();
		if (dis[1][1]==1){//特判1号点自环
			for (int i=0;i<=n+1;i++) vec[i].clear();
			printf("%d\n",n); continue;
		}
		if (dis[1][1]==INF){
			for (int i=0;i<=n+1;i++) vec[i].clear();
			printf("%d\n",n-1); continue;
		}
		int x,y; cnt=0;
		for (int i=1;i<=n;i++){
			x=dis[0][i]; y=dis[1][i];
			if (x>y) swap(x,y);
			if (!tot[x][y]) tot[x][y]=1,s[++cnt]=pii(x+y,x);
			else tot[x][y]++;
		}
		sort(s+1,s+cnt+1); int ans=0,now,lst;
		for (int i=1;i<=cnt;i++){
			x=s[i].second; y=s[i].first-s[i].second;
			if (!x) continue;
			now=tot[x][y]; lst=num[x-1][y+1];
			ans+=max(now-lst,0);
			if (tot[x-1][y-1]) now=min(now,lst);
			if (x+1<y){
				num[x][y]=now;
				ans+=now;
			} else ans+=(now+1)>>1;
		}
		printf("%d\n",ans);
		for (int i=0;i<=n+1;i++){
			vec[i].clear();
			tot[i].clear();
			num[i].clear();
		}
	}
	return 0;
}
