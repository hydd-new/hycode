#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a[110000],b[2][51000];
int main(){
	scanf("%d",&n); ll ans=0;
	for (int i=0;i<n;i++){
		scanf("%d",&a[i]);
		ans+=a[i];
	}
	int x;
	for (int i=0;i<n;i++){
		scanf("%d",&x); x-=a[i];
		b[i&1][i>>1]=x;
	}
	sort(b[0],b[0]+(n>>1),greater<int>());
	sort(b[1],b[1]+(n>>1),greater<int>());
	for (int i=0;i<(n>>1);i++)//not n
		if (b[0][i]>=-b[1][i]) ans+=b[0][i],ans+=b[1][i];
		else break;
	printf("%lld\n",ans);
	return 0;
}