//#include <iostream>
//#include <cstring>
//using namespace std;
//
//char s1[1005], s2[1005];
//int num1[1005], num2[1005], sum[1005];
//int main() {
//	cin >> s1 >> s2;
//	num1[0] = strlen(s1);
//	num2[0] = strlen(s2);
//
//	//数字数组的下表 j；
//	for (int i = 0, j = num1[0]; s1[i]; i++, j--) {
//		num1[j] = s1[i] - '0';  //必须减去0才能获得字符的值； 
//	}
//
//	for (int i = 0, j = num2[0]; s2[i]; i++, j--) {
//		num2[j] = s2[i] - '0';
//	}
//
//	sum[0] = max(num1[0], num2[0]);
//	for (int i = 1; i <= sum[0]; i++) {
//		sum[i] = num1[i] + num2[i];
//	}
//
//	//进位
//	for (int i = 1; i <= sum[0]; i++) {
//		cout << sum[i] << endl;
//		if (sum[i] > 9) {
//			sum[i + 1] += sum[i] / 10;
//			sum[i] %= 10;
//			if (i == sum[0]) {
//				sum[0]++;
//			}
//		}
//	}
//
//	//倒着输出
//	for (int i = sum[0]; i > 0; i--) {
//		cout << sum[i];
//	}
//	cout << endl;
//	return 0;
//}