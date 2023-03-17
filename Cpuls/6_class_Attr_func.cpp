#include<iostream>
#include<queue>
#include<cmath>
#include<vector>
#include<set>
#include<map>
#include<stack>
#include<algorithm>

using namespace std;

class People{
public:
    People(){  x= 23800; }
    void say()const {
        cout << x << endl;
    }
    void run();
    string &name() const;
    static void is_signed_height(double height);
private:
    static int total_num;
    int x ;
    string __name;
    double __height;
    double __weight;
};

int main(){
    const  People a;
    a.say();
    return 0;
}
