#include<bits/stdc++.h>
#define ls now<<1
#define rs now<<1|1
using namespace std;
typedef long long ll;
int n,Mod,p[310000]; ll pw[310000];
bool A[310000],B[310000];
int cnt=0;
struct L_{
	ll tree[1210000];
	void build(int now,int l,int r){
//		cnt++;
		if (l==r){
			tree[now]=0;
			return;
		}
		int mid=(l+r)>>1;
		build(ls,l,mid); build(rs,mid+1,r);
	}
	void change(int now,int l,int r,int x){
		cnt++;
		if (l==r){
			tree[now]=1;
			return;
		}
		int mid=(l+r)>>1;
		if (x<=mid) change(ls,l,mid,x);
		else change(rs,mid+1,r,x);
		tree[now]=(tree[ls]*pw[r-mid]+tree[rs])%Mod;
	}
	int query(int now,int l,int r,int x,int y){
//		cnt++;
		if (l==x&&r==y) return tree[now];
		int mid=(l+r)>>1;
		if (y<=mid) return query(ls,l,mid,x,y);
		else if (x>mid) return query(rs,mid+1,r,x,y);
		else return (query(ls,l,mid,x,mid)*pw[y-mid]+query(rs,mid+1,r,mid+1,y))%Mod;
	}
} L;
struct R_{
	ll tree[1210000];
	void build(int now,int l,int r){
//		cnt++;
		if (l==r){
			tree[now]=0;
			return;
		}
		int mid=(l+r)>>1;
		build(ls,l,mid); build(rs,mid+1,r);
	}
	void change(int now,int l,int r,int x){
		cnt++;
		if (l==r){
			tree[now]=1;
			return;
		}
		int mid=(l+r)>>1;
		if (x<=mid) change(ls,l,mid,x);
		else change(rs,mid+1,r,x);
		tree[now]=(tree[rs]*pw[mid-l+1]+tree[ls])%Mod;
	}
	int query(int now,int l,int r,int x,int y){
//		cnt++;
		if (l==x&&r==y) return tree[now];
		int mid=(l+r)>>1;
		if (y<=mid) return query(ls,l,mid,x,y);
		else if (x>mid) return query(rs,mid+1,r,x,y);
		else return (query(rs,mid+1,r,mid+1,y)*pw[mid-x+1]+query(ls,l,mid,x,mid))%Mod;
	}
} R;
bool check(int i){
	int len=min(i-1,n-i);
	if (len==0) return false;
	return L.query(1,1,n,i-len,i-1)!=R.query(1,1,n,i+1,i+len);
}
void work(bool *c){
	pw[0]=1;
	for (int i=1;i<=n;i++) pw[i]=(pw[i-1]<<1)%Mod;
	L.build(1,1,n); R.build(1,1,n);
	for (int i=1;i<=n;i++){
		c[i]=check(p[i]);
		L.change(1,1,n,p[i]); R.change(1,1,n,p[i]);
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
//	srand(10);
//	n=300000;
//	for (int i=1;i<=n;i++) p[i]=i;
//	random_shuffle(p+1,p+n+1);
	cin>>n;
	for (int i=1;i<=n;i++) cin>>p[i];
	Mod=1e9+7; work(A);
//	Mod=1e9+9; work(B);
//	for (int i=1;i<=n;i++) cerr<<A[i]<<' '<<B[i]<<'\n';
//	cerr<<cnt<<'\n';
	for (int i=1;i<=n;i++)
		if (A[i]){
			cout<<"YES\n"; 
			return 0;
		}
	cout<<"NO\n";
	return 0;
}
