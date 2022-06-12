#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int Mod=998244353;
int n,q,A,B,C,D; char s[110000],op[11];
int tot,ls[810000],rs[810000],sz[810000];
mt19937 rand_num(19260817);
struct node{
	int v[2][2];
	node operator*(const node &a) const{
		node res;
		res.v[0][0]=(1ll*v[0][0]*a.v[0][0]+1ll*v[0][1]*a.v[1][0])%Mod;
		res.v[0][1]=(1ll*v[0][0]*a.v[0][1]+1ll*v[0][1]*a.v[1][1])%Mod;
		res.v[1][0]=(1ll*v[1][0]*a.v[0][0]+1ll*v[1][1]*a.v[1][0])%Mod;
		res.v[1][1]=(1ll*v[1][0]*a.v[0][1]+1ll*v[1][1]*a.v[1][1])%Mod;
		return res;
	}
} val[810000],num[810000],W,E;
void Pushup(int x){
	sz[x]=sz[ls[x]]+1+sz[rs[x]];
	num[x]=num[ls[x]]*val[x]*num[rs[x]];
}
int Merge(int x,int y){
	if (!x||!y) return x|y;
	Pushup(x); Pushup(y);
	if (rand_num()%(sz[x]+sz[y])<sz[x]){
		rs[x]=Merge(rs[x],y); Pushup(x);
		return x;
	} else{
		ls[y]=Merge(x,ls[y]); Pushup(y);
		return y;
	}
}
void Split(int now,int k,int &x,int &y){
	if (!now){
		x=0; y=0;
		return;
	}
	if (k<=sz[ls[now]]){
		y=now;
		Split(ls[now],k,x,ls[now]);
	} else{
		x=now;
		Split(rs[now],k-sz[ls[now]]-1,rs[now],y);
	}
	Pushup(now);
}
int Newnode(int v){
	tot++;
	sz[tot]=1; val[tot]=(v?W:E); num[tot]=val[tot];
	return tot;
}
void add(int v){
	int x;
	x=Newnode(v); A=Merge(A,x);
	x=Newnode(v); B=Merge(x,B);
	x=Newnode(v^1); C=Merge(C,x);
	x=Newnode(v^1); D=Merge(x,D);
}
inline void print(){
	printf("%d %d\n",num[A].v[0][0],(num[A].v[0][0]+num[A].v[1][0])%Mod);
}
int main(){
	freopen("code.in","r",stdin);
	// freopen("code.out","w",stdout);
	scanf("%d%d",&n,&q);
	scanf("%s",s+1);
	W.v[0][0]=1; W.v[0][1]=0;
	W.v[1][0]=1; W.v[1][1]=1;
	E.v[0][0]=2; E.v[0][1]=1;
	E.v[1][0]=Mod-1; E.v[1][1]=0;
	num[0].v[0][0]=1; num[0].v[0][1]=0;
	num[0].v[1][0]=0; num[0].v[1][1]=1;
	//A 原，B 翻，C 反，D 翻反
	for (int i=1;i<=n;i++) add(s[i]=='W');
	print();
	double aaa=clock();
	int x1,x2,y1,y2,z1,z2,l,r;
	while (q--){
		scanf("%s",op);
		if (op[0]=='A'){
			scanf("%s",s); n++;
			add(s[0]=='W');
		} else{
			scanf("%d%d",&l,&r);
			if (op[0]=='F'){
				Split(A,r,y1,z1); Split(y1,l-1,x1,y1);
				Split(C,r,y2,z2); Split(y2,l-1,x2,y2);
				A=Merge(x1,y2); A=Merge(A,z1);
				C=Merge(x2,y1); C=Merge(C,z2);
				Split(B,n-l+1,y1,z1); Split(y1,n-r,x1,y1);
				Split(D,n-l+1,y2,z2); Split(y2,n-r,x2,y2);
				B=Merge(x1,y2); B=Merge(B,z1);
				D=Merge(x2,y1); D=Merge(D,z2);
			} else{
				Split(A,r,y1,z1); Split(y1,l-1,x1,y1);
				Split(B,n-l+1,y2,x2); Split(y2,n-r,z2,y2);
				A=Merge(Merge(x1,y2),z1); B=Merge(Merge(z2,y1),x2);
				Split(C,r,y1,z1); Split(y1,l-1,x1,y1);
				Split(D,n-l+1,y2,x2); Split(y2,n-r,z2,y2);
				C=Merge(Merge(x1,y2),z1); D=Merge(Merge(z2,y1),x2);
			}
		}
		print();
	}
	double bbb=clock(); cerr<<bbb-aaa<<endl;
	return 0;
}
