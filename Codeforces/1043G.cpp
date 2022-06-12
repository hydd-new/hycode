#include<bits/stdc++.h>
using namespace std;
struct SA{
	void build(){
		memset(f,0,sizeof(f));
		for (int i=1;i<=n;i++) f[s[i]-'a'+1]=1;
		for (int i=1;i<=26;i++) f[i]+=f[i-1]; t=f[26];
		for (int i=1;i<=n;i++) rk[i]=f[s[i]-'a'+1];
		for (int i=1;t<n;i<<=1){
			for (int j=1;j<=n;j++) oldrk[j]=rk[j];
			for (int j=1;j<=n;j++) a[j]=j+i<=n?rk[j+i]:0;//后i位的rank
			
			memset(f,0,sizeof(f));
			for (int j=1;j<=n;j++) f[a[j]]++;
			for (int j=1;j<=t;j++) f[j]+=f[j-1];
			for (int j=1;j<=n;j++) g[f[a[j]]--]=j;//以后i位的rank为关键字的排序结果
			
			memset(f,0,sizeof(f));
			for (int j=1;j<=n;j++) f[rk[j]]++;
			for (int j=1;j<=t;j++) f[j]+=f[j-1];
			for (int j=n;j>=1;j--) sa[f[rk[g[j]]]--]=g[j];//以前i位rank为第一关键字，后i位rank为第二关键字的排序结果
			
			t=0;
			for (int j=1;j<=n;j++){
				t+=oldrk[sa[j]]>oldrk[sa[j-1]]||(oldrk[sa[j]]==oldrk[sa[j-1]]&&a[sa[j]]>a[sa[j-1]]);
				rk[sa[j]]=t;
			}
		}
		for (int j=1;j<=n;j++) sa[rk[j]]=j;
		int j=0;
		for (int i=1;i<=n;i++){
			if (rk[i]==n) j=0;
			else{
				if (j) j--;
				while (s[i+j]==s[sa[rk[i]+1]+j]) j++;
			}
			h[rk[i]]=j;
		}
		
		for (int i=1;i<=n;j++) ff[0][i]=h[i];
		for (int j=1;(1<<j)<=n;j++)
			for (int i=1;i+(1<<j)-1<=n;i++)
				ff[j][i]=min(ff[j-1][i],ff[i-1][i+(1<<(j-1))]);
	}
	int lcp(int x,int y){
		x=rk[x]; y=rk[y];
		if (x>y) swap(x,y);
		int k=Log2[y-x];
		return min(ff[k][x+1],ff[k][y-(1<<k)+1]);//+1?
	}
};
int main(){
    cin>>n>>s;
    cin>>q;
    
    return 0;
}
