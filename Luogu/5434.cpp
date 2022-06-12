#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int Mod=998244353;
const int inv2=(Mod+1)/2;
const int invG=(Mod+1)/3;
int Q,n,rev[270000],fac[270000];
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
	while (ch<='9'&&ch>='0') x=x*10+ch-'0',ch=Getchar();
	return x*f;
}
inline int add(int x,int y){ return x+y>=Mod?x+y-Mod:x+y;}
inline int dec(int x,int y){ return x-y<0?x-y+Mod:x-y;}
ll qpow(ll x,ll a){
	ll res=1;
	while (a){
		if (a&1) res=res*x%Mod;
		x=x*x%Mod; a>>=1;
	}
	return res;
}
inline ll getinv(int x){ return qpow(x,Mod-2);}
int Gpow[2][19][270000];
void initG(){
    for (int p=1;p<=18;p++){
        int buf1=qpow(3,(Mod-1)/(1<<p));
        int buf0=qpow(invG,(Mod-1)/(1<<p));
        Gpow[1][p][0]=Gpow[0][p][0]=1;
        for (int i=1;i<(1<<p);i++){
            Gpow[1][p][i]=1ll*Gpow[1][p][i-1]*buf1%Mod;
            Gpow[0][p][i]=1ll*Gpow[0][p][i-1]*buf0%Mod;
        }
    }
}
void NTT(int *a,int len,int inv){
    if (inv==-1) inv=0;
    for (int i=0;i<len;i++)
        if (i<rev[i]) swap(a[i],a[rev[i]]);
    int mx=0;
    for (int l=2,cnt=1;l<=len;l<<=1,cnt++){
        int m=l>>1; mx=cnt;
        for (int i=0;i<len;i+=l){
            int *buf=Gpow[inv][cnt];
            for (int j=0;j<m;j++,buf++) {
                int x=a[i+j],y=1ll*(*buf)*a[i+j+m]%Mod;
                a[i+j]=add(x,y),a[i+j+m]=dec(x,y);
            }
        }
    }
//    cerr<<mx<<endl;
    if (inv!=1){
        ll inv=getinv(len);
        for (int i=0;i<len;i++) a[i]=inv*a[i]%Mod;
    }
}
/*
void NTT(int *a,int len,int op){
	for (int i=0;i<len;i++)
		if (i<rev[i]) swap(a[i],a[rev[i]]);
	for (int mid=1;mid<len;mid<<=1){
		int tmp=qpow(3,(Mod-1)/(mid<<1));
		if (op==-1) tmp=getinv(tmp);
		for (int i=0;i<len;i+=(mid<<1)){
			ll omega=1;
			for (int j=0;j<mid;j++,omega=omega*tmp%Mod){
				int x=a[i+j],y=1ll*omega*a[i+j+mid]%Mod;
				a[i+j]=add(x,y); a[i+j+mid]=dec(x,y);
			}
		}
	}
	if (op==-1){
		ll inv=getinv(len);
		for (int i=0;i<len;i++) a[i]=a[i]*inv%Mod;
	}
}
*/
void Mul(int *a,int *b,int *c,int p,int q){
	static int A[270000],B[270000];
	int n=p+q;
	int bit=0; while ((1<<bit)<n) bit++;
	int len=1<<bit,mid=len>>1;
	for (int i=0;i<p;i++) A[i]=a[i]; 
	for (int i=p;i<len;i++) A[i]=0;
	for (int i=0;i<q;i++) B[i]=b[i]; 
	for (int i=q;i<len;i++) B[i]=0;
	for (int i=0;i<len;i++) rev[i]=(rev[i>>1]>>1)|((i&1)?mid:0);
	NTT(A,len,1); NTT(B,len,1);
	for (int i=0;i<len;i++) c[i]=1ll*A[i]*B[i]%Mod;
	NTT(c,len,-1);
}
void Inv(int *a,int *b,int n){
	static int A[270000],B[270000];
	b[0]=qpow(a[0],Mod-2);
	for (int mid=2;mid<(n<<1);mid<<=1){
		int len=mid<<1;
		for (int i=0;i<mid;i++) A[i]=a[i],B[i]=b[i];
		for (int i=mid;i<len;i++) A[i]=0,B[i]=0;
		for (int i=0;i<len;i++) rev[i]=(rev[i>>1]>>1)|((i&1)?mid:0);
		
		NTT(A,len,1); NTT(B,len,1);
		for (int i=0;i<len;i++) b[i]=1ll*(Mod+2-1ll*A[i]*B[i]%Mod)*B[i]%Mod;
		NTT(b,len,-1);
		for (int i=mid;i<len;i++) b[i]=0;
	}
}
void Der(int *A,int *B,int len){
	for (int i=1;i<len;i++) B[i-1]=1ll*i*A[i]%Mod;
	B[len-1]=0;
}
void Int(int *A,int *B,int len){
	for (int i=1;i<len;i++) B[i]=1ll*A[i-1]*getinv(i)%Mod;
	B[0]=0;
}

void Ln(int *f,int *g,int n){
	static int A[270000],B[270000],C[270000];
	Der(f,A,n); Inv(f,B,n);
	Mul(A,B,C,n,n);
	Int(C,g,n);
}
void Exp(int *a,int *b,int n){
	static int A[270000],B[270000],t[270000];
	b[0]=1;
	for (int mid=2;mid<(n<<1);mid<<=1){
		int len=mid<<1;

		Ln(b,t,mid);
		for (int i=0;i<mid;i++)
			if (i<n) t[i]=dec(a[i],t[i]);
			else t[i]=0;
		t[0]=add(1,t[0]);

		for (int i=0;i<mid;i++) A[i]=t[i],B[i]=b[i];
		for (int i=mid;i<len;i++) A[i]=0,B[i]=0;
		for (int i=0;i<len;i++) rev[i]=(rev[i>>1]>>1)|((i&1)?mid:0);
		
		NTT(A,len,1); NTT(B,len,1);
		for (int i=0;i<len;i++) b[i]=1ll*A[i]*B[i]%Mod;
		NTT(b,len,-1);
		for (int i=mid;i<len;i++) b[i]=0;
	}
}
void Sol(int *b,int n){
	static int A[270000],B[270000];
	static int C[270000],D[270000];
	static int E[270000],F[270000];
	static int G[270000],T[270000];
	b[0]=0; b[1]=1;
	for (int mid=4;mid<(n<<1);mid<<=1){
		int len=mid<<1;
		// get 1: 1/(1-b(x))
		for (int i=0;i<mid;i++) T[i]=b[i]?Mod-b[i]:0;
		for (int i=mid;i<len;i++) T[i]=0;
		T[0]=(T[0]+1)%Mod;
		Inv(T,A,mid);
		// get 2: 1+1/(1-b(x))^2
		NTT(A,len,1);
		for (int i=0;i<len;i++) B[i]=(1ll*A[i]*A[i]+1)%Mod;
		NTT(B,len,-1);
		for (int i=mid;i<len;i++) B[i]=0;
		// get 3: x exp ((2b(x) - b(x)^2) / (2 - 2b(x)))
		for (int i=0;i<len;i++) A[i]=1ll*A[i]*inv2%Mod;
		NTT(b,len,1);
		for (int i=0;i<len;i++) C[i]=(2ll*b[i]%Mod-1ll*b[i]*b[i]%Mod+Mod)%Mod*A[i]%Mod;
		NTT(C,len,-1);
		Exp(C,D,mid);
		for (int i=mid-1;i>=1;i--) D[i]=D[i-1]; D[0]=0;
		// get 4: x exp ((2b(x) - b(x)^2) / (2 - 2b(x))) * (1 + 1 / (1 - b(x))^2) - 2
		NTT(D,len,1); NTT(B,len,1);
		for (int i=0;i<len;i++) E[i]=(1ll*D[i]*B[i]-2)%Mod;
		NTT(E,len,-1);
		// get ans:
		Inv(E,F,mid);
		for (int i=0;i<len;i++) G[i]=2ll*(D[i]-b[i]+Mod)%Mod;
		NTT(F,len,1);
		for (int i=0;i<len;i++) b[i]=(b[i]-1ll*G[i]*F[i]%Mod+Mod)%Mod;
		NTT(b,len,-1);
		for (int i=mid;i<len;i++) b[i]=0;
	}
}

int f[270000];
int main(){
	initG();
	fac[0]=1; for (int i=1;i<131072;i++) fac[i]=1ll*fac[i-1]*i%Mod;
	Sol(f,131072);
	scanf("%d",&Q);
	while (Q--){
		scanf("%d",&n);
		printf("%lld\n",1ll*f[n]*fac[n-1]%Mod);
	}
	return 0;
}
