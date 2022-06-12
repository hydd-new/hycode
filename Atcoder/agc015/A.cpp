#include<bits/stdc++.h>
using namespace std;
int n,a,b;
int main(){
	scanf("%d%d%d",&n,&a,&b);
	if (n==1||a>b) return printf("%d\n",(a==b)),0;
	printf("%lld\n",1ll*(b-a)*(n-2)+1);
	return 0;
}