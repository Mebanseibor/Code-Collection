#include <iostream>

class Node{
    public:
    int value = 0;
    int height = 1;
    Node* left = nullptr;
    Node* right = nullptr;

    Node(){}
    Node(int value){this->value = value;}
};

class AVLTree{
    public:
    Node* root = nullptr;
    AVLTree(){}

    void insert(int value){
        root = insert(root, value);
        std::cout << "\n\n\n";
    }

    Node* insert(Node*& node, int value){
        if(node == nullptr){
            node = new Node(value);
            std::cout << "Inserted:\t" << node ->value << "\n";
            return node;
        }

        // insertion of the node following binary tree properties 
        if(value == node->value) return node;
        else if(value < node->value) node->left = insert(node->left, value);
        else node->right = insert(node->right, value);

        // add the height to the parents of the nodes within the path
        node->height = 1 + max(height(node->left), height(node->right));
        std::cout << "New height for node " << node->value << ":\t" << node->height << "\n";

        int bf = balanceFactor(node);

        // the following conditions catches the first node that has an invalid balance factor
        if(bf>1 && value < node->left->value){
            std::cout << "Perform LL\n";
            return left(node);
        }
        else if(bf>1 && value > node->left->value){
            std::cout << "Perform LR\n";
            return leftRight(node);
        }
        else if(bf<-1 && value > node->right->value){
            std::cout << "Perform RR\n";
            return right(node);
        }
        else if(bf<-1 && value < node->right->value){
            std::cout << "Perform RL\n";
            return rightLeft(node);
        }

        return node;
    }

    Node* left(Node* node){
        Node* child = node->left;
        Node* temp = child->right;

        // exchanging custody
        child->right = node;
        node->left = temp;

        // updating heights
        node->height = 1 + max(height(node->left), height(node->right));
        child->height = 1 + max(height(child->left), height(child->right));

        std::cout << "Attaching parent to: " << child->value << "\n";
        return child; // return the child that has climbed up
    }

    Node* right(Node* node){
        Node* child = node->right;
        Node* temp = child->left;

        // exchanging custody
        child->left= node;
        node->right = temp;

        // updating heights
        node->height = 1 + max(height(node->left), height(node->right));
        child->height = 1 + max(height(child->left), height(child->right));

        std::cout << "Attaching parent to: " << child->value << "\n";
        return child; // return the child that has climbed up
    }

    Node* leftRight(Node* node){
        node->left = right(node->left);

        std::cout << "Attaching parent to: " << node->value << "\n";
        return left(node);
    }

    Node* rightLeft(Node* node){
        node->right = left(node->right);

        std::cout << "Attaching parent to: " << node->value << "\n";
        return right(node);
    }

    int balanceFactor(Node* node){
        std::cout << "Checking bf for node with value:\t" << node->value << "\n";

        int left = height(node->left);
        int right = height(node->right);
        int diff = left - right;
        std::cout << "balance factor: " << left << "-" << right << "=" << diff << "\n";

        return diff;
    }

    int height(Node* node){
        if(node == nullptr) return 0;
        return node->height;
    }

    int max(int a, int b){return a>b ? a : b;}

    void inorder(Node* node){
        if(node == nullptr) return;

        inorder(node->left);
        std::cout << node->value << "\t" << height(node) << "\n";
        inorder(node->right);
    }
};

int main(){
    AVLTree a = AVLTree();

    a.insert(50);
    a.insert(20);
    a.insert(10);
    a.insert(70);
    a.insert(60);

    a.inorder(a.root);

    return 0;
}
