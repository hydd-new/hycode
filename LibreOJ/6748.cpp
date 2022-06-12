#include<bits/stdc++.h>
using namespace std;
int n,m,a[1100],b[1100];
int Ans[1100][1100];
bool check(int x,int y){
	if (Ans[x][y]||Ans[x+1][y]||Ans[x-1][y]||Ans[x][y+1]||Ans[x][y-1]) return false;
	return true;
}
bool solve(int l,int r,int s=-1){
	if (l>r) return false;
	if (s==-1) s=((r-l)&1?1:2);
	for (int i=l;i<=r;i++){
		for (int j=s;j<=n&&a[i];j+=2)
			if (check(j,i)){
				a[i]--;
				Ans[j][i]=true;
			}
		for (int j=1;j<=n&&a[i];j++)
			if (check(j,i)){
				a[i]--;
				Ans[j][i]=true;
			}
		if (a[i]) return false;
		s^=3;
	}
	return true;
}
void work1(){
	int lst=0;
	for (int i=1;i<=m;i++){
		if (a[i]>(n+1)/2){
			puts("No");
			return;
		}
		if (a[i]==(n+1)/2){
			int s=1;
			for (int j=s;j<=n&&a[i];j+=2){
				Ans[j][i]=1;
				a[i]--;
			}
			s^=3;
			if (lst){
				if (!solve(lst+1,i-1)){
					puts("No");
					return;
				}
			} else solve(1,i-1);
			lst=i;
		}
	}
	if (lst!=m) solve(lst+1,m,2);
	puts("Yes");
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			b[j]+=Ans[i][j];
			putchar(Ans[i][j]+'0');
		}
		putchar('\n');
	}
}
void work2(){
	int s=1;
	for (int i=1;i<=m;i++){
		for (int j=s;j<=n&&a[i];j+=2){
			Ans[j][i]=1;
			a[i]--;
		}
		if (a[i]){
			puts("No");
			return;
		}
		s^=3;
	}
	puts("Yes");
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			b[j]+=Ans[i][j];
			putchar(Ans[i][j]+'0');
		}
		putchar('\n');
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++) scanf("%d",&a[i]);
	if (n&1) work1();	
	else work2();
	return 0;
}
