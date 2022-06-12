#include<bits/stdc++.h>
using namespace std;
int n; char s[1100000];
int a[1100000],ans;
int main(){
	scanf("%d",&n);
	scanf("%s",s);
	if (n==1){ putchar(s[0]); return 0;}
	int flag=1;
	for (int i=0;i<n;i++){
		a[i]=s[i]-'1';
		if (a[i]==1) flag=0;
	}
	for (int i=0;i<n;i++)
		if (((n-1)&i)==i) ans^=((a[i]>>flag)&1); 
	printf("%d\n",(ans<<flag));
	return 0;
}