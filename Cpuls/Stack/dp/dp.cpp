//#include <iostream>
//using   namespace std;
//
//long long ans[25][25];
//
//int main()
//{
//	for (int i = 1; i <= 21; i++)
//	{
//		for (int j = 1; j <= 21; j++)
//		{
//			if (i == 1 && j == 1) {
//				ans[i][j] = 1;
//				continue;
//			}
//			ans[i][j] = ans[i - 1][j] + ans[i][j - 1];
//		}
//	}
//	cout << ans[21][21] << endl;
//
//	return 0;
//}



//组合排序
//long long ans[25][25];
//int main()
//{
//	long long fin = 1;
//	for (int i = 40, j = 1; i > 20; i--, j++)
//	{
//		fin*=i;
//		fin/=j;
//	}
//
//	cout << fin << endl;
//	return 0;
//}
//



