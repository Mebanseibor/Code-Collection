public class Main{
    public static void bubbleSort(int[] array){
        int size = array.length;
        boolean isSorted = false;
        
        // for every integer in the array
        for(int i=0 ; i<size && !isSorted; i++){
            
            // assume that the array is sorted
            isSorted = true;

            // for every integer in the array till second-last element
            for(int j=0 ; j<size-1 ; j++){
                
                // if array[j] is larger than the following integer
                if(array[j] > array[j+1]){
                    
                    // swapping the adjacent pair of integers
                    int temp = array[j];
                    array[j] = array[j+1];
                    array[j+1] = temp;

                    // swapping was done, indicating that the array was not sorted
                    isSorted = false;
                };
            };
        }
    }
    public static void main(String[] args){
        int[] array = {9, 5, 7, 2, 6, -1, -2, 1, 4, 0};
        

        bubbleSort(array);

        // printing the array
        for(int number: array){System.out.print(number+", ");};
        // Output: -2, -1, 0, 1, 2, 4, 5, 6, 7, 9,
    }
}