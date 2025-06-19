#include <iostream>

void traverse(int arr[], int size){
    for(int i=0 ; i<size ; i++) std::cout << arr[i] << ", ";
    std::cout << "\n";
}

void insertionSort(int arr[], int size){
    for(int i=0 ; i<size-1 ; i++){
        for(int j=i+1 ; j>0 ; j--){
            if(arr[j] < arr[j-1]){
                int temp = arr[j-1];
                arr[j-1] = arr[j];
                arr[j] = temp;
                traverse(arr, size);
            }
        }
    }
}

int main(){
    int arr[5] = {3, 2, 6, 1, 5};
    int size = sizeof(arr)/sizeof(int);

    traverse(arr, size);
    insertionSort(arr, size);
    traverse(arr, size);
    return 0;
}
