#include <iostream>

class Node{
    public:
    int value = 0;
    Node* left = nullptr;
    Node* right = nullptr;

    Node(){}
    Node(int value){this->value = value;}
};

class BinarySearchTree{
    public:
    Node* root = nullptr;

    BinarySearchTree(){}

    void insert(int value){
        insert(root, value);
        std::cout << "Inserted:\t" << value << "\n";
    }

    void insert(Node*& root, int value){
        if(root == nullptr){
            root = new Node(value);
            return;
        };

        if(value == root->value) return;
        else if(value < root->value) insert(root->left, value);
        else insert(root->right, value);
    }

    void inOrder(){
        std::cout << "InOrder Traversal:\n";
        inOrder(root);
        std::cout << "\n\n";
    }
    void inOrder(Node* node){
        if(node == nullptr) return;

        inOrder(node->left);
        std::cout << node->value << ", ";
        inOrder(node->right);
    }

    void height(){ std::cout << "Height of the tree: " << height(root) << "\n"; }
    int height(Node* root){
        if(root == nullptr) return 0;

        int left = height(root->left);
        int right = height(root->right);
        return left > right? 1+left : 1+right;
    }

    void depth(int value){ std::cout << "Depth of " << value << ":\t" << depth(root, value) << "\n"; }
    int depth(Node* node, int value){
        if(node == nullptr) return -1;

        int d;
        if (value == node->value) return 0;
        else if(value < node->value) { d = depth(node->left, value); }
        else { d = depth(node->right, value); };

        return d == -1 ? -1 : 1+d;
    }
};

int main(){
    BinarySearchTree b = BinarySearchTree();

    b.insert(50);
    b.insert(20);
    b.insert(10);
    b.insert(80);
    b.insert(70);

    std::cout << "\n";
    b.inOrder();


    b.height();

    b.depth(50);
    b.depth(20);
    b.depth(60);
    return 0;
}
