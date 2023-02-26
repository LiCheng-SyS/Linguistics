#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<pthread.h>

int main()
{
	union {
		int n;
		char ch;
	} data;

	int arr[] = { 0,1 };
	data.n = 0x00000001;
	if (data.ch == 1)
	{
		//printf(" ch %d\n", data.ch);
		printf("little\n");
	}
	else {
		printf("big");
	}
	int val = 321;
	//int* prt1, * prt2, * prt;
	char* prt;
	prt = (char*)&val;
	//prt1 = &arr[0];
	//prt2 = &arr[1];
	printf("addr= %p\n val=%x\n", prt, *prt);
	printf("addr= %p\n val=%x\n", prt + 1, *(prt + 1));
	printf("addr= %p\n val=%x\n", prt + 2, *(prt + 2));
	printf("addr= %p\n val=%x\n", prt + 3, *(prt + 3));
	//printf("addr %p\n val=%x\n", prt1);
	//printf("addr %p\n val=%x\n", prt2);
	printf("addr =%p", prt);

	return 0;
}
