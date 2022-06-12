#include<bits/stdc++.h>
using namespace std;
int n,k,ansx,ansy,Log2[1<<20];
int f[21][1<<21],trans[1<<21][2];
char t[(1<<20)+1];
void dfs(int i,int s){
	if (i>n) return;
	for (int t=1;t<1<<(n-i+1);t++) f[i][t]=0;
	for (int t=1;t<1<<(n-i+2);t++) f[i][trans[t][s&1]]+=f[i-1][t];
	int sum=0;
	for (int t=1;t<1<<(n-i+1);t++) sum+=f[i][t];
	if (sum>=k&&ansx<i) ansx=i,ansy=s;
	dfs(i+1,s<<1); dfs(i+1,s<<1|1);
}
int main(){
	scanf("%d%d",&n,&k); Log2[0]=-1;
	for (int i=1;i<(1<<20);i++) Log2[i]=Log2[i>>1]+1;
	f[0][0]=0;
	for (int i=0;i<=n;i++){
		scanf("%s",t); int now=1<<i;
		for (int s=0;s<now;s++) f[0][now+s]=t[s]-'0';
		for (int s=0;s<now;s++){
			int len=Log2[(now-1)^s];
			trans[now+s][0]=(len==-1?0:(s&((1<<len)-1))|(1<<len));
			trans[now+s][1]=s;
		}
	}
	ansx=0; ansy=1;
	dfs(1,2); dfs(1,3);
	for (int i=ansx-1;i>=0;i--) putchar(((ansy>>i)&1)+'0'); putchar('\n');
	return 0;
}
