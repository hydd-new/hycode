#include <bits/stdc++.h>
using namespace std;
const int K = 1000000;
int n, a[1100000];

int main() {
	scanf("%d", &n);
	int x;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &x);
		a[x]++;
	}

	int ans = 0;
	for (int i = 1; i * i <= K; i++)
		for (int j = i + 1; i * j <= K; j++)
			if (!((j - i) & 1))
				ans += a[i * j] * a[(j - i) >> 1];
	printf("%d\n", ans);
	return 0;
}