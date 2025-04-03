#include <iostream>

int binarySearch(int arr[], int capacity, int key){
    int indexLeft = 0;
    int indexRight = capacity-1;
    int indexMiddle = (indexRight-indexLeft)/2;

    while(indexLeft<=indexRight){
        int element = arr[indexMiddle];
        if(element == key) return indexMiddle;
        else if(key < element) indexRight = indexMiddle - 1;
        else if(key > element) indexLeft = indexMiddle + 1;
        indexMiddle = indexLeft + (indexRight-indexLeft)/2;
    }
    return -1;
}

int main(){
    int capacity = 8;
    int arr[] = {1, 3, 6, 7, 8, 12, 14, 15};
    
    std::cout << binarySearch(arr, capacity, 12) << "\n";
    std::cout << binarySearch(arr, capacity, 13) << "\n";

    return 0;
}
