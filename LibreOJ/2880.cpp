#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n; ll ans;
int top,s[410000],t2p,t[410000];
struct node{ int x,y;} p[410000];
bool cmpx(const node &a,const node &b){ return a.x<b.x;}
bool cmpy(const node &a,const node &b){ return a.y>b.y;}
void ins(int i){
	while (top&&p[s[top]].x>p[i].x) top--;
	s[++top]=i;
}
int calc(){
	int l=1,r=top+1,mid;
	int val=p[t[t2p-1]].y;
	while (l<r){
		mid=(l+r)>>1;
		if (p[s[mid]].y<=val) r=mid;
		else l=mid+1;
	}
	return top-r+1;
}
void solve(int l,int r){
	if (l==r) return;
	int mid=(l+r)>>1;
	solve(l,mid); solve(mid+1,r);
	
	int j=mid+1; top=0; t2p=0;
	for (int i=l;i<=mid;i++){
		while (j<=r&&p[j].y>p[i].y) ins(j++);
		
		while (t2p&&p[t[t2p]].x<p[i].x) t2p--;
		t[++t2p]=i;
		
		if (t2p==1) ans+=top;
		else ans+=calc();
	}
	sort(p+l,p+r+1,cmpy);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>n;
	for (int i=1;i<=n;i++) cin>>p[i].x>>p[i].y;
	sort(p+1,p+n+1,cmpx);
	solve(1,n); cout<<ans<<'\n';
	return 0;
}

