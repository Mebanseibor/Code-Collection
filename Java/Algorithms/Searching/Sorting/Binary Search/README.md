# Binary Search
Binary Search is a searching algorithm that searches a **sorted** array for a key by **comparing the middle element** of an array to the key element, each time taking half of the array, which  potentially contain the key element

## Time and Space Complexity
- Time Complexity:
    | Best Time ()  | Average Time ()   | Worst Time(O) |
    | ---           | ---               | ---           |
    | 1             | log(n)            | log(n)        |
- Space Complexity:
    O(n)

## Flowchart
### Binary Search Algorithm
```mermaid
flowchart
    Start((Start))
    VarInitFunc[Set variables to keep track of the<br>left end and right end of the array or subarray]
    CompareLeftLTRight{if Left end < Right End}
    ReturnNotFound((Return not found))
    
    subgraph LoopLeftLTRight [While Left End < Right End]
        direction TB
        VarInitMid[Set a variable to store the middle point of the array or subarray]
        CompareKeyWithMiddle{Compare the key element with<br>the element at the middle}
        ReturnMid((Return the middle<br>position/index))
        SubarrayLeftHalf[Take left half of the<br>array as a subarray]
        SubarrayRightHalf[Take Right half of the<br>array as a subarray]
        
        VarInitMid --> CompareKeyWithMiddle
        %% Comparision
            CompareKeyWithMiddle -->|Lesser| SubarrayLeftHalf
            CompareKeyWithMiddle -->|Equal| ReturnMid
            CompareKeyWithMiddle -->|Greater| SubarrayRightHalf
    end
    
    

    Start --> VarInitFunc
    VarInitFunc --> CompareLeftLTRight
    %% CompareLeftLTRight
        CompareLeftLTRight -->|Yes| LoopLeftLTRight
        CompareLeftLTRight -->|No| ReturnNotFound
    LoopLeftLTRight --> CompareLeftLTRight
```

### Main Function
```mermaid
flowchart
    %%Node difinition
    Start(Start)
    InputArray[/Input Array/]
    InputKey[/Input Key/]
    subgraph LoopLeftLTRight [While Left End < Right End]
        direction TB
        VarInitMid[Set a variable to store the middle point of the array or subarray]
        CompareKeyWithMiddle{Compare the key element with<br>the element at the middle}
        ReturnMid((Return the middle<br>position/index))
        SubarrayLeftHalf[Take left half of the<br>array as a subarray]
        SubarrayRightHalf[Take Right half of the<br>array as a subarray]
        
        VarInitMid --> CompareKeyWithMiddle
        %% Comparision
            CompareKeyWithMiddle -->|Lesser| SubarrayLeftHalf
            CompareKeyWithMiddle -->|Equal| ReturnMid
            CompareKeyWithMiddle -->|Greater| SubarrayRightHalf
    end
    BinarySearch[Binary  Search]
    End(End)

    Start --> InputArray[/Input a sorted array/]
    InputArray --> InputKey
    InputKey --> BinarySearch[Perform Binary Search]
    BinarySearch --> End
```