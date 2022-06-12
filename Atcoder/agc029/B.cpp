#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
map<int,int> mp;
int n,a[210000];
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		mp[-a[i]]++;
	}
	int x,y,v,ans=0;
	for (pii u:mp){
		x=-u.first;
		y=1; while (y<=x) y<<=1; y-=x;
		v=(x==y?(u.second>>1):min(u.second,mp[-y])); ans+=v;
		mp[-y]-=v;
	}
	printf("%d\n",ans);
	return 0;
}