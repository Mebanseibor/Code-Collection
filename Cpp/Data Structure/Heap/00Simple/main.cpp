#include <iostream>
#include <cmath>

const int HEAP_SIZE = 16;

class Heap{
    public:
    int size = 0;
    int arr[HEAP_SIZE] = {-1};

    void add(int value){
        if(size == HEAP_SIZE){
            std::cout << "Max Heap Size reached\n";
            return;
        };
        arr[size] = value;
        size++;

        display();
        heapify(size-1);
        std::cout << "\n";
    };

    void heapify(int index){
        while(index > 0){
            int parent = (index-1)/2;

            if(arr[index]<=arr[parent]) break;

            int temp = arr[parent];
            arr[parent] = arr[index];
            arr[index] = temp;

            index=parent;
            parent/=2;

            display();
        }
    }

    void display(){
        for(int i=0 ; i<size ; i++){
            std::cout << arr[i] << ", ";
        }
        std::cout << "\n";
    }
};

int main(){
    Heap h = Heap();

    h.add(10);
    h.add(2);
    h.add(6);
    h.add(12);
    h.add(14);

    return 0;
}
