#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
char s[110000]; int n;
int main(){
	scanf("%s",s+1); n=strlen(s+1);
	ll ans=0;
	for (int i=1;i<=n;i++) ans+=n-1+(s[i]=='U')*(i-1)+(s[i]=='D')*(n-i);
	printf("%lld\n",ans);
	return 0;
}
