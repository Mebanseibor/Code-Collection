#include <iostream>

void display(int arr[], int size){
    for(int i=0 ; i<size ; i++) std::cout << arr[i] << ", ";
    std::cout << "\n";
}

void fibo(const int n){
    int arr[n] = {};

    int f3 = 0;
    int f2 = 1;
    int f1 = 0;

    for(int i=0 ; i<n ; i++){
        arr[i] = f3;
        f3 = f1+f2;
        f1 = f2;
        f2 = f3;
    }
    std::cout << "\n";

    display(arr, n);
}

int main(){
    fibo(10);
    return 0;
}
