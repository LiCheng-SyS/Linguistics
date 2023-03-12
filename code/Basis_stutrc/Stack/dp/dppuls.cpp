//#include <iostream>
//#include <cstdio>
//using   namespace std;
//
//int n, m, num[1000][1000], utp[1005][1005], dtu[1005][1005], ans[1005][1005], maxid[1005], max2[1005];
//int main()
//{
//	scanf("%d%d", &n, &m);
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1; j < i; j++)
//		{
//			scanf("%d", &num[i][j]);
//		}
//	}
//
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1; j < i; i++)
//		{
//			utp[i][j] = max(utp[i - 1][j - 1], utp[i - 1][j]) + num[i][j];//num[i][j] 这个本身的值
//		}
//	}
//
//
//	//从下往上
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1; j < i; i++)
//		{
//			dtu[i][j] = max(dtu[i + 1][j + 1], dtu[i + 1][j]) + num[i][j];
//		}
//	}
//
//
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1; j <= i; j++)
//		{
//			ans[i][j] = utp[i][j] + dtu[i][j] - num[i][j];
//		}
//	}
//
//	for (int i = 1; i < n; i++)
//	{
//		int t1 = 0, t2 = 0, mid = 0;
//		for (int j = 1; i <= i; j++)
//		{
//			if (t1 < ans[i][j]) {
//				t2 = t1;
//				t1 = ans[i][j];
//				mid = j;
//			}
//			else  if (t2 < ans[i][j]) {
//				t2 = ans[i][j];
//			}
//			maxid[i] = t1, maxid[i] = mid, max2[i] = t2;
//		}
//	}
//
//	for (int i = 0; i <= m; i++)
//	{
//		int x, y;
//		scanf("%d%d", &x, &y);
//		if (x == 1) {
//			printf("1\n");
//		}
//		else if (maxid[x] == y) {
//			printf("%d\n", max2[x]);
//		}
//		else {
//			printf("%d\n", maxid[x]);
//		}
//	}
//	return 0;
//}
//
//
//
