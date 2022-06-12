#include<bits/stdc++.h>
using namespace std;
int n,k;
int gcd(int a,int b){
	if (!b) return a;
	return gcd(b,a%b);
}
int main(){
	scanf("%d%d",&n,&k);
	int g=0,m=0,x;
	for (int i=1;i<=n;i++){
		scanf("%d",&x);
		g=gcd(x,g); m=max(m,x);
	}
	if (k%g||k>m) puts("IMPOSSIBLE");
	else puts("POSSIBLE");
	return 0;
}
