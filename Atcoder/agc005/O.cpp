#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a[21]; ll y,z,now,ans;
char s[110000]; bool vis[21];
void dfs(int d,ll x){
	if (d==n){
		if (min(abs(x-y),z-abs(x-y))>now){
			now=min(abs(x-y),z-abs(x-y));
			ans=x;
		}
		return;		
	}
	for (int i=0;i<=9;i++)
		if (!vis[i]){
			vis[i]=true;
			dfs(d+1,x*10+i);
			vis[i]=false;
		}
}
int main(){
	scanf("%s",s); n=strlen(s);
	y=0; z=1; now=0; ans=y;
	for (int i=0;i<n;i++) y=y*10+s[i]-'0',z*=10;
	dfs(0,0);
	for (int i=0;i<n;i++) a[i]=ans%10,ans/=10;
	while (n--) putchar(a[n]+'0');
	return 0;
}
