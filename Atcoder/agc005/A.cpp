#include<bits/stdc++.h>
using namespace std;
int n; char s[210000];
int main(){
	scanf("%s",s+1); n=strlen(s+1);
	int tot=0,ans=n;
	for (int i=1;i<=n;i++)
		if (s[i]=='S') tot++;
		else
			if (tot) tot--,ans-=2;
	printf("%d\n",ans);
	return 0;
}
