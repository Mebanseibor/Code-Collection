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

    bool search(Node* root, const int& value){
        if (this->root == nullptr) return false;
        if (root == nullptr) return false;

        if(root->value == value) return true;

        if(value < root->value) return search(root->left, value);
        else return search(root->right, value);
    }
};

int main(){
    BinarySearchTree bt = BinarySearchTree();

    bt.addNode(bt.root, new Node(10));
    bt.addNode(bt.root, new Node(2));
    bt.addNode(bt.root, new Node(15));

    bt.traverseInorder(bt.root);

    std::cout << "\n\nPerforming searching:\n";

    std::cout << bt.search(bt.root, 2) << "\n";
    std::cout << bt.search(bt.root, 8) << "\n";
    return 0;
}
