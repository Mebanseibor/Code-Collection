#include <iostream>

void traverse(int arr[], int size){
    for(int i=0 ; i<size ; i++) std::cout << arr[i] << ", ";
    std::cout << "\n";
}

void bubbleSort(int arr[], int size){
    for(int i=0 ; i<size ; i++) {
        for(int j=0 ; j<size-i-1 ; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
            traverse(arr, size);
        }
    }
}

int main(){
    int arr[5] = {3, 2, 6, 1, 5};
    int size = sizeof(arr)/sizeof(int);

    traverse(arr, size);
    bubbleSort(arr, size);
    traverse(arr, size);

    return 0;
}
