public class Main{
    public static int BinarySearch(int array[], int elementKey){
        int indexLeft = 0;
        int indexRight = array.length-1;

        while(indexLeft<indexRight){
            int indexMid = indexLeft+(indexRight-indexLeft)/2;
            int elementMid = array[indexMid];
            
            if(elementMid == elementKey){return indexMid;}
            else if(elementKey<elementMid){indexRight = indexMid-1;}
            else{indexLeft = indexMid+1;}
        }
        return -1;
    }
    public static void main(String[] args){
        
        // example:
        // 6 and 18 are missing
        int[] array = {1, 2, 3, 4, 5, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 19, 20};
        
        int key;

        key = 7;
        System.out.println("Index of key " +key+ " is: " +BinarySearch(array, key));
        
        key = 5;
        System.out.println("Index of key " +key+ " is: " +BinarySearch(array, key));
        
        key = 6;
        System.out.println("Index of key " +key+ " is: " +BinarySearch(array, key));
        
        key = 21;
        System.out.println("Index of key " +key+ " is: " +BinarySearch(array, key));
    };
}