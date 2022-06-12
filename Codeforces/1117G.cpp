#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
int n,Q,p[1100000],l[1100000];
int top,s[1100000]; ll Ans[1100000];
vector<int> vec[1100000];
priority_queue<pii> que;
struct node{
	int l,r;
	bool operator<(const node &a) const{
		return l<a.l||(l==a.l&&r<a.r);
	}
} q[1100000]; pll tree[1100000];
void add(int x,pll v){
	for (;x<=n;x+=x&-x) tree[x].first+=v.first,tree[x].second+=v.second;
}
pll query(int x){
	pll res=pll(0,0);
	for (;x;x-=x&-x) res.first+=tree[x].first,res.second+=tree[x].second;
	return res;
}
void solve(){
	for (int i=1;i<=n;i++) tree[i]=pll(0,0),vec[i].clear();
	top=1; s[1]=0;
	for (int i=1;i<=n;i++){
		while (top>1&&p[s[top]]<p[i]) top--;
		l[i]=s[top]+1; s[++top]=i;
	}
	for (int i=1;i<=Q;i++)
		vec[q[i].l].push_back(i);
	for (int i=n;i>=1;i--){
		que.push(pii(l[i],i)); add(i,pll(0,1));
		while (!que.empty()&&que.top().first==i){
			int u=que.top().second; que.pop();
			add(u,pll(i,-1));
		}
		for (int v:vec[i]){
			pll tmp=query(q[v].r);
			Ans[v]+=tmp.first+tmp.second*i;
		}
	}
}
int main(){
	scanf("%d%d",&n,&Q);
	for (int i=1;i<=n;i++) scanf("%d",&p[i]);
	for (int i=1;i<=Q;i++) scanf("%d",&q[i].l);
	for (int i=1;i<=Q;i++) scanf("%d",&q[i].r);
	
	solve();
//	for (int i=1;i<=Q;i++) cerr<<Ans[i]<<' '; cerr<<'\n';
	reverse(p+1,p+n+1);
	for (int i=1;i<=Q;i++){
		q[i].l=n-q[i].l+1; q[i].r=n-q[i].r+1;
		swap(q[i].l,q[i].r);
	}
	solve();
	for (int i=1;i<=Q;i++) printf("%lld ",1ll*(n+2)*(q[i].r-q[i].l+1)-Ans[i]);
	return 0;
}
/*
 * 询问[L,R]笛卡尔树的每层区间大小之和
 * 但是原序列的笛卡尔树不是很容易转化为[L,R]的笛卡尔树
 * 
 * 由于是排列，转而考虑一个点管辖的区间[l_i,r_i]
 * 对于原树，l_i是i左边第一个大于当前数的位置+1（找不到为1），r_i是i右边第一个大于当前数的位置-1（找不到为n）
 * 对于[L,R]的询问，它管辖的区间变为[max(L,l_i),min(R,r_i)]
 * 
 * 现在询问变为对于[L,R]中的数i，求min(R,r_i)-max(L,l_i)+1的和
 * 考虑max(L,l_i)的和，求min(R,r_i)的和也类似
 * 从大到小枚举L，对于所有i>=L维护max(L,l_i)的值（前缀和）
 * 可以使用两个树状数组和一个set，set维护l_i>L的i，树状数组就分别维护值和个数（前缀和）
 * */
