class TwoSum{
    public static int[] findSolution(int[] array, int target){
        int[] solution = new int[]{-1, -1};
        
        int size = array.length;
        for(int i=0 ; i<size ; i++){
            for(int j=i+1 ; j<size ; j++){
                if(array[i] + array[j] == target){
                    solution[0] = i;
                    solution[1] = j;
                    
                    return solution;
                }
            }
        };

        return solution;
    }

    public static void displaySolution(int[] solution){
        System.out.printf("%d, %d", solution[0], solution[1]);
    }

    public static void main(String[] args){
        int[] array = {2, 7, 11, 15};
        int target = 9;

        displaySolution(findSolution(array, target));
    }
}