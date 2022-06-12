#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int n,s,used[110000],son[110000];
pii a[110000]; bitset<70005> f,g;
bool vis[110000]; int c[110000];
int main(){
	scanf("%d%d",&n,&s);
	for (int i=1;i<=n;i++){
		scanf("%d",&c[i]);
		a[i]=pii(c[i],i);
	}
	sort(a+1,a+n+1,greater<pii>());
	f[a[1].first]=1; used[a[1].first]=1;
	for (int i=2;i<=n;i++){
		g=f; f|=(g<<a[i].first); g^=f;
		for (int j=g._Find_first();j<=70000;j=g._Find_next(j)) used[j]=i;
		if (f[s]) break;
	}
	if (!f[s]){
		puts("-1");
		return 0;
	}
	for (int i=s;i;i-=a[used[i]].first) vis[used[i]]=true;
	int now=0;
	for (int i=n;i>=1;i--)
		if (!vis[i]||i==1){
			son[a[i].second]=now;
			now=a[i].second;
		}
	for (int i=1;i<=n;i++)
		if (son[i]) printf("%d 1 %d\n",c[i]-c[son[i]],son[i]);
		else printf("%d 0\n",c[i]);
	return 0;
}
