#include<iostream>
#include<algorithm>
using namespace std;
#define  BEGIN(x) namespace x{
#define ENDS(x) } //end of namespace x
BEGIN(TEST)
    //头文件
    class Peopel{
    public :
        string name;
        int age;    

        double wight;
        double height ;
        //以上叫成员属性
        void say(string name);
        //this 可以访问到对象中的变量
        void run();
        //以上为成员方法    
    };

//按照约定， 声明的定义是分开的(也就是需要加域的限定，加上People里的say方法)
void Peopel::say(string name){
    cout << "  1 " << name <<endl;
    //this 可以访问到对象中的变量
    cout << "this name  2 " <<this-> name <<endl;
}

ENDS(TEST)
int main(){
        TEST::Peopel hug;        
        TEST::Peopel cheng;
        hug.name =" sga1";
        cheng.name = "leader xx";

        hug.say("hub");
        cheng.say("xiao zhang");

        return   0;
 }
