# AVL Tree
- Named after its inventors:
    - Georgy Adelson-Velsky
    - Evgenii Landis

## Properties:
- A self balancing search tree (SBT) that ensures
    - Efficient searching, insertion and deletion operations
    - It maintains a balanced structure
    - It guarantees that the height between the left and right subtrees of any node is at most 1
    - The balancing takes place by ratations during the insertion and deletions of the nodes

## To remember:
- leftHeight - rightHeight

- Balance factor:
    - It is the difference between the height of the left subtree and the height of the right subtree
    - Acceptable values: {-1, 0, +1}
    - If BF is has unacceptable positive values, the subtree is heavily leaning towards to left handside
    - If BF is has unacceptable negative values, the subtree is heavily leaning towards to right handside

- Remember, we count the highest height of the subtree

- If multiple nodes are imbalance, start balancing the unbalanced node that is nearest to the recently inserted node

- The validation of the balance factor starts from the leaf node towards its parents

- The path to the recently inserted node is tracked by using its value

## Observation:
- The statements that are performed within the insert function considers only the nodes that are within the path from the root node to the inserted node

- For each insertion that disrupts the balance, isn't it that there should be only one set of rotation(s) to be performed?
    - Yes

## To Learn:
- Why is height by default, 1?
    - It solves the issue when BF is calculated
    - Is there any alternative to just make to the more intuitive value of 0?

## Practice:
- How to count the height of a subtree? Or, how to determine the balance factor of the subtree?

- How to identify LL, LR, RR, and RL imbalance programmatically?

- How to implement deletion?

- To keep track of the node that was just inserted, we just simple keep node of the value of the node during insertion

## Projects:
