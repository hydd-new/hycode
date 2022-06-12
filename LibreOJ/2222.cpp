#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int T,n,a[11000];
int main(){
	cin>>T;
	for (int Cas=1;Cas<=T;Cas++){
		cin>>n; assert(n!=-1);
		
		ll sum=0;
		for (int i=0;i<30;i++) cout<<(1<<i)<<' ',sum+=(1<<i);
		for (int i=30;i<n;i++) cout<<1000000030-i<<' ',sum+=1000000030-i; cout<<'\n';
		
		cout.flush();
		
		for (int i=0;i<n;i++){
			cin>>a[i],sum+=a[i];
			assert(a[i]!=-1);
		}
		
		assert(sum%2==0);
		sum>>=1;
		sort(a,a+n); int now=1;
		for (int i=0;i<n;i++)
			if (a[i]==now) now<<=1;
			else
				if (a[i]<=sum) sum-=a[i],cout<<a[i]<<' ';
		for (int i=0;i<30;i++)
			if ((sum>>i)&1) cout<<(1<<i)<<' ',sum-=(1<<i);
		assert(sum==0);
		cout<<'\n';
		
		cout.flush();
	}
	return 0;
}
