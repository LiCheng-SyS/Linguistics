#include <iostream>
#include <vector>

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};


ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
       if(list1==NULL) return list2;
       if(list2==NULL) return list1;
       
       if(list2->val <= list1->val){
          list1=mergeTwoLists(list1->next,list2);
       }

}


int mian(){

    return 0;
}