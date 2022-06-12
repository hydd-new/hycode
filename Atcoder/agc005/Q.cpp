#include<bits/stdc++.h>
using namespace std;
int n,a[1100],b[1100],ans; char op[11];
int cnt,c[1100]; bool vis[1100];
bool cmp(int x,int y){ return b[x]<b[y];}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%s%d",op,&b[i]);
		a[i]=(op[0]=='y');
		if (a[i]) c[++cnt]=i;
	}
	sort(c+1,c+cnt+1,cmp);
	for (int i=1;i<=cnt;i++){
		int u=c[i];
		if (vis[u]) continue;
		
		int l=u;
		while (!(l<1||!a[l]&&b[l]>=b[u])) vis[l--]=true;
		int r=u;
		while (!(r>n||!a[r]&&b[r]>=b[u])) vis[r++]=true;
		ans++;
	}
	printf("%d\n",ans);
	return 0;
}