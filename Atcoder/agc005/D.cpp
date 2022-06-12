#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> poly;
const int Mod=924844033;
const int G=5; const int invG=554906420;
int n,m,rev[510000],k;
poly f,g,h; ll fac[510000],inv[510000];
inline int add(int x,int y){ return x+y>=Mod?x+y-Mod:x+y;}
inline int dec(int x,int y){ return x-y<0?x-y+Mod:x-y;}
inline int mul(int x,int y){ return 1ll*x*y%Mod;}
ll qpow(ll x,ll a){
	ll res=1;
	while (a){
		if (a&1) res=res*x%Mod;
		x=x*x%Mod; a>>=1;
	}
	return res;
}
inline ll getinv(int x){ return qpow(x,Mod-2);}
void NTT(poly &a,int len,int inv){
	a.resize(len);
	for (int i=0;i<len;i++)
		if (i<rev[i]) swap(a[i],a[rev[i]]);
	for (int mid=1;mid<len;mid<<=1){
		int tmp=qpow(G,(Mod-1)/(mid<<1));
		if (inv==-1) tmp=getinv(tmp);
		for (int i=0;i<len;i+=(mid<<1)){
			ll omega=1;
			for (ll j=0;j<mid;j++,omega=mul(omega,tmp)){
				int x=a[i+j],y=mul(omega,a[i+j+mid]);
				a[i+j]=add(x,y),a[i+j+mid]=dec(x,y);
			}
		}
	}
	if (inv==-1){
		ll inv=getinv(len);
		for (int i=0;i<len;i++) a[i]=mul(a[i],inv);
	}
}
void mult(poly a,poly b,poly &c){
	int bit=0; while ((1<<bit)<=n+n+1) bit++;
	int len=1<<bit;
	for (int i=0;i<len;i++) rev[i]=(rev[i>>1]>>1)|((i&1)<<(bit-1));
	NTT(a,len,1); NTT(b,len,1);
	c.resize(len);
	for (int i=0;i<len;i++) c[i]=mul(qpow(a[i],(k-n%k)*2),qpow(b[i],n%k*2));
	NTT(c,len,-1);
}
ll C(int n,int m){
	if (n<m) return 0;
	return mul(fac[n],mul(inv[m],inv[n-m]));
}
int main(){
	scanf("%d%d",&n,&k);
	fac[0]=1; for (int i=1;i<=n;i++) fac[i]=mul(fac[i-1],i);
	inv[1]=1; for (int i=2;i<=n;i++) inv[i]=mul(Mod-Mod/i,inv[Mod%i]);
	inv[0]=1; for (int i=1;i<=n;i++) inv[i]=mul(inv[i-1],inv[i]);
	f.resize(n+1); g.resize(n+1);
	for (int i=0;i<=n;i++){
		f[i]=C(n/k-i,i);
		g[i]=C(n/k+1-i,i);
	}
	mult(f,g,h);
	int ans=0;
	for (int i=0;i<=n;i++)
		if (i&1) ans=dec(ans,mul(fac[n-i],h[i]));
		else ans=add(ans,mul(fac[n-i],h[i]));
	printf("%d\n",ans);
	return 0;
}