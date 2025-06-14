#include <iostream>

void towerOfHanoi(int n, char A, char B, char C){
    if(n>0){
        towerOfHanoi(n-1, A, C, B);
        std::cout << "Moving disk from " << A << " to " << C << "\n";
        towerOfHanoi(n-1, B, A, C);
    }
}

int main(){
    int n = 4;

    towerOfHanoi(n, 'A', 'B', 'C');
    return 0;
}
