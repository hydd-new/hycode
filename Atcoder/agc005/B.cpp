#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a[210000];
int top,s[210000];
ll calc(){ return 1ll*a[s[top]]*(s[top]-s[top-1]);}
int main(){
	scanf("%d",&n);
	ll sum=0,ans=0;
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		while (top&&a[s[top]]>a[i]){
			sum-=calc();
			top--;
		}
		s[++top]=i; sum+=calc(); ans+=sum;
	}
	printf("%lld\n",ans);
	return 0;
}