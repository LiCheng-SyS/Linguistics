//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//#include <algorithm>
//#include <cstdio>
//using   namespace std;
//
//struct node
//{
//	int num, cnt;
//};
//
//node wm[100005];
//int n, m;//n 个瓜  m次询问
//
//bool cmp(const node& a, const node& b) {
//	return a.cnt < b.cnt;
//}
//
//
////二分查找  --<前提必须是 有序的
//int main()
//{
//	scanf("%d%d", &n, &m);
//	for (int i = 0; i < n; i++)
//	{
//		scanf("%d", &wm[i].cnt);//i堆个西瓜的数量里
//		wm[i].num = i + 1;//编号
//	}
//
//	sort(wm, wm + n, cmp); //瓜堆的数量则有序了
//	for (int i = 0; i < m; i++)
//	{
//		int  t = 0, l = 0, r = n - 1, f = 0;
//		scanf("%d", &t);
//		while (l <= r)  //当左指针小于 右指针 还可以往下找
//		{
//			int mid = (l + r) / 2;
//			if (wm[mid].cnt == t)
//			{
//				//找到了
//				f = 1;
//				printf("%d\n", wm[mid].num);
//				break;
//			}//调整左或者右
//			else if (wm[mid].cnt > t) {
//				//数据大了-->超右移动
//				r = mid - 1;
//			}
//			else {
//				l = mid + 1;
//			}
//		}
//
//		if (f == 0) {
//			printf("0\n");
//		}
//
//	}
//	return 0;
//}
//
