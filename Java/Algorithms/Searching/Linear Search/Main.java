public class Main{
    public static int LinearSearch(int[] array, int key){
        int size = array.length;
        for(int index=0 ; index<size ; index++){
            if(array[index] == key){return index;}
        };
        return -1;
    }
    public static void main(String[] args){
        // example:
        // 6 and 18 are missing
        int[] array = {1, 2, 3, 4, 5, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 19, 20};
        
        int key;

        key = 7;
        System.out.println("Index of key " +key+ " is: " +LinearSearch(array, key));
        
        key = 5;
        System.out.println("Index of key " +key+ " is: " +LinearSearch(array, key));
        
        key = 6;
        System.out.println("Index of key " +key+ " is: " +LinearSearch(array, key));
        
        key = 21;
        System.out.println("Index of key " +key+ " is: " +LinearSearch(array, key));
    };
}