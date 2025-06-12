#include <iostream>

class Node{
    public:
    int value = 0;
    Node* left = nullptr;
    Node* right = nullptr;

    Node(int value){this->value = value;}
};

class BinarySearchTree{
    public:
    int size = 0;
    Node* root = nullptr;

    BinarySearchTree(){}

    void addNode(Node*& root, Node* node){
        if(this->root == nullptr){
            this->root = node;
            size++;
            return;
        }

        if(root == nullptr){
            root = node;
            size++;
            return;
        }

        if(node->value < root->value) addNode(root->left, node);
        else addNode(root->right, node);
    }

    void traverseInorder(Node* root){
        if (root == NULL) return;
        
        traverseInorder(root->left);
        std::cout << root->value << ", ";
        traverseInorder(root->right);
    }
};

int main(){
    BinarySearchTree bt = BinarySearchTree();

    bt.addNode(bt.root, new Node(10));
    bt.addNode(bt.root, new Node(2));
    bt.addNode(bt.root, new Node(15));

    bt.traverseInorder(bt.root);
    return 0;
}
