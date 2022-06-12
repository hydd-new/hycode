#include<bits/stdc++.h>
using namespace std;
int main(){
	scanf("%d",&n); int c;
	for (int i=1;i<=n;i++){
		scanf("%d%d",&c,&s[i]);
		vec[c].push_back(i);
	}
	sort(vec[0].begin(),vec[0].end());
	sort(vec[1].begin(),vec[1].end());
	return 0;
}
