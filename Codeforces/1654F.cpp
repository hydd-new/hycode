#include<bits/stdc++.h>
using namespace std;
int n,m,p,t[1100000]; char s[1100000];
int a[1100000],b[1100000];
bool cmp(int x,int y){
	if (b[x]==b[y]) return b[x^p]<b[y^p];
	return b[x]<b[y];
}
int main(){
	cin>>n>>s; m=(1<<n);
	for (int i=0;i<m;i++) a[i]=i;
	for (int i=0;i<m;i++) b[i]=s[i]-'a';
	sort(a,a+m,cmp);
	for (int i=1;i<=n;i++){
		p=(1<<(i-1)); sort(a,a+m,cmp);
		int cnt=0;
		for (int j=0;j<m;j++)
			if (j==0||cmp(a[j-1],a[j])) t[a[j]]=++cnt;
			else t[a[j]]=cnt;
		for (int j=0;j<m;j++) b[j]=t[j];
	}
	int ans=a[0];
	for (int i=0;i<m;i++) cout<<s[i^ans];
	return 0;
}

