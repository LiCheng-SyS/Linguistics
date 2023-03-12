//#include <iostream>
//#include <algorithm>
//#include <math.h>
//#include <stdio.h>
//#include <cstdio>
//using   namespace std;
////382
//long long  n, m, num[100005], rawr;
//long long func(long long x) {
//	int t = 0;
//	for (int i = 0; i < n; i++)
//	{
//		//只有这样才能被切 
//		if (num[i] > x) {
//			t += num[i] - x;
//		}
//	}
//	return t;
//}
//
//long long  bs() {
//	long long  l = 0, r = rawr;
//	while (l != r)
//	{
//		long long mid = (l + r + 1) / 2;
//		long long s = func(mid);
//		if (s >= m) {
//			l = mid;
//		}
//		else {
//			r = mid - 1;
//		}
//	}
//	return l;
//}
//
//int main()
//{
//	cin >> n >> m;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> num[i];
//		rawr = max(rawr, num[i]);
//	}
//	cout << bs() << endl;
//	return 0;
//}
//
