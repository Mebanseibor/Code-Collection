#include <iostream>

class Queue{
    public:
    static const int capacity = 8;
    int arr[capacity];
    int size = 0;

    Queue(){}

    void enqueue(int value){
        std::cout << "Attempting to enqueue:\t" << value << "\n";
        if(isFull()){
            std::cout << "Enqueue operation failed: Queue is full\n";
            return;
        }

        arr[size] = value;
        size++;
        std::cout << "Enqueued:\t" << value << "\n";
    }

    int dequeue(){
        std::cout << "Attempting to dequeue:\n";
        if(isEmpty()){
            std::cout << "Dequeue operation failed: Queue is empty\n";
            return -1;
        }

        int temp = arr[0];

        for(int i=0 ; i<size-1 ; i++){ arr[i] = arr[i+1]; }

        size--;
        std::cout << "Dequeued:\t" << temp << "\n";
        return temp;
    }

    int peek(){
        std::cout << "Attempting to peek:\n";
        if(isEmpty()){
            std::cout << "Peek operation failed: Queue is empty\n";
            return -1;
        }

        std::cout << "Peek:\t" << arr[0] << "\n";
        return arr[0];
    }

    bool isFull() { return size==capacity; }
    bool isEmpty() { return size==0; }
};

int main(){
    Queue q = Queue();

    q.dequeue();
    q.peek();

    q.enqueue(5);
    q.enqueue(3);
    q.enqueue(8);
    q.enqueue(2);
    q.enqueue(3);
    q.peek();

    q.dequeue();
    q.peek();

    q.enqueue(50);
    q.enqueue(80);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(90);
    q.enqueue(510);
    q.enqueue(320);
    q.enqueue(190);

    q.peek();

    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();

    return 0;
}
