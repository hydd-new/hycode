#include<bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
const int Mod=1e9+7;
typedef pair<int,int> pii;
int n,num[210000],p[210000]; pii a[210000];
int l[210000],r[210000],f[210000],sum[210000];
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d%d",&a[i].second,&a[i].first);
	sort(a+1,a+n+1);
	
	for (int i=1;i<=n;i++) num[i]=a[i].second;
	sort(num+1,num+n+1);
	
	for (int i=1;i<=n;i++){
		a[i].second=lower_bound(num+1,num+n+1,a[i].second)-num;
		p[a[i].second]=i;
	}

	r[0]=0; for (int i=1;i<=n;i++) r[i]=max(r[i-1],p[i]);
	l[n+1]=n+1; for (int i=n;i>=1;i--) l[i]=min(l[i+1],p[i]);
	
	f[0]=1; sum[0]=1; int j=0;
	for (int i=1;i<=n;i++){
		while (r[j]<l[i]-1) j++;
		f[i]=(sum[i-1]-sum[j-1]+Mod)%Mod;
		sum[i]=(sum[i-1]+f[i])%Mod;
	}
	while (r[j]<n) j++;
	printf("%d\n",(sum[n]-sum[j-1]+Mod)%Mod);
	return 0;
}
