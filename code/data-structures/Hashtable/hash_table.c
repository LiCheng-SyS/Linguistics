#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<pthread.h>


typedef  struct Node{
    char *str;
    struct Node *next;
}Node;

typedef struct HashTable{
  Node **data;
  int size;
}HashTable;

Node *init_node(char *str,Node *head){
    Node *node =(Node *)malloc(sizeof(Node));
    node->str=strdup(str); //返回克隆的
    node->next=head;
    return node;
}

HashTable *init_hashtable(int n){
    HashTable *h=(HashTable *)malloc(sizeof(HashTable));
    h->size =n << 1;// *2
    h->data=(Node **)calloc(h->size,sizeof(Node *));
    return h;
}

int   BKDRhash(char *str){
    int seed=31,hash=0;
    for(int i=0;str[i];i++){
        hash=hash*seed+str[i];
    }
    return hash &0xfffffff;
} 


int insert(HashTable *h,char *str){
    int hash=BKDRhash(str);
    int index =hash % h->size;
    h->data[index]= init_node(str,h->data[index]);
    return 1;
}

int search(HashTable *h,char *str){
    int hash=BKDRhash(str);
    int ind =hash % h->size;
    Node *p=h->data[ind];
    while(p && strcmp(p->str,str))p=p->next;
    return p!=NULL;
}

void clear_node(Node * node){
    if(node==NULL)return;
    Node *p=node ,*q;
    while(p){
        q=p->next;
        free(p->str);
        free(p);
        p=q;
    }
    return;
}

void clear_hash_tb(HashTable *h){
    if(h==NULL)return;
    for(int i=0;i<h->size;i++){
        clear_node(h->data[i]);
    }
    free(h->data);

    free(h);
    return;
}


int main(){
  int op;
#define MAX_N 100
    char str[MAX_N+5]={0};
    HashTable *h=init_hashtable(MAX_N+5);
    while(~scanf("%d%s",&op,str)){
        switch(op){
            case 0:
                printf("insert %s to HashTable\n",str);
                insert(h,str);
                break;
            case 1:
                printf(" search %s for res %d\n",str,search(h,str));
                break;
        }
    }
#undef  MAX_N
    clear_hash_tb(h);
  return 0;
}
