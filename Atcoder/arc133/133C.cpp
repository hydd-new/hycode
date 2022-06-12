#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,k,a[210000],b[210000];
int main(){
	scanf("%d%d%d",&n,&m,&k);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]),a[i]=((-a[i]-m)%k+k)%k;
	for (int i=1;i<=m;i++) scanf("%d",&b[i]),b[i]=((-b[i]-n)%k+k)%k;
	ll sum1=0,sum2=0;
	for (int i=1;i<=n;i++) sum1+=a[i];
	for (int i=1;i<=m;i++) sum2+=b[i];
	if (sum1%k!=sum2%k) puts("-1");
	else printf("%lld\n",1ll*n*m*(k-1)-max(sum1,sum2));
	return 0;
}
