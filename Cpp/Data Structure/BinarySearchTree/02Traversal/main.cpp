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

    void insert(int value){ insert(root, value); }
    void insert(Node*& node, int value){
        if(node == nullptr){
            node = new Node(value);
            std::cout << "Inserted: " << value << "\n";
            return;
        }

        if(value == node->value) return;
        else if(value < node->value) insert(node->left, value);
        else insert(node->right, value);
    }

    void inOrder(){
        std::cout << "In-Order:\n";
        inOrder(root);
        std::cout << "\n";
    }
    void inOrder(Node* node){
        if(node == nullptr) return;

        inOrder(node->left);
        std::cout << node->value << ", ";
        inOrder(node->right);
    }

    void preOrder(){
        std::cout << "Pre-Order:\n";
        preOrder(root);
        std::cout << "\n";
    }
    void preOrder(Node* node){
        if(node == nullptr) return;

        std::cout << node->value << ", ";
        preOrder(node->left);
        preOrder(node->right);
    }

    void postOrder(){
        std::cout << "Post-Order:\n";
        postOrder(root);
        std::cout << "\n";
    }
    void postOrder(Node* node){
        if(node == nullptr) return;

        postOrder(node->left);
        postOrder(node->right);
        std::cout << node->value << ", ";
    }

    void levelOrder(){
        std::cout << "Level-Order:\n";

        Node* arrRoot[1] = {root};
        
        levelOrder(1, arrRoot);

        std::cout << "\n";
    }

    void levelOrder(int level, Node* arrParents[]){
        // output the parents
        int sizeParents = 1 << (level-1);
        for(int i=0 ; i<sizeParents ; i++){
            Node* parent = arrParents[i];
            if (parent) std::cout << parent->value << ", ";
        }

        int sizeChildren = 1 << level;
        Node* arrChildren[sizeChildren] = {nullptr};

        bool hasChildren = false;
        for(int i=0 ; i<sizeParents ; i++){
            Node* parent = arrParents[i];

            if(parent==nullptr) continue;

            if(parent->left){
                hasChildren = true;
                arrChildren[i*2] = parent->left;
            };
            if(parent->right){
                hasChildren = true;
                arrChildren[(i*2)+1] = parent->right;
            };
        }

        if(hasChildren) levelOrder(level+1, arrChildren);
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

    std::cout << "\n\n\n";

    b.inOrder();

    std::cout << "\n";
    b.preOrder();

    std::cout << "\n";
    b.postOrder();

    std::cout << "\n";
    b.levelOrder();

    return 0;
}
