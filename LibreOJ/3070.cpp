#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> poly;
const int INF=0x3f3f3f3f;
const int G=3;
const int Mod=998244353;
const int inv2=(Mod+1)>>1;

int n,k; ll Ans[310000]; bool cut[110000];
int cnt,p[110000],q[110000]; poly vec[110000];
int edgenum=1,vet[210000],val[210000],Next[210000],Head[110000];

inline ll add(ll x,ll y){ return x+y>=Mod?x+y-Mod:x+y;}
inline ll dec(ll x,ll y){ return x-y<0?x-y+Mod:x-y;}

char Getchar(){
	static char now[1<<20],*S,*T;
	if (T==S){
		T=(S=now)+fread(now,1,1<<20,stdin);
		if (T==S) return EOF;
	}
	return *S++;
}
int read(){
	int x=0,f=1;
	char ch=Getchar();
	while (ch<'0'||ch>'9'){
		if (ch=='-') f=-1;
		ch=Getchar();
	}
	while (ch>='0'&&ch<='9') x=x*10+ch-'0',ch=Getchar();
	return x*f;
}
void addedge(int u,int v){
	vet[++edgenum]=v;
	Next[edgenum]=Head[u];
	Head[u]=edgenum;
}
ll qpow(ll x,ll a){
	ll res=1;
	while (a){
		if (a&1) res=res*x%Mod;
		x=x*x%Mod; a>>=1;
	}
	return res;
}
ll getinv(ll x){ return qpow(x,Mod-2);}
namespace find_cycle{
	bool vis[110000],flag;
	int le[110000];
	void dfs(int u){
		vis[u]=true;
		for (int e=Head[u];e;e=Next[e])
			if (e!=(le[u]^1)){
				if (vis[vet[e]]){
					int x=u,y=vet[e]; cut[e>>1]=true;
					cnt=0;
					for (;x!=y;x=vet[le[x]^1]) cut[le[x]>>1]=true,p[++cnt]=x;
					p[++cnt]=y;
					flag=true; return;
				}
				le[vet[e]]=e;
				dfs(vet[e]); if (flag) return;
			}
	}
	void work(){
		dfs(1);
	}
}
namespace polynomial{
	int rev[810000];
	void NTT(poly &a,int len,int inv){
		a.resize(len);
		for (int i=0;i<len;i++)
			if (i<rev[i]) swap(a[i],a[rev[i]]);
		for (int mid=1;mid<len;mid<<=1){
			ll tmp=qpow(G,(Mod-1)/(mid<<1));
			if (inv==-1) tmp=getinv(tmp);
			for (int i=0;i<len;i+=(mid<<1)){
				ll omega=1;
				for (int j=0;j<mid;j++,omega=omega*tmp%Mod){
					ll x=a[i+j],y=omega*a[i+j+mid]%Mod;
					a[i+j]=add(x,y); a[i+j+mid]=dec(x,y);
				}
			}
		}
		if (inv==-1){
			ll tmp=getinv(len);
			for (int i=0;i<len;i++) a[i]=a[i]*tmp%Mod;
		}
	}
	void polysqr(poly a,poly &b){
		int bit=0,len=1;
		while (len<(int)a.size()+(int)a.size()) bit++,len<<=1;
		for (int i=0;i<len;i++) rev[i]=(rev[i>>1]>>1)|((i&1)<<(bit-1));
		NTT(a,len,1);
		
		b.resize(len);
		for (int i=0;i<len;i++) b[i]=a[i]*a[i]%Mod;
		NTT(b,len,-1);
		b.resize((int)a.size()+(int)a.size()-1);
	}
	void polymul(poly a,poly b,poly &c){
		int bit=0,len=1;
		while (len<(int)a.size()+(int)b.size()) bit++,len<<=1;
		for (int i=0;i<len;i++) rev[i]=(rev[i>>1]>>1)|((i&1)<<(bit-1));
		NTT(a,len,1); NTT(b,len,1);
		
		c.resize(len);
		for (int i=0;i<len;i++) c[i]=a[i]*b[i]%Mod;
		NTT(c,len,-1);
		c.resize((int)a.size()+(int)b.size()-1);
	}
}

namespace divide_conquer{
	poly F,G,H; int m;
	void solve(int l,int r){
		if (l==r) return;
		int mid=(l+r)>>1;
		solve(l,mid); solve(mid+1,r);
		F.clear();
		for (int i=l;i<=mid;i++)
			for (int j=0;j<(int)vec[i].size();j++){
				while ((int)F.size()<=j+mid-i) F.push_back(0);
				F[j+mid-i]=add(F[j+mid-i],vec[i][j]);
			}
		G.clear();
		for (int i=mid+1;i<=r;i++)
			for (int j=0;j<(int)vec[i].size();j++){
				while ((int)G.size()<=j+i-mid) G.push_back(0);
				G[j+i-mid]=add(G[j+i-mid],vec[i][j]);
			}
		polynomial::polymul(F,G,H);
		for (int i=0;i<(int)H.size();i++) Ans[i]=add(Ans[i],H[i]);
	}
	void solve2(int l,int r){
		if (l==r){//i=j
			polynomial::polymul(vec[l],vec[l+m],H);
			for (int i=0;i<(int)H.size();i++) Ans[i+m]=add(Ans[i+m],H[i]);
			return;
		}

		int mid=(l+r)>>1;
		solve2(l,mid); solve2(mid+1,r);

		//j<i
		F.clear();
		for (int i=mid+1;i<=r;i++)//i
			for (int j=0;j<(int)vec[i].size();j++){
				while ((int)F.size()<=j+r-i) F.push_back(0);
				F[j+r-i]=add(F[j+r-i],vec[i][j]);
			}
		G.clear();
		for (int i=l;i<=mid;i++)//j
			for (int j=0;j<(int)vec[i+m].size();j++){
				while ((int)G.size()<=j+i-l) G.push_back(0);
				G[j+i-l]=add(G[j+i-l],vec[i+m][j]);
			}
		polynomial::polymul(F,G,H);
		for (int i=0;i<(int)H.size();i++) Ans[i+l+m-r]=add(Ans[i+l+m-r],H[i]);


		//i<j
		F.clear();
		for (int i=mid+1;i<=r;i++)//j
			for (int j=0;j<(int)vec[i+m].size();j++){
				while ((int)F.size()<=j+r-i) F.push_back(0);
				F[j+r-i]=add(F[j+r-i],vec[i+m][j]);
			}
		G.clear();
		for (int i=l;i<=mid;i++)//i
			for (int j=0;j<(int)vec[i].size();j++){
				while ((int)G.size()<=j+i-l) G.push_back(0);
				G[j+i-l]=add(G[j+i-l],vec[i][j]);
			}
		polynomial::polymul(F,G,H);
		for (int i=0;i<(int)H.size();i++) Ans[i+l+cnt-m-r]=add(Ans[i+l+cnt-m-r],H[i]);
	}
	void work(){
		m=cnt>>1;
		solve(1,m);
		solve(m+1,cnt);
		if (cnt&1){
			F.clear();
			for (int i=1;i<=m;i++)
				for (int j=0;j<(int)vec[i].size();j++){
					while ((int)F.size()<=j+i) F.push_back(0);
					F[j+i]=add(F[j+i],vec[i][j]);
				}
			polynomial::polymul(F,vec[cnt],G);
			for (int i=0;i<(int)G.size();i++) Ans[i]=add(Ans[i],G[i]);
		}
		solve2(1,m);
	}
}

namespace tree_divide{
	int all,mn,rt;
	int sz[110000],dep[110000];
	bool vis[110000];
	poly F,G;
	void getrt(int u,int f){
		sz[u]=1;
		int tmp=0;
		for (int e=Head[u];e;e=Next[e])
			if (vet[e]!=f&&!vis[vet[e]]&&!cut[e>>1]){
				getrt(vet[e],u);
				sz[u]+=sz[vet[e]];
				tmp=max(tmp,sz[vet[e]]);
			}
		tmp=max(tmp,all-sz[u]);
		if (tmp<mn) mn=tmp,rt=u;
	}
	void dfs(int u,int f){
		dep[u]=dep[f]+1;
		if ((int)F.size()<=dep[u]) F.push_back(0);
		F[dep[u]]++;
		for (int e=Head[u];e;e=Next[e])
			if (vet[e]!=f&&!vis[vet[e]]&&!cut[e>>1]) dfs(vet[e],u);
	}
	void solve(int u,int k){
		F.clear(); dfs(u,0);
		polynomial::polysqr(F,G);
		for (int i=k;i<(int)G.size();i++)
			if (k) Ans[i]=add(Ans[i],G[i]);
			else Ans[i+2]=dec(Ans[i+2],G[i]);
	}
	void divide(int u){
		solve(u,1);
		vis[u]=true; int tot=all;
		for (int e=Head[u];e;e=Next[e])
			if (!vis[vet[e]]&&!cut[e>>1]){
				solve(vet[e],0);
				all=sz[vet[e]]>sz[u]?tot-sz[u]:sz[vet[e]]; mn=INF;
				getrt(vet[e],0); divide(rt);
			}
	}
	void work(){
		dep[0]=-1;
		for (int i=1;i<=cnt;i++){
			F.clear(); dfs(p[i],0);
			vec[i].resize(F.size());
			for (int j=0;j<(int)F.size();j++) vec[i][j]=F[j],q[i]+=F[j];
		}
		for (int i=1;i<=cnt;i++){
			all=q[i]; mn=INF;
			getrt(p[i],0); divide(rt);
		}
		for (int i=1;i<n;i++) Ans[i]=Ans[i]*inv2%Mod;
	}
}

int main(){
//	freopen("b.in","r",stdin);
//	freopen("b.out","w",stdout);
	n=read(); k=read(); int u,v;
	bool flag=true;
	for (int i=1;i<=n;i++){
		u=read(); v=read();
		if (u==v){ flag=false; continue;}
		addedge(u,v); addedge(v,u);
	}
	if (flag) find_cycle::work();
	else{ cnt=1; p[1]=1;}
	tree_divide::work();
	if (flag) divide_conquer::work();
	ll ans=0;
	for (int i=1;i<n;i++) ans=(ans+qpow(i,k)*Ans[i])%Mod;
	ans=ans*qpow((1ll*n*(n-1)/2)%Mod,Mod-2)%Mod;
	printf("%lld\n",ans);
	return 0;
}
