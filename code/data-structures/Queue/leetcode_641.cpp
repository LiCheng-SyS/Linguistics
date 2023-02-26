#include<iostream>
#include<vector>
using namespace std;

class MyCircularDeque {
private:
    vector<int> st;
    int front, tail, size, length;
public:
    MyCircularDeque(int k):front(1), tail(0), size(0), length(k) {
        st.resize(k);

    }

    bool insertFront(int value) {
        if (isFull()) return false;
        st[front] = value;
        front = (front + 1) % length;
        size++;
        return true;

    }

    bool insertLast(int value) {
        if (isFull()) return false;
        st[tail] = value;
        tail = (tail - 1 + length) % length;
        size++;
        return true;

    }

    bool deleteFront() {
        if (isEmpty()) return false;
        front = (front - 1 + length) % length;
        size--;
        return true;

    }

    bool deleteLast() {
        if (isEmpty()) return false;
        tail = (tail + 1) % length;
        size--;
        return true;
    }

    int getFront() {
        if (isEmpty()) return -1; 
        return st[(front - 1 + length) % length];                        
    }

    int getRear() {
        if (isEmpty()) return -1;
        return st[(tail + 1) % length];

    }

    bool isEmpty() {
        return size == 0;

    }

    bool isFull() {
        return size == length;
    }

};
