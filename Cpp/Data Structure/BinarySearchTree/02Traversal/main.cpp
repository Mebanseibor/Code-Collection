#include <iostream>
#include <cmath>

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

        preOrder(node->left);
        preOrder(node->right);
        std::cout << node->value << ", ";
    }

    void postOrder(){
        std::cout << "Post-Order:\n";
        postOrder(root);
        std::cout << "\n";
    }
    void postOrder(Node* node){
        if(node == nullptr) return;

        std::cout << node->value << ", ";
        postOrder(node->left);
        postOrder(node->right);
    }

    void levelOrder(){
        std::cout << "Level-Order:\n";

        Node* arrRoot[1] = {root};
        levelOrder(1, arrRoot);

        std::cout << "\n";
    }
    void levelOrder(int level, Node* arrParents[]){
        // for root
        if(level == 1){
            Node* node = arrParents[0];
            if(node == nullptr) return;

            std::cout << node->value << ", ";
        }

        int sizeChildrens = std::pow(2, level);
        Node* arrChildren[sizeChildrens] = {nullptr};
        getNodesAtLevel(arrParents, arrChildren, level);

        bool hasChildren = false;
        for(int i=0 ; i<sizeChildrens ; i++){
            if(arrChildren[i] != nullptr){
                if (!hasChildren) std::cout << "\n";
                hasChildren = true;
                std::cout << arrChildren[i]->value << ", ";
            };
        };

        if(hasChildren) levelOrder(level+1, arrChildren);
    }
    void getNodesAtLevel(Node* arrParents[], Node* arrChildren[], int level){
        for(int iParent=0 ; iParent<std::pow(2, level-1) ; iParent++){
            Node* node = arrParents[iParent];

            if(node == nullptr) continue;

            if(node->left) arrChildren[iParent*2] = node->left;
            if(node->right) arrChildren[(iParent*2)+1] = node->right;
        }

        return;
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
