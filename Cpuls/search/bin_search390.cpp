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
//int n, m;//n ����  m��ѯ��
//
//bool cmp(const node& a, const node& b) {
//	return a.cnt < b.cnt;
//}
//
//
////���ֲ���  --<ǰ������� �����
//int main()
//{
//	scanf("%d%d", &n, &m);
//	for (int i = 0; i < n; i++)
//	{
//		scanf("%d", &wm[i].cnt);//i�Ѹ����ϵ�������
//		wm[i].num = i + 1;//���
//	}
//
//	sort(wm, wm + n, cmp); //�϶ѵ�������������
//	for (int i = 0; i < m; i++)
//	{
//		int  t = 0, l = 0, r = n - 1, f = 0;
//		scanf("%d", &t);
//		while (l <= r)  //����ָ��С�� ��ָ�� ������������
//		{
//			int mid = (l + r) / 2;
//			if (wm[mid].cnt == t)
//			{
//				//�ҵ���
//				f = 1;
//				printf("%d\n", wm[mid].num);
//				break;
//			}//�����������
//			else if (wm[mid].cnt > t) {
//				//���ݴ���-->�����ƶ�
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
