#include <iostream>

void display(int arr[], int size){
    for(int i=0 ; i<size ; i++) std::cout << arr[i] << ", ";
    std::cout << "\n";
}

void merge(int arr[], int lower, int mid, int upper){
    int i = lower;
    int j = mid+1;
    int index = lower;

    int result[upper+1] = {};

    while(i <= mid && j <= upper){
        if(arr[i] <= arr[j]) result[index] = arr[i++];
        else result[index] = arr[j++];
        
        index++;
    }

    if(i > mid) while(j<=upper) result[index++] = arr[j++];
    else while(i<=mid) result[index++] = arr[i++];

    for(int i=lower ; i<=upper; i++) arr[i] = result[i];
}

void mergeSort(int arr[], int lower, int upper){
    if(lower < upper){
        int mid = (lower+upper)/2;
        
        mergeSort(arr, lower, mid);
        mergeSort(arr, mid+1, upper);
        merge(arr, lower, mid, upper);
    }
}

int main(){
    int arr[] = {4, 6, 2, 3, 1, 20, 39, 4, 18, 15};
    int size = sizeof(arr)/sizeof(int);

    display(arr, size);
    mergeSort(arr, 0, size-1);
    display(arr, size);

    return 0;
}
