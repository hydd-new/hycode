#include<bits/stdc++.h>
using namespace std;
int n,k,Log2[1<<20];
char t[(1<<20)+1]; int top,s[25];
int *f[1<<21],trans[1<<21][2];
int main(){
	scanf("%d%d",&n,&k); Log2[0]=-1;
	for (int i=1;i<(1<<20);i++) Log2[i]=Log2[i>>1]+1;
	f[1]=new int[1<<(n+1)];
	f[1][0]=0;
	for (int i=0;i<=n;i++){
		scanf("%s",t); int now=1<<i;
		for (int s=0;s<now;s++) f[1][now+s]=t[s]-'0';
		for (int s=0;s<now;s++){
			int len=Log2[(now-1)^s];
			trans[now+s][0]=(len==-1?0:(s&((1<<len)-1))|(1<<len));
			trans[now+s][1]=s;
		}
	}
	int ans=1;
	for (int i=1;i<=n;i++){
		int now=1<<i;
		for (int s=2*now-1;s>=now;s--){
			f[s]=new int[1<<(n-i+1)];
			for (int t=1;t<1<<(n-i+1);t++) f[s][t]=0;
			for (int t=1;t<1<<(n-i+2);t++) f[s][trans[t][s&1]]+=f[s>>1][t];
			int sum=0;
			for (int t=1;t<1<<(n-i+1);t++) sum+=f[s][t];
			if (sum>=k) ans=s;
		}
	}
	while (ans) s[++top]=ans&1,ans>>=1; top--;
	while (top) putchar(s[top--]+'0'); putchar('\n');
	return 0;
}
