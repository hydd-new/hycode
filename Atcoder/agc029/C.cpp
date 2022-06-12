#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int n,a[510000];
int top; pii s[510000];
bool check(int mid){
	top=0;
	for (int i=2;i<=n;i++){
		if (a[i]>a[i-1]) continue;
		while (top&&s[top].first>a[i]) top--;
		if (s[top].first!=a[i]) s[++top]=pii(a[i],0);
		s[top].second++;
		while (top>1&&s[top].second==mid&&s[top-1].first+1==s[top].first){
			s[top-1].second++; s[top].second=0;
			top--;
		}
		if (s[top].second==mid) s[top].first--,s[top].second=1;
	}
	return s[1].first>=1;
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	bool flag=true;
	for (int i=1;i<n;i++)
		if (a[i]>=a[i+1]){ flag=false; break;}
	if (flag){ puts("1"); return 0;}
	int l=2,r=n,mid;
	while (l<r){
		mid=(l+r)>>1;
		if (check(mid)) r=mid;
		else l=mid+1;
	}
	printf("%d\n",l);
	return 0;
}