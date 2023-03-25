#include<iostream>
#include<queue>
#include<cmath>
#include<vector>
#include<set>
#include<map>
#include<stack>
#include<algorithm>
#include<functional>  

#define BEGINS(x) namespace x{
#define ENDS(x)} 
using namespace std;

BEGINS(test1)

    void output(int *arr,int *out,string xx ){
        cout << xx << "  " ;
        while(arr !=out){
            cout << *arr  << "   ";
            ++arr;
        }
        cout << endl;
        return ;
    }
bool cmp1(const int  &a,const int &b){
    return a > b ;
}
class CMP{
public : 
    bool operator()(const int &a, const int &b){
        return a  >  b;
    }
};
int main(){
    int arr[100], n ; 
    cin >> n ;
    for(int i =0; i < n ; i++){
        cin >> arr[i];
    }
    sort(arr , arr+n );
    output(arr , arr +n ," none ");

    sort(arr , arr+n ,cmp1);
    output(arr , arr + n ," cmp1 ");

    CMP cmp2;
    sort(arr , arr + n ,cmp2);
    output(arr, arr+n, " CMP2 ");

    //STL sort 可以传一个函数对象,也可以直接传函数
    cout << endl;
    return 0;
}
ENDS(test1)

BEGINS(test2)

    void output(int *arr,int *out,string xx ){
        cout << xx << "  " ;
        while(arr !=out){
            cout << *arr  << "   ";
            ++arr;
        }
        cout << endl;
        return ;
    }
bool cmp1(const int  &a,const int &b){
    return a > b ;
}
class CMP{
public : 
    bool operator()(const int &a, const int &b){
        return a  >  b;
    }
};
void sort(int* first, int* last, function<bool(int, int)>func = less<int>()) {
	//要排首先得查区间是否为空
     if (first >= last) return;
	int* x = first, *y= last - 1, z = *first;
	//first <  last  证明还可以继续调整
	while (x < y) {
		//z 为基准值,尾指针的值小于基准值则向前调整,比基准值大的都在向左侧移动 
		while (x < y && func(z, *y)) --y;
		//当首指针<尾指针，下一位的值=尾指针
		if (x < y) (*x++) = *y;
		while (x < y && func(*x, z)) ++x;
		if (x < y) (*y--) = *x;
	}
    //将首地址拉到基准值这里来
    *x = z;
	sort(first + 1, x, func); //< 小于基准值调整 ， 
	sort(x + 1,last ,func);//  >大于基准值的调整
    return ;
}
int main(){
    int arr[100], n ; 
    cin >> n ;
    for(int i =0; i < n ; i++){
        cin >> arr[i];
    }
    sort(arr , arr + n );
    output(arr , arr + n ," none ");

    sort(arr , arr+n ,cmp1);
    output(arr , arr + n ," cmp1 ");

    CMP cmp2;
    sort(arr , arr + n ,cmp2);
    output(arr, arr+n, " CMP2 ");

    //STL sort 可以传一个函数对象,也可以直接传函数
    cout << endl;
    return 0;
}
ENDS(test2)

BEGINS(test3)
class RandomIter {
public:
	RandomIter(int* prt) :ptr(ptr) {}
	int& operator*() { return *ptr; }
	RandomIter operator-(int x ) {return ptr - x;}
	RandomIter operator+(int x) { return ptr + x; }

	int operator-(const RandomIter& iter) { return ptr - iter.ptr; }
	
	RandomIter& operator++() { ++ptr; return *this; }
	RandomIter& operator--() { --ptr; return *this; }

	bool operator<(const RandomIter& iter)const {
		return (ptr < iter.ptr);
	}

	bool operator>(const RandomIter& iter)const {
		return (iter < *this);
	}

	bool operator==(const RandomIter& iter) const {
		return !(*this < iter) && !(*this > iter);
	}

	bool operator!=(const RandomIter& iter)const {
		return !(*this == iter);
	}

	bool operator<=(const RandomIter& iter)const {
		return !(*this > iter);
	}

	bool operator>=(const RandomIter& iter)const {
		return !(*this < iter);
	}

private:
	int* ptr;
};
void output(int* arr, int* out, string xx) {
	cout << xx << "  ";
	while (arr != out) {
		cout << *arr << "   ";
		++arr;
	}
	cout << endl;
	return;
}
bool cmp1(const int& a, const int& b) {
	return a > b;
}
class CMP {
public:
	bool operator()(const int& a, const int& b) {
		return a > b;
	}
};

const int  threshold = 16;
void intro_loop(RandomIter first, RandomIter last, function<bool(int, int)>func = less<int>()) {
	//要排首先得查区间是否为空
	while (last - first > threshold) {
		RandomIter x = first,  y = last - 1;
		int	z = *first;
		do {
			while (func(*x, z)) ++x;
			while (func(z, *y)) --y;
			if (x <= y) {
				swap(*x, *y);
				++x, --y;
			}
		} while (x <= y);
		intro_loop(x, last, func);
		last = y + 1;
	}
	return;
}
void insertion_sort(RandomIter first, RandomIter last, function<bool(int, int)>func = less<int>()) {
	RandomIter ind = first;
	for (RandomIter x = first + 1; x < last; ++x) {
		if (func(*x, *ind))
			ind = x;
	}
	while (ind != first) {
		swap(*ind, *(ind - 1));
		--ind;
	}
	for (RandomIter x= first + 2; x < last; ++x) {
		RandomIter j = x;
		while (func(*j, *(j - 1)))
		{
			swap(*j, *(j - 1));
			--j;
		}
	}
	return;
}
void sort(RandomIter first, RandomIter last, function<bool(int, int)>func = less<int>()) {
	intro_loop(first, last, func);
	insertion_sort(first, last, func);
	return;
}
int main() {
	int arr[100], n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	output(arr, arr + n, " none ");

	sort(arr, arr + n, cmp1);
	output(arr, arr + n, " cmp1 ");

	CMP cmp2;
	sort(arr, arr + n, cmp2);
	output(arr, arr + n, " CMP2 ");

	//STL sort 可以传一个函数对象,也可以直接传函数
	cout << endl;
	return 0;
}
ENDS(test3)

int main(){
      test2::main();
      return 0;
 }
