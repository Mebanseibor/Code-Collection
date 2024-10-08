class MedianOfTwoSortedArrays{

    public static double findSolution( int[] arrayA, int[] arrayB){
        double median = -1;

        int sizeA = arrayA.length;
        int sizeB = arrayB.length;

        
        int size = sizeA + sizeB;
        
        int numberBackward = 0;
        int numberForward = 0;
        
        System.out.printf("(size/2)+1 : %d\n", (size/2)+1);   // #Debugging
        for(int indexA = 0, indexB = 0, index=0 ; index<(size/2)+1 && index<size ; index++){
            System.out.printf("Index: %d\n", index);  // #Debugging

            if(indexA < sizeA && (indexB>=sizeB || (indexB<sizeB && arrayA[indexA] <= arrayB[indexB]))){
                System.out.printf("Taking from ArrayA: %d\n", arrayA[indexA]);  // #Debugging
                numberBackward = numberForward;
                numberForward = arrayA[indexA];
                indexA++;
            }
            else if(indexB < sizeB){
                System.out.printf("Taking from ArrayB: %d\n", arrayB[indexB]);  // #Debugging
                numberBackward = numberForward;
                numberForward = arrayB[indexB];
                indexB++;
            };
            
            if(index == size/2){
                System.out.printf("Back: %d\tFront: %d\n", numberBackward, numberForward);    // #Debugging
                if(size%2 == 0) median = (double)(numberBackward + numberForward)/2;
                else median = numberForward;
            }
        };

        return median;
    };

    public static void main(String[] args){
        int[] arrayA = {1, 3};
        int[] arrayB = {2};

        int numberPrint = 1;
        System.out.printf("%d. Solution: %f\n\n", numberPrint++, findSolution(arrayA, arrayB));
        System.out.printf("%d. Solution: %f\n\n", numberPrint++, findSolution(new int[]{1, 2}, new int[]{3, 4}));
        System.out.printf("%d. Solution: %f\n\n", numberPrint++, findSolution(new int[]{0, 0}, new int[]{0, 0}));
        System.out.printf("%d. Solution: %f\n\n", numberPrint++, findSolution(new int[]{2}, new int[]{1}));
        System.out.printf("%d. Solution: %f\n\n", numberPrint++, findSolution(new int[]{}, new int[]{1}));
        System.out.printf("%d. Solution: %f\n\n", numberPrint++, findSolution(new int[]{2}, new int[]{}));
        System.out.printf("%d. Solution: %f\n\n", numberPrint++, findSolution(new int[]{1, 3}, new int[]{2}));
    };
};