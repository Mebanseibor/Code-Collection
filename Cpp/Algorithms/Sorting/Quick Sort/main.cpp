# include <iostream>

void display(int arr[], int size){
    for(int i=0 ; i<size ; i++){ std::cout << arr[i] << ", "; }
    std::cout << "\n";
}

void swap(int &a , int &b){
    std::cout << "Swapping " << a << " with " << b << "\n";

    int temp = a;
    a = b;
    b = temp;
}

// returns the partition point after arranging the lesser and greater elements relative to it
int partition(int arr[], int low, int high){
    int indexPivot = low;
    int pivot = arr[indexPivot];
    int left = low;
    int right = high;

    while(right > left){
        while(arr[left] <= pivot) left++;
        while(arr[right] > pivot) right--;

        if (right > left) swap(arr[left], arr[right]);
    }
    swap(arr[right], arr[indexPivot]);
    return right;
}

void quickSort(int arr[], int low, int high){
    if(low < high){
        int p = partition(arr, low, high);

        std::cout << "Sorting from index " << low << " to index " << p-1 << "\n";
        quickSort(arr, low, p-1);

        std::cout << "Sorting from index " << p+1 << " to index " << high << "\n";
        quickSort(arr, p+1, high);
    }
}

int main(){
    int arr[] = {5, 3, 7, 1, 2};
    int size = 5;

    display(arr, size);
    quickSort(arr, 0, size-1);
    display(arr, size);

    return 0;
}
