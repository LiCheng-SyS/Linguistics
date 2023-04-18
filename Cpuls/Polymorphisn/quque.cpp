#include<iostream>
#include<cmath>
#include<vector>
#include<set>
#include<map>
#include<stack>
#include<algorithm>
#include<cstdlib>
#include "Quque.h" 
using namespace std;

class Queue : public IQueue {
public:
    Queue(int n = 10):arr( vector<int>(n)),head(0),tail(0),__size(n),count(0){}
    void push(int x ) override{
        if(count  == __size){
            expand();
        }  
        cout <<" push succ "<<endl;
        arr[tail++] =x;
        tail %=__size;
        __size+=1;
    };
    int  front() override{
        return arr[head];        
    };

    int top() override{
        return arr[head];
    };
    
    void pop() override{
        if(empty()) return ; 
        cout << "pop succ "<< endl; 
        head += 1;
        head %=   __size  ; 
        return ; 
    };
    
    bool full()override{
        return tail == arr.size();
    };
    
    int get_size()override{
        return __size ;
    };
    
    bool empty() override{return  count ==0;};

    void output(){
        cout   << "head  : " <<  head << "   " << tail <<endl;
        for(int i =head ;i <= tail ;i++){
            cout <<  arr[i] <<  " ";
        }
        cout  << endl;
        return;
    }
private:
    vector<int> arr;
    int  count=0 ,  head =0,tail= 0 ,__size ;
};
int main(){
    Queue x ; 
    x.push(11111);
    x.push(1232122);
    x.push(2122);
    x.pop();

    x.output();
    return 0;
}
