#include<iostream>
using namespace std;




int data[10];
int next_p[10];
void LinkListadd(int index,int p,int value){
       next_p[index]=p;
       data[p]=value;
}


int main(){

   int  head =3 ;
   data[3]=0;
   //头节点是
   LinkListadd(3,5,1);
   LinkListadd(2,7,3);
   LinkListadd(5,2,2);
   LinkListadd(7,9,100);
  
        int p =head;
        while(p!=0)
        {
            cout <<  " -> " << data[p]<<  endl;
            p=next_p[p];                                  
        }
         cout << endl;

   return 0;
}                             
                                                                        
                                                                                    // 第二个是下一个节点 ,最后一个是值
                                                                                            
                            
                                                                                                    
                                                                                                            
