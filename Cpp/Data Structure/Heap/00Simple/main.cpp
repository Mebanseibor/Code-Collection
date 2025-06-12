#include <iostream>

const int HEAP_SIZE = 16;

class Heap{
    public:
    int size = 0;
    int arr[HEAP_SIZE] = {-1};

    void insert(int value){
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

    void heapifyDown(){
        int index = 0;
        while(true){
            int left = 2*index+1;
            int right = 2*index+2;
            int highest = index;
            if(left<size && arr[left]>arr[highest]) highest = left;
            if(right<size && arr[right]>arr[highest]) highest = right;
            
            if(highest!=index){
                int temp = arr[index];
                arr[index] = arr[highest];
                arr[highest] = temp;
                index = highest;
            }
            else break;

            display();
        }
    }

    void extract(){
        if(size==0) return;

        arr[0] = arr[size-1];
        size--;

        heapifyDown();
        std::cout << "\n";
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

    h.insert(10);
    h.insert(2);
    h.insert(6);
    h.insert(12);

    h.extract();
    h.display();

    return 0;
}
