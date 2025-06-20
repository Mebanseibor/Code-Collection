#include <iostream>

const int MAX_SIZE = 8;

class Stack{
    public:
    static const int capacity = MAX_SIZE;
    int arr[capacity];
    int size = 0;
    int top = -1;

    void push(int value){
        std::cout << "Attempting to push " << value << "\n";
        if(isFull()){
            std::cout << "Push operation failed: Stack is already full\n";
            return;
        }

        arr[++top] = value;
        size++;

        std::cout << "Pushed: " << value << "\n";
    }

    int pop(){
        std::cout << "Attempting to pop\n";
        if(isEmpty()){
            std::cout << "Pop operation failed: Stack is already empty\n";
            return -1;
        }

        int temp = arr[top--];
        size--;
        std::cout << "Popped: " << temp << "\n";
        return temp;
    }

    int peek(){
        std::cout << "Attempting to peek\n";
        if(isEmpty()){
            std::cout << "Peek operation failed: Stack is already empty\n";
            return -1;
        }

        int temp = arr[top];
        std::cout << "Peeked: " << temp << "\n";
        return temp;
    }

    bool isFull(){ return size==capacity; }
    bool isEmpty(){ return size==0; }
};

int main(){
    Stack stk = Stack();

    stk.pop();
    stk.peek();

    stk.push(5);
    stk.push(4);
    stk.push(2);
    stk.push(3);
    stk.push(1);
    stk.peek();
    stk.push(19);
    stk.push(8);
    stk.push(10);
    stk.push(20);

    stk.pop();
    stk.pop();
    stk.pop();
    stk.pop();
    stk.pop();
    stk.pop();

    stk.peek();

    return 0;
}
