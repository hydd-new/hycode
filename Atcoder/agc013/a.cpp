#include<bits/stdc++.h>
using namespace std;
int m,n,a[110000];
int main(){
	scanf("%d",&m); int x;
	for (int i=1;i<=m;i++){
		scanf("%d",&x);
		if (a[n]!=x) a[++n]=x;
	}
	int ans=1;
	for (int i=2;i<n;i++)
		if (a[i]>max(a[i-1],a[i+1])||a[i]<min(a[i-1],a[i+1])) ans++,i++;
	printf("%d\n",ans);
	return 0;
}