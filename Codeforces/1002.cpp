#include<bits/stdc++.h>
using namespace std;
const int Mod=998244353;
const int inv2=(Mod+1)/2;
int k,n,a[510000],b[510000];
void FWT(int *a,int op){
	for (int mid=1;mid<n;mid<<=1)
		for (int i=0;i<n;i+=(mid<<1))
			for (int j=0;j<mid;j++){
				int x=a[i+j],y=a[i+j+mid];
				a[i+j]=(x+y)%Mod; a[i+j+mid]=(x-y+Mod)%Mod;
				if (op==-1){
					a[i+j]=1ll*a[i+j]*inv2%Mod;
					a[i+j+mid]=1ll*a[i+j+mid]*inv2%Mod;
				}
			}
}
int main(){
	scanf("%d",&k); n=(1<<k);
	for (int i=0;i<n;i++) scanf("%d",&a[i]);
	for (int i=0;i<n;i++) scanf("%d",&b[i]);
	FWT(a,1); FWT(b,1);
	for (int i=0;i<n;i++) a[i]=1ll*a[i]*b[i]%Mod;
	FWT(a,-1);
	for (int i=0;i<n;i++) printf("%d ",a[i]);
	return 0;
}
