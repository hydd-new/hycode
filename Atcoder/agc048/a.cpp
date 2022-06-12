#include<bits/stdc++.h>
using namespace std;
const char t[8]={'a','t','c','o','d','e','r',0};
int T,n; char s[1100];
int main(){
	scanf("%d",&T);
	while (T--){
		for (int i=0;i<8;i++) s[i]=0;
		scanf("%s",s); n=strlen(s);
		bool flag=false;
		for (int i=0;i<8;i++)
			if (t[i]!=s[i]){
				flag=(t[i]<s[i]);
				break;
			}
		if (flag){ puts("0"); continue;}
		int pos=-1;
		for (int i=0;i<n;i++)
			if (s[i]!='a'){
				pos=i;
				break;
			}
		if (pos==-1){ puts("-1"); continue;}
		printf("%d\n",pos-1+(s[pos]<='t'));
	}
	return 0;
}