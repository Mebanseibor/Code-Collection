#include <iostream>

class Node{
    public:
    int value = 0;
    Node* left = nullptr;
    Node* right = nullptr;

    Node(){}
    Node(int value){ this->value = value; }
};

class BinarySearchTree{
    public:
    Node* root = nullptr;

    BinarySearchTree(){}

    void insert(int value){
        insert(root, value);
        std::cout << "Inserted: " << value << "\n";
    }

    void inOrder(){
        std::cout << "InOrder:\n";
        inOrder(root);
        std::cout << "\n";
    }

    void removeNode(int value){
        std::cout << "Deleting: " << value << "\n";
        root = removeNode(root, value);
        std::cout << "Deleted: " << value << "\n";
    }

    private:
    void insert(Node*& node, int& value){
        if(node == nullptr) {
            node = new Node(value);
            return;
        };

        if(value == node->value) return;
        else if(value < node->value) insert(node->left, value);
        else insert(node->right, value);
    }

    void inOrder(Node* node){
        if(node == nullptr) return;

        inOrder(node->left);
        std::cout << node->value << ", ";
        inOrder(node->right);
    }

    Node* removeNode(Node* node, int value){
        if(node == nullptr) return nullptr;

        if(value < node->value){
            node->left = removeNode(node->left, value);
            return node;
        }
        else if(value > node->value){
            node->right = removeNode(node->right, value);
            return node;
        }

        Node* replacement = findSuccessor(node->right);
        if(replacement == nullptr){
            replacement = findPredecessor(node->left);
            if(replacement == nullptr) return nullptr;

            replacement->right = node->right;
            if(replacement!=node->left) replacement->left = node->left;
        }
        else{
            replacement->left = node->left;
            if(replacement!=node->right) replacement->right = node->right;
        }

        return replacement;
    }

    Node* findSuccessor(Node* node){
        if(node == nullptr) return nullptr;

        Node* ptr = node;
        Node* ptrParent = nullptr;
        while(ptr->left != nullptr) {
            ptrParent = ptr;
            ptr = ptr->left;
        }
        if (ptrParent) ptrParent->left = ptr->right;

        std::cout << "Found successor as: " << ptr->value << "\n";
        return ptr;
    }

    Node* findPredecessor(Node* node){
        if(node == nullptr) return nullptr;

        Node* ptr = node;
        Node* ptrParent = nullptr;
        while(ptr->right!= nullptr){
            ptrParent = ptr;
            ptr = ptr->right;
        }
        if (ptrParent) ptrParent->right = ptr->left;

        std::cout << "Found predecessor as: " << ptr->value << "\n";
        return ptr;
    }
};

int main(){
    BinarySearchTree b = BinarySearchTree();

    b.insert(50);
    b.insert(20);
    b.insert(10);
    b.insert(40);
    b.insert(30);
    b.insert(60);
    b.insert(80);
    b.insert(70);
    b.insert(75);

    std::cout << "\n";
    b.inOrder();

    std::cout << "\n";
    b.removeNode(20);

    std::cout << "\n";
    b.inOrder();

    std::cout << "\n";
    b.removeNode(50);

    std::cout << "\n";
    b.inOrder();

    return 0;
}
