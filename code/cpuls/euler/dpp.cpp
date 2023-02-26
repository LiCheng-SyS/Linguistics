#include <iostream>
#include <cstdio>
using   namespace std;

int n, ans[1000][1000];
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			scanf("%d", &ans[i][j]);
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			ans[i][j] += max(ans[i - 1][j - 1], ans[i - 1][j]);
		}
	}

	int t = 0;
	for (int i = 1; i <=n; i++)
	{
		t = max(t, ans[n][i]);

	}
	printf("%d\n", t);
	return 0;
}

