#include<bits/stdc++.h>
using namespace std;
int n,m,d1,d2,col[610][610],col2[610][610];
int cnt,dx[1100000],dy[1100000];
void dfs(int x,int y){
	int nx,ny;
	for (int i=1;i<=cnt;i++){
		nx=x+dx[i]; ny=y+dy[i];
		if (nx>=0&&nx<m&&ny>=0&&ny<m&&col[nx][ny]==-1){
			col[nx][ny]=col[x][y]^1;
			dfs(nx,ny);
		}
	}
}
void work(int d){
	cnt=0;
	for (int i=0;i<=d;i++){
		int j=sqrt(d-i*i);
		if (i*i+j*j==d){
			cnt++; dx[cnt]=i; dy[cnt]=j;
			cnt++; dx[cnt]=-i; dy[cnt]=j;
			cnt++; dx[cnt]=i; dy[cnt]=-j;
			cnt++; dx[cnt]=-i; dy[cnt]=-j;
		}
	}
	for (int i=0;i<m;i++)
		for (int j=0;j<m;j++)
			col[i][j]=-1;
	for (int i=0;i<m;i++)
		for (int j=0;j<m;j++)
			if (col[i][j]==-1){
				col[i][j]=0;
				dfs(i,j);
			}
}
void print(){
	int tot=0;
	for (int i=0;i<m;i++)
		for (int j=0;j<m;j++)
			if (!col[i][j]&&!col2[i][j]){
				printf("%d %d\n",i,j);
				tot++; if (tot==n*n) return;
			}
}
int main(){
	scanf("%d%d%d",&n,&d1,&d2); m=n*2;
	work(d1);
	for (int i=0;i<m;i++)
		for (int j=0;j<m;j++)
			col2[i][j]=col[i][j];
	work(d2);
	print();
	return 0;
}
