#include<vector>
#include<iostream>
using namespace std;


int  n, num[15];
int deep=1;
void writeline(){
    for(int i=1; i<=deep; i++)
    {
        if(i!=1){
            cout << " ";
        }
        cout << num[i];
    }
    cout <<endl;
}

//进入下一层的时候让层数 ++
//回来的时候层数--
void func(int s){
    for(int i =s; i<=n ; i++){
        num[deep]=i;
        writeline();
        deep++; //触++
        func(i +1 );
        deep--; //因为要回去
    }

}

int main(){
    cin >>n;
    func(1);
    return 0;
}
