#include<vector>
#include<iostream>
using namespace std;


template<typename T>
class Heap : public vector<T> {
public:
        template<typename Func_T>
                Heap(Func_T cmp) : cmp(cmp) {}
        void push(const T &a) {
               this->push_back(a);
        }

private :
        function<bool(T,T)> cmp;
};
