#include<bits/stdc++.h>
using namespace std;
const int lim=1e6;
const int INF=0x3f3f3f3f;
int T,n,m,a[310][310],b[310][310],dis[210000];
int edgenum,vet[210000],val[210000],Next[210000],Head[1100];
int head,tail,que[210000],cnt[210000]; bool vis[210000];
void add(int v,int u,int c){//num[v]<=num[u]+c
//	printf("%c[%d]<=%c[%d]+%d\n",(v>n)+'a',(v>n?v-n:v),(u>n)+'a',(u>n?u-n:u),c);
	vet[++edgenum]=v; val[edgenum]=c;
	Next[edgenum]=Head[u]; Head[u]=edgenum;
}
inline int op(int x){ return x&1?-1:1;}
inline int nxt(int x){ return (x+1)==(n+m)?0:x+1;}
//int tot;
bool SPFA(int s){
	for (int i=1;i<=n+m;i++) dis[i]=INF,vis[i]=false,cnt[i]=0;
	head=0; tail=1; que[0]=s;
	dis[s]=0; cnt[s]=1;
	while (head!=tail){
		int u=que[head]; head=nxt(head);
		vis[u]=false;
		for (int e=Head[u];e;e=Next[e]){
			if (dis[vet[e]]>dis[u]+val[e]){
				dis[vet[e]]=dis[u]+val[e]; cnt[vet[e]]=cnt[vet[e]]+1;
				if (cnt[vet[e]]>n+m) return false;
				if (!vis[vet[e]]){
					vis[vet[e]]=true;
					que[tail]=vet[e]; tail=nxt(tail);
				}
			}
		}
	}
	return true;
}
int main(){
	scanf("%d",&T);
//	T=10;
	while (T--){
//		n=300; m=300;
		scanf("%d%d",&n,&m);
		edgenum=1;
		for (int i=1;i<=n+m;i++) Head[i]=0;
		for (int i=2;i<=n;i++)
			for (int j=2;j<=m;j++){
//				b[i][j]=rand()+1;
				scanf("%d",&b[i][j]);
			}
		bool flag=true;
		for (int i=2;i<=n;i++)
			for (int j=2;j<=m;j++){
				a[i][j]=b[i][j]-a[i-1][j-1]-a[i-1][j]-a[i][j-1];
				if (a[i][j]<-12000000||a[i][j]>12000000) flag=false;
			}
		if (!flag){
			puts("NO");
			continue;
		}
		for (int i=1;i<=n;i++)
			for (int j=1;j<=m;j++)
				if ((i+j)&1){
					//-a[i][j]<=-a_i+b_j<=lim-a[i][j]
					
					//a_i<=b_j+a[i][j]
					//b_j<=a_i+lim-a[i][j]
					add(i,j+n,a[i][j]); add(j+n,i,lim-a[i][j]);
				} else{
					//-a[i][j]<=a_i-b_j<=lim-a[i][j]
					
					//b_j<=a_i+a[i][j]
					//a_i<=b_j+lim-a[i][j]
					add(j+n,i,a[i][j]); add(i,j+n,lim-a[i][j]);
				}
				//(-1)^j  (-1)^i a_i   +   (-1)^i   (-1)^(j-1) b_j
//		double x=clock();
//		tot=0;
		bool ans=SPFA(1);
//		cerr<<tot<<endl;
//		double y=clock();
//		cerr<<y-x<<endl;
		if (!ans) puts("NO");
		else{
			puts("YES");
			for (int i=1;i<=n;i++){
				for (int j=1;j<=m;j++)
					printf("%d ",a[i][j]+op(i+j)*dis[i]+op(i+j-1)*dis[j+n]);
				putchar('\n');
			}
		}
	}
	return 0;
}
