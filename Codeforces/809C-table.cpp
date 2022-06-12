#include<bits/stdc++.h>
using namespace std;
bool vis[21000];
int a[110][110];
int main(){
	int n=20;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			a[i][j]=1;
			for (int i=1;i<=n+n;i++) vis[i]=false;
			for (int k=1;k<i;k++) vis[a[k][j]]=true;
			for (int k=1;k<j;k++) vis[a[i][k]]=true;
			while (vis[a[i][j]]) a[i][j]++;
			printf("%3d ",a[i][j]-1);
		}
		puts("");
	}
	return 0;
}
