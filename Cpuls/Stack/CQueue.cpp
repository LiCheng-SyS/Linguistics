class CQueue {
public:
    stack<int> inlist, outlist;
    // s2为入栈的集合 ，s1为模拟队列出栈的集合
    CQueue() {}
    
void  tansferStack(){
        //inlist->outlist转移
         if(!outlist.empty()) return;
         
         if(outlist.empty()){
            while(!inlist.empty()){
                outlist.push(inlist.top());
                inlist.pop();
             }
         }
         return;
    }

    void appendTail(int value) {
        inlist.push(value);
        return;
    }

    int deleteHead() {
         tansferStack();
         int ret = outlist.top();
         outlist.pop();
         return ret;
    }
};

int main(){
    
}