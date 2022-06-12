#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n; char s[2100];
bitset<2100> a[2100],b[2100];
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%s",s+1);
		for (int j=1;j<=n;j++){
			if (i==j) continue;
			if (s[j]=='Y') a[i][j]=1;
			else b[i][j]=1;
		}
	}
/*
	(a,b),(b,c),(c,d),(d,a) is colored X, (a,c) is colored Y       -1
	(a,b),(c,d) is colored X, (b,c),(d,a) is colored Y             +1
*/
	ll ans1=0,ans2=0; int tmp,x,y;
	for (int i=1;i<=n;i++)
		for (int j=i+1;j<=n;j++){
			if (a[i][j]) x=(b[i]&b[j]).count();
			else x=(a[i]&a[j]).count();
			ans1+=x*(x-1)/2;
			
			int x=(a[i]&b[j]).count(),y=(b[i]&a[j]).count();
			ans2+=x*y;
		}
	printf("%lld\n",(ans2>>1)-ans1);
	return 0;
}
