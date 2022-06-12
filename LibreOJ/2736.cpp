#include<bits/stdc++.h>
using namespace std;
int n,Q,blo,a[510000],bel[510000],L[510000],R[510000];
priority_queue<int> p[510000];
priority_queue<int,vector<int>,greater<int>> q[510000];
void refac(int x){
	for (int i=L[x];i<=R[x];i++){
		q[x].push(a[i]);
		a[i]=q[x].top(); q[x].pop();
	}
	while (!q[x].empty()) q[x].pop();
}
void store(int x){
	while (!p[x].empty()) p[x].pop();
	for (int i=L[x];i<=R[x];i++) p[x].push(a[i]);
}
int solve(int l,int r,int v){
	if (bel[l]==bel[r]){
		refac(bel[l]);
		for (int i=l;i<=r;i++)
			if (a[i]>v) swap(a[i],v);
		store(bel[l]); return v;
	}
	
	refac(bel[l]);
	for (int i=l;i<=R[bel[l]];i++)
		if (a[i]>v) swap(a[i],v);
	store(bel[l]);
	for (int i=bel[l]+1;i<=bel[r]-1;i++){
		q[i].push(v);
		p[i].push(v);
		v=p[i].top(); p[i].pop();
	}
	refac(bel[r]);
	for (int i=L[bel[r]];i<=r;i++)
		if (a[i]>v) swap(a[i],v);
	store(bel[r]);
	return v;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin>>n>>Q; blo=sqrt(n+0.5);
	for (int i=1;i<=n;i++) cin>>a[i];
	for (int i=1;i<=n;i++) bel[i]=(i-1)/blo+1;
	for (int i=n;i>=1;i--) L[bel[i]]=i;
	for (int i=1;i<=n;i++) R[bel[i]]=i;
	for (int i=1;i<=bel[n];i++) store(i);
	int l,r,v;
	for (int i=1;i<=Q;i++){
		cin>>l>>r>>v;
		if (l<=r) cout<<solve(l,r,v)<<'\n';
		else cout<<solve(1,r,solve(l,n,v))<<'\n';
	}
    return 0;
}
