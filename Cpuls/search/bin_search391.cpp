//#include <iostream>
//#include <algorithm>
//#include <cstdio>
//using   namespace std;
//
//int n, m, num[100005], rows;
//
//int func(int x) {
//	int t = 0;
//	for (int i = 0; i < n; i++)
//	{
//		t += num[i] / x;
//	}
//	return t;
//} //�����ڳɲ�������
//
//int bs() {
//	int l = 1, r = rows;
//	while (l != r)
//	{
//		int mid = (l + r + 1) / 2;
//		int temp = func(mid);
//		if (temp >= m) {
//			l = mid;
//		}
//		else {
//			l = mid - 1;
//		}
//	}
//	return r;
//}//����
//
//int main()
//{
//	cin >> n >> m;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> num[i];
//		rows = max(rows, num[i]);
//	}//����߼�
//
//	cout << bs() << endl;
//	return 0;
//}
//
