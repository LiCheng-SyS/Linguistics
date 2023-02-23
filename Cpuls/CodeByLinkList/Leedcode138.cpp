#include <iostream>
#include <vector>
class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
    Node *copyRandomList(Node *head)
    {
        Node *p = head, *q;
        while (p)
        {
            q = new Node(p->val);
            q->random = p->random;
            q->next = q->next;  

            p->next = q;
            p=q->next;
        }

       p= head->next;
       while (p)
       {
     
       }
       
       return p ;

    }
};

int main()
{
    Node *q = NULL;
    q= new Node(3);
    q->random=nullptr;
    
    q->next = new Node(1);
    q->random =new Node(3);


    q->next-> next = new Node(3);
    q->random=new Node(4);
    
    Node *temp=q;
    while (temp)
    {
         std:: cout << temp->val  << "  " <<  temp->random->val  <<std::endl ;
         temp= temp -> next;
    }
    std :: cout << std :: endl ;
    
    system("pause");

    return 0;
}
