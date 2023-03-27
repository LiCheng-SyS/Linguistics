#include<iostream>
#include<queue>
#include<cmath>
#include<vector>
#include<set>
#include<map>
#include<stack>
#include<algorithm>
#include <memory>
using namespace std;
// 模板库的 <memory> 头文件中定义的智

#define BEGINS(x) namespace x {
#define  ENDS(x) }   // end of namespace x 
BEGINS(test1)
    class A{
    public :
        int i; 
        A(){}
        A(int n):i(n) {
            cout <<"default construct "  << i <<endl;
        }
        ~A(){
            cout <<"reaelse construct " <<endl;
        }
        shared_ptr<A> p ; 
    private:
    };
int main(){
    //将A类的对象,存在p指针中
    //A *p =new A();

    // 指向A类型的智能指针|对象调用A对象的构造函数，申请一个A对象  
    shared_ptr<A> p =    make_shared<A>(4);
    // 查看引用计数  成员use_count
    cout << "use_count " << p.use_count()  << endl;
    cout<< " load succ"<< p->i << endl ; 
    shared_ptr<A> q =p;
    cout << "new p  use_count " << p.use_count()  << endl;
    cout << "new q  use_count " << q.use_count()  << endl;
    q =nullptr;
    cout << "q  use_count " << q.use_count()  << endl;
    cout <<"end main " <<endl;
    //如果不想发生内存泄露，原生指针，就必须delete 



    cout << " --------------------------------------"  <<endl;
    //环形引用
    shared_ptr<A> x1 = make_shared<A>(10);
    shared_ptr<A> xx= x1;
    x1 = xx;
    x1 = nullptr;
    cout <<"xx : " <<xx.use_count()<< endl;
    cout <<"x1 : " <<x1.use_count()<< endl;
    return 0;
}
ENDS(test1);


BEGINS(test2)
    class A{
    public :
        int i; 
        A(){}
        A(int n):i(n) {
            cout <<"default construct "  << i <<endl;
        }
        ~A(){
            cout <<"reaelse construct " <<endl;
        }
        shared_ptr<A> p ; 
    private:
    };
int main(){

    shared_ptr<A> p =make_shared<A>(10); 
    shared_ptr<A> q =make_shared<A>(10); 

    p->p = q; 
    q->p = p;


    cout << q.use_count() <<endl;
    cout << p.use_count() <<endl;
    p = nullptr ;
    q = nullptr ;

    cout << p.use_count() <<endl;
    cout << q.use_count() <<endl;
    cout << "end main " <<endl;
    return 0;
}
ENDS(test2)

BEGINS(test3)

class A{
    public :
        int x , y; 
        A(){
            cout <<"default construct " <<endl;
        }
        ~A(){
            cout <<"reaelse construct " <<endl;
        }
    private:
 };

class ptr_data{
public :
    ptr_data(A *prt , int *cnt =nullptr)
    :prt(prt),cnt(cnt){
        if(this->cnt ==nullptr ) this->cnt =new int(1);
    }
    void incnrease_one()const{
        *cnt +=1;
        return ;
    }
    void decrease_one()const{
        *cnt -=1;
        if(*cnt ==0) delete  prt;
        return ;
    }
    bool operator==(const ptr_data &p)const{
        return p.prt ==prt && p.cnt ==cnt;
    }
    ~ptr_data(){
         decrease_one();
         if(*cnt ==0)delete cnt;
    }
    A *prt;
    int *cnt ;
};

class share_prt{
public  :
    share_prt(A *prt):p(prt){}       // 将 ptr 对象进行init 
    //间接引用是指针对象
    A *operator->(){ return p.prt; }
    A &operator*(){
        return *(p.prt);
    }
    //智能指针如果要拷贝,引用计数+1 
    share_prt(const share_prt &obj): p(obj.p){
        p.incnrease_one();
    }
    share_prt &operator=(const share_prt &obj){
        if(obj.p==p)  return *this;
        obj.p.decrease_one();
        p = obj.p;
        p.incnrease_one();
        return *this;
    }
    ~share_prt(){
        p.decrease_one();
    }
    int use_count(){
        return  *p.cnt;  
    }

private :
    ptr_data p;
};

//首先就是构造一个对象 ，不然玩不下去
share_prt make_shared(){
    return   share_prt(new A());
}
ostream &operator<<(ostream &out , const A&a){
    out <<  "class A" << a.x << a.y  <<endl;
    return out;
}
int main(){
    share_prt p =make_shared();
    p->x = 4 ,p->y =2;
    cout << *p << endl;
    cout  << "p.usecount " <<p.use_count() <<endl;

    share_prt q = p;
    cout  << "p.usecount " <<p.use_count() <<endl;
    cout  << "q.usecount " <<q.use_count() <<endl;

    p=nullptr;
    cout  << "q.usecount " <<q.use_count() <<endl;
    q= nullptr;
    cout  << "p.usecount " <<p.use_count() <<endl;
    cout  << "end main" << endl;
    return 0;
}


ENDS(test3)
    int main(){
        test2:: main();
        return 0; 
    }
