#include <iostream>
#include <algorithm>
#include <math.h>
#include <stdio.h>
#include <vector>
#include <cstdio>
using   namespace std;
//382
//long long  n, m, num[100005], rawr;
//long long func(long long x) {
//	long long  t = 0;
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



int  bs(vector<int>values,int key) {
 
	int fisrt = 0, mid = 0;
	int last = values.size() - 1;
	while (fisrt <= last)
	{

		mid = (fisrt + last) / 2;
		if (values[mid] == key)
		{
			return mid;
		}
		else if (values[mid] > key)
		{
			last = mid - 1;
		}
		else if (values[mid] < key)
		{
			fisrt = mid + 1;
		}
	}
	return -1;
}



int main()
{
	int temp = 0;
	int key = 78;
	vector<int> values;
	for (int i = 0; i < 10000; i++)
	{
		values.push_back(i);
	}
	temp =bs(values, key);
	cout << temp << endl;
	


	return 0;
}



