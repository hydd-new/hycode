#include <bits/stdc++.h>
using namespace std;
int n;
char s[110000], t[110000];

int main() {
	scanf("%s", s + 1);
	scanf("%s", t + 1);
	n = strlen(s + 1);
	int j;

	j = 1;
	for (int i = 1; i <= n; i++)
		if (j <= n && t[i] == s[j])
			j += 2;
	if (j > n) {
		puts("Yes");
		return 0;
	}

	j = 2;
	for (int i = 1; i <= n; i++)
		if (j <= n && t[i] == s[j])
			j += 2;
	if (j > n) {
		puts("Yes");
		return 0;
	}

	puts("No");
	return 0;
}