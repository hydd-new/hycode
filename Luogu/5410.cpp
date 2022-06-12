#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,z[21000000],p[21000000];
char s[21000000],t[21000000];
void Z(char *s,int n){
	z[1]=n; int l=0,r=0;
	for (int i=2;i<=n;i++){
		int tmp=0;
		if (i<=r) tmp=min(z[i-l+1],r-i+1);
		while (i+tmp<=n&&1+tmp<=n&&s[i+tmp]==s[1+tmp]) tmp++;
		z[i]=tmp;
		if (i+tmp-1>r) l=i,r=i+tmp-1;
	}
}
void P(char *s,char *t,int n,int m){
	Z(t,m); int l=0,r=0;
	for (int i=1;i<=n;i++){
		int tmp=0;
		if (i<=r) tmp=min(z[i-l+1],r-i+1);
		while (i+tmp<=n&&1+tmp<=m&&s[i+tmp]==t[1+tmp]) tmp++;
		p[i]=tmp;
		if (i+tmp-1>r) l=i,r=i+tmp-1;
	}
}
int main(){
	scanf("%s",s+1); n=strlen(s+1);
	scanf("%s",t+1); m=strlen(t+1);
	P(s,t,n,m); ll ans;
	
	ans=0;
	for (int i=1;i<=m;i++) ans^=1ll*i*(z[i]+1);
	printf("%lld\n",ans);

	ans=0;
	for (int i=1;i<=n;i++) ans^=1ll*i*(p[i]+1);
	printf("%lld\n",ans);
	return 0;
}
