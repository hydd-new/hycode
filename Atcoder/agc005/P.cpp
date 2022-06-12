#include<bits/stdc++.h>
using namespace std;
int n; char s[110000];
vector<int> L,R;
int main(){
	scanf("%d",&n);
	scanf("%s",s+1);
	for (int i=n;i>=1;i--)
		if (s[i]=='<') R.push_back(i);
	int ans=0;
	for (int i=1;i<=n;i++){
		int now=-1;
		if (s[i]=='<'){
			R.pop_back();
			if (!L.size()) now=i; 
			else if (L.size()<=R.size()) now=R[R.size()-L.size()];
			else now=n-L[L.size()-R.size()-1]+1;
		}
		if (s[i]=='>'){
			if (!R.size()) now=n-i+1;
			else if (R.size()<=L.size()) now=n-L[L.size()-R.size()]+1;
			else now=R[R.size()-L.size()-1];
			L.push_back(i);
		}
		ans=max(now,ans); //printf("%d\n",now);
	}
	printf("%d\n",ans);
	return 0;
}