#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<pthread.h>
#include<time.h>

//结构定义 
typedef  struct seqVector{
  //需要连续的存储空间
   int *data;//连续的存储空间的首地址 他是没有空间的 只是一个指针变量 所需要单独申请
   int size ,length; //size为总长度  当前空间存在的个数
}seqVector;


//这个容量大小 为n的存储空间
seqVector * init(int n){
   //申请存结构变量空间
   seqVector *v=(seqVector *)malloc(sizeof(seqVector));   //向内存申请空间并强转类型
    //动态申请空间 内存堆申请 虽然是函数内部 栈区为8mb  堆区不受8mb限制  *****和loc相关的- malloc 需要主动释放
    //free 释放   需要接受地址 address
   v->data=(int *) malloc(sizeof(int)* n); //动态申请内存区 主动申请空间传递给这个字段
   v->size=n;
   v->length=0;
   return v;
   //自此空间和字段 init 完成
}


//2 销毁操作 释放内存空间
void clear(seqVector *v){
    if(v==NULL) return;
    free(v->data);
    free(v); //如果你只释放v  只是释放顺序表
    //如 你不按照先后顺序不销毁
    //但是数组还存在,而代码无法访问v-data了
    //你整个内存泄漏了 内存实际是找不到了 os 也找不到 ,你也找不到
    return ;
}

//扩容数组长度
int expand(seqVector *v){
    //三种动态申请空间   
    //malloc ->只是申请空间 不能确定是否初始化
    //calloc ->他可以直接初始化 主动清空为0值
    //realloc ->重新分配内存
    // v->data=(int *)realloc(v->data ,sizeof(int)* (v->size *2));
    // v->size  *=2; //  *=2;
   
    int extr_size=v->size; //原来的大小
    int *p;
    while(extr_size){
        //额外空间不为0就可以扩容
        p=(int*) realloc(v->data,sizeof(int)* (v->size + extr_size));
        if(p!=NULL) break; 
        extr_size >>=1;  // /=2   这个是额外的  需要减小
    }
    if(p==NULL) return 0;
       //只要p不等于空 则可以扩容
        v->data=p;
        v->size +=extr_size;
    
    return 1;
}


//3 插入
int insert(seqVector *v, int index,int value){
    if(v==NULL){
        //初始化失败了
        return 0;
    }
    if(index <0 || index > v->length){
        return 0;
    }
    //这就是满了
    if(v->length==v->size){
        // 扩容
        if(!expand(v))return 0;
        printf("seuccess  expand size %d\n",v->size);
    }
    //先把index 空出来 向后移动
   /*
    for(int i=index;i<=v->length;i++){
        // v->data[i+1]=v->data[i];//这特么是覆盖了  全覆盖成了当前index 的值了
    }
   */
    //移动一定要从后往前
    
    for(int i=v->length;i>index;i--){
        //由于他是大于index的 所以我减一是能访到插入点的索引的
        v->data[i]=v->data[i-1];//这才是后移动
    }
    v->data[index]=value;
    v->length+=1;
    return 1;
}

int erase(seqVector *v,int index){
  if(v==NULL) return 0;
  if(index < 0 || index>=v->length)return 0;
  for(int i=index;i< v->length;i++){      
      v->data[i]=v->data[i+1];
      //从前向后移动
  }
  v->length-=1;
  return 1;
}


void output(seqVector *v){
    if(v==NULL) return ;
    printf("Vector : [");
    for(int i=0;i<v->length;i++){
        i && printf(" ");
        printf("%d",v->data[i]);
    }  
    printf("]\n");
    return ;
}
//结构操作
// 操作步骤
// 1 : 初始化  生成一个顺序表
// 2 : 销毁
// 3 : 插入
// 4:  删除
// 查询
int main()
{
    srand(time(0));
    #define MAX_OP 20
    //必须初始化随机种子
    seqVector *sq =init(MAX_OP);
    for(int i=0; i< MAX_OP;i++){
        int operators=rand()%2; //要么0 要1
        int value=rand()%100;
        int index =rand()%(sq->length+1);
     
        switch(operators){
           case 0:{
                    printf("inert %d at %d to vector%d\n",value,index,insert(sq,index,value));
                  } break;
           case 1:{
                    printf("delete %d at %d form vector ",index,erase(sq,index));
                  } break;
        }
        output(sq),printf("\n");
    } 
    #undef MAX_OP
    
    clear(sq);
    
    return 0;
}
