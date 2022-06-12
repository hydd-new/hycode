#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int n,a[210000],b[210000];
pii c[4100000]; int cnt;
int tree[210000];
void add(int x,int y){
	for (;x<=n;x+=x&-x) tree[x]=max(tree[x],y);
}
int query(int x){
	int res=0;
	for (;x;x-=x&-x) res=max(res,tree[x]);
	return res;
}
int main(){
	scanf("%d",&n); int x;
	for (int i=1;i<=n;i++){
		scanf("%d",&x);
		a[x]=i;
	}
	for (int i=1;i<=n;i++){
		scanf("%d",&x);
		b[x]=i;
	}
	for (int i=1;i<=n;i++)
		for (int j=i;j<=n;j+=i)
			c[++cnt]=pii(a[i],-b[j]);
	sort(c+1,c+cnt+1); int ans=0,now;
	for (int i=1;i<=cnt;i++){
		now=query(-c[i].second-1)+1;
		add(-c[i].second,now); ans=max(ans,now);
	}
	printf("%d\n",ans);
	return 0;
}
