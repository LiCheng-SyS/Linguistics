#ifndef __priority_quque_H__
#define __priority_quque_H__

//定义接口类
class IQueue{
 public:
    virtual bool full()= 0; 
    virtual void push(int) = 0;
    virtual void pop() = 0;
    virtual int  get_size() = 0;
    virtual bool empty() = 0;
    virtual int top() = 0;
    virtual int front() = 0;

    virtual ~IQueue(){}
};


#endif
