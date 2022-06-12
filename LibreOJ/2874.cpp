#include<bits/stdc++.h>
using namespace std;
int n,q,blo,a[110000],bel[110000],num[110000];
int L[110000],R[110000],tot[110000]; long long Ans[110000],ans;
vector<int> vec[110000];
bool cmp(int x,int y){ return R[x]<R[y];}
void add(int x){
	tot[a[x]]++;
	ans=max(ans,1ll*num[a[x]]*tot[a[x]]);
}
void del(int x){
	tot[a[x]]--;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin>>n>>q; blo=sqrt(n+0.5);
	for (int i=1;i<=n;i++){
		cin>>a[i];
		num[i]=a[i];
	}
	sort(num+1,num+n+1); int cnt=unique(num+1,num+n+1)-num-1;
	for (int i=1;i<=n;i++)
		a[i]=lower_bound(num+1,num+cnt+1,a[i])-num;
	for (int i=1;i<=n;i++) bel[i]=(i-1)/blo+1;
	for (int i=1;i<=q;i++){
		cin>>L[i]>>R[i];
		if (R[i]-L[i]<=blo){
			for (int j=L[i];j<=R[i];j++) add(j);
			Ans[i]=ans;
			for (int j=R[i];j>=L[i];j--) del(j);
			ans=0;
		} else vec[bel[L[i]]].push_back(i);
	}
	for (int i=1;i<=bel[n];i++){
		sort(vec[i].begin(),vec[i].end(),cmp);
		int d=i*blo;
		int l=d,r=d-1; ans=0;
		for (int j:vec[i]){
			while (r<R[j]) add(++r);
			long long tmp=ans;
			while (l>L[j]) add(--l);
			Ans[j]=ans;
			while (l<d) del(l++);
			ans=tmp;
		}
		while (r>=d) del(r--);
	}
	for (int i=1;i<=q;i++) cout<<Ans[i]<<endl;
    return 0;
}
