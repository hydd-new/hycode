#include<bits/stdc++.h>
using namespace std;
const int lim=100004;
int n,m,a[110000],bel[110000]; bool Ans[110000];
struct node{
	int op,l,r,x,id;
	bool operator<(const node &a) const{
		return bel[l]<bel[a.l]||bel[l]==bel[a.l]&&r<a.r;
	}
} q[110000];
bitset<100005> A,B; int C[110000];
bool query(int op,int x){
	if (op==1) return (A&(A>>x)).any();
	if (op==2) return (A&(B>>(lim-x))).any();
	if (!x) return C[0];
	for (int i=1;i*i<=x;i++)
		if (x%i==0&&C[i]&&C[x/i]) return true;
	return false;
}
void add(int x){
	C[x]++;
	A.set(x); B.set(lim-x);
	A[x]=1; B[lim-x]=1;
}
void del(int x){
	C[x]--;
	if (!C[x]){
		A.reset(x); B.reset(lim-x);
	}
}
int main(){
	scanf("%d%d",&n,&m); int blo=sqrt(n);
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		bel[i]=(i-1)/blo+1;
	}
	for (int i=1;i<=m;i++){
		scanf("%d%d%d%d",&q[i].op,&q[i].l,&q[i].r,&q[i].x);
		q[i].id=i;
	}
	sort(q+1,q+m+1);
	
	int l=1,r=0;
	for (int i=1;i<=m;i++){
		while (r<q[i].r) add(a[++r]);
		while (l>q[i].l) add(a[--l]);
		while (r>q[i].r) del(a[r--]);
		while (l<q[i].l) del(a[l++]);
		Ans[q[i].id]=query(q[i].op,q[i].x);
	}
	for (int i=1;i<=m;i++)
		if (Ans[i]) puts("yuno");
		else puts("yumi");
	return 0;
}
