#include<bits/stdc++.h>
using namespace std;
int m,n,c[25];
int r[5100],l[5100]; bool f[5100],g[5100][25];
int main(){
	scanf("%d",&m); int x;
	for (int i=1;i<=m;i++){
		scanf("%d",&x);
		if (x!=1) c[++n]=x;
	}
	if (m==1&&n==0){ puts("YES"); return 0;}
	if (n>12){ puts("NO"); return 0;}
	int upperlim=(1<<n)-1;
	for (int s=1;s<=upperlim;s++){
		int u=0,tot=0;
		for (int i=1;i<=n;i++)
			if ((s>>(i-1))&1){
				tot++;
				if (c[i]>c[u]) u=i;
			}
		r[s]=tot; l[s]=c[u]-tot;//internal count / leaf count
		if (l[s]<0) continue;
		
		int all=s^(1<<(u-1));
		if (all) f[s]=(f[all]&&l[all]!=0&&l[all]<l[s]);
		else f[s]=(l[s]!=1);
		for (int i=0;i<=l[s];i++) f[s]=(f[s]||g[all][i]);
		
		for (int t=((s-1)&s);t;t=((t-1)&s))
			for (int i=l[t];i<=m-n;i++)
				if ((f[t]&&g[s^t][i-l[t]])||(f[t]&&(f[s^t]&&l[s^t]==i-l[t]))) g[s][i]=true;
	}
	if (r[upperlim]==n&&l[upperlim]==m-n&&f[upperlim]) puts("YES");
	else puts("NO");
	return 0;
}
