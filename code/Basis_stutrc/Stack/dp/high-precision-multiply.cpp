//#include<iostream>
//#include<cstring>
//using namespace std;
//
//char s1[1005], s2[1005];
//int n1[1005], n2[1005], ans[2005];
//int main() {
//	cin >> s1 >> s2;
//	n1[0] = strlen(s1), n2[0] = strlen(s2);
//	for (int i = 0, j = n1[0]; i < n1[0]; i++, j--) {
//		n1[j] = s1[i] - '0';
//
//	}
//	for (int i = 0, j = n2[0]; i < n2[0]; i++, j--) {
//		n2[j] = s2[i] - '0';
//
//	}
//	ans[0] = n1[0] + n2[0] - 1;
//	for (int i = 1; i <= n1[0]; i++) {
//		for (int j = 1; j <= n2[0]; j++) {
//			ans[i + j - 1] += n1[i] * n2[j];
//		}
//	}
//	for (int i = 1; i <= ans[0]; i++) {
//		if (ans[i] > 9) {
//			ans[i + 1] += ans[i] / 10;
//			ans[i] %= 10;
//			if (ans[0] == i) {
//				ans[0]++;
//			}
//		}
//		else if (i == ans[0] && ans[i + 1] != 0) {
//			ans[0]++;
//		}
//	}
//	for (int i = ans[0]; i > 0; i--) {
//		cout << ans[i];
//	}
//	cout << endl;
//	return 0;
//}