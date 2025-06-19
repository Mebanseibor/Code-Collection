#include <iostream>

void traverse(int arr[], int size){
    for(int i=0 ; i<size ; i++) std::cout << arr[i] << ", ";
    std::cout << "\n";
}

void selectionSort(int arr[], int size){
    for(int i=0 ; i<size-1 ; i++){
        int indexLowest = i;

        for(int j=i+1 ; j<size ; j++){
            if(arr[j] < arr[indexLowest]){ indexLowest = j; }
        }
        if(indexLowest != i){
            int temp = arr[i];
            arr[i] = arr[indexLowest];
            arr[indexLowest] = temp;
            traverse(arr, size);
        }
    }
}

int main(){
    int arr[5] = {3, 2, 6, 1, 5};
    int size = sizeof(arr)/sizeof(int);

    traverse(arr, size);
    selectionSort(arr, size);
    traverse(arr, size);
    return 0;
}
