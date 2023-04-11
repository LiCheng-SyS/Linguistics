#include<iostream>
#include<queue>
#include<cmath>
#include<vector>
#include<set>
#include<map>
#include<stack>
#include<algorithm>
  
using namespace std;

class tc{
public : 
    tc(string name ): name(name){
        cout  << " construct "<< name << endl; 
    }
    string name;
};
  
int main(){

    tc c1(" x");
    return 0;
}
