# Two Sum

## Table of Contents
| Content                                           |
| ------------------------------------------------- |
| 🧩[Problem Statement](#content-problemstatement) |
| 🎯[Solution](#content-solution)                  |
| 🔗[Links](#content-links)                        |


## <p id='content-problemstatement'>Problem Statement🧩</p>
&emsp;Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

- #### More Information:
    - It is assumed that each input would have exactly one solution
    - We may not use the same element twice.
    - You can return the answer in any order.

- #### Sample Input/Output
    | Input                          | Output |
    | ------------------------------ | ------ |
    | nums = [2,7,11,15], target = 9 | [0,1]  |
    | nums = [3,2,4], target = 6     | [1,2]  |
    | nums = [3,3], target = 6       | [0,1] |

- #### Auxiliary Goal
    - Construct an algorithm that is less than $O(n^2)$ time complexity




## <p id='content-solution'>Solution🎯</p>
- ### Rudimentary Solution
    - #### Code
        - [TwoSum [-v01]][directorylink-solution1]

    - #### Flowchart
        - ![Flowchart of Rudimentary](./TwoSum%20[-v01].drawio.png)


    - #### Space and Time Complexity
        - ##### Time Complexity
            
            | Best Time  | Average Time | Worst Time |
            | ---------- | ------------gi | ---------- |
            | $\Omega(1)$ | $\Theta()$   | $O(n^2)$ |
        
        - ##### Space Complexity
            - $O(1)$
    
    - #### Features:
        - Early return when the solution is found






## <p id='content-links'>Links🔗</p>
- [Online Practice Problem][weblink-leetcode-twosum] by leetcode



<!-- weblink -->
[weblink-leetcode-twosum]: https://leetcode.com/problems/two-sum/description/




<!-- directorylink -->
[directorylink-solution1]: ./TwoSum%20[-v01].java