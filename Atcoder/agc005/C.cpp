#include<bits/stdc++.h>
using namespace std;
int n,a[110000];
int main(){
	scanf("%d",&n); int x,mx=0;
	for (int i=1;i<=n;i++){
		scanf("%d",&x);
		a[x]++; mx=max(mx,x);
	}
	for (int i=0;i<=mx;i++){
		if (a[max(i,mx-i)]==0){
			puts("Impossible");
			return 0;
		}
		a[max(i,mx-i)]--;
	}
	for (int i=1;i<=((mx+1)>>1);i++)
		if (a[i]){
			puts("Impossible");
			return 0;
		}
	puts("Possible");
	return 0;
}
