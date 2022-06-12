#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int n,mx,t,b[1100000],c[1100000],cnt,xx,yy;
int s[1100000]; pii a[1100000]; char ss[1100000];
queue<int> que;
bool check(int tot){
	if (xx+tot<yy) return false;
	ll sum=0,ans=1ll<<60; int now=0;
	for (int i=1;i<=cnt;i++){
		if (que.empty()) ans=min(ans,sum+(mx-now)+(mx-a[i].first));
		else ans=min(ans,sum+(mx-now)+(mx-que.front()));
		if (a[i].second==1){
			sum+=(a[i].first-now); now=a[i].first;
			if (!que.empty()){
				sum+=now-que.front();
				now=que.front(); que.pop();
			} else tot++;
		} else{
			if (tot>0) tot--;
			else que.push(a[i].first);
			sum+=(a[i].first-now); now=a[i].first;
		}
	}
	return (min(ans,sum))<=t;
}
int main(){
	scanf("%d%d",&n,&t);
//	scanf("%s",ss+1);
	for (int i=1;i<=n;i++){
		if (rand()%3==0) a[++cnt]=pii(i,1),mx=max(mx,i),xx++;
		else if (rand()&1) a[++cnt]=pii(i,0),mx=max(mx,i),yy++;
	}
	int l=0,r=n;
	while (l<r){
		int mid=(l+r)>>1;
		if (check(mid)) r=mid;
		else l=mid+1;
	}
	printf("%d\n",l);
	return 0;
}
