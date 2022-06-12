#include<bits/stdc++.h>
using namespace std;
// a = cos x + i sin x
// 1 + a^1 + a^2 + ... + a^(n-1) = 0
// a^1 + a^2 + ... + a^(n-1) + a^n = 0
// a^n = 1
// (cos x + i sin x)^n = 1
// cos nx = 1, sin nx = 0 (De Moivre's formula)
// nx = 2kpi
int x;
int main(){
	scanf("%d",&x);
	for (int n=1;;n++)
		if (n*x%360==0){
			printf("%d\n",n);
			break;
		}
	return 0;
}