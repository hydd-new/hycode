#include<bits/stdc++.h>
using namespace std;
const int v=555;
int n,m,r,c;
int main(){
	scanf("%d%d%d%d",&n,&m,&r,&c);
	if (!(n%r)&&!(m%c)){
		puts("No");
		return 0;
	}
	puts("Yes");
	int tot=r*c-1;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++)
			if (!(i%r)&&!(j%c)) printf("%d ",-v*tot-1);
			else printf("%d ",v);
		putchar('\n');
	}
	return 0;
}