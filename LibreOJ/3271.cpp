#include<bits/stdc++.h>
using namespace std;
const int N=1100000;
const int INF=0x3f3f3f3f;
int n,m,a[N][2],R[N][2],L[N][2]; char c[N];
int main(){
	cin>>m; n=m<<1;
	for (int j=0;j<=1;j++)
		for (int i=1;i<=n;i++)
			cin>>a[i][j];
	for (int i=1;i<=n;i++)
		for (int j=0;j<=1;j++){
			L[i][j]=INF; R[i][j]=-INF;
			for (int k=0;k<=1;k++)
				if (a[i][j]>=a[i-1][k]){
					L[i][j]=min(L[i][j],L[i-1][k]+j);
					R[i][j]=max(R[i][j],R[i-1][k]+j);
				}
		}
	int t=INF; string Ans;
	for (int i=n;i>=1;i--){
		char res=0;
		for (int j=0;j<=1;j++)
			if (L[i][j]<=m&&R[i][j]>=m&&t>=a[i][j]){
				res='A'+j;
				t=a[i][j]; m-=j;
			}
		if (!res){ cout<<"-1\n"; return 0;}
		Ans.push_back(res);
	}
	reverse(Ans.begin(),Ans.end());
	cout<<Ans<<endl;
	return 0;
}
