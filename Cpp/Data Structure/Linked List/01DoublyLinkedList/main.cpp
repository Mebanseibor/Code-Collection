#include <iostream>

class Node{
    public:
    int value;
    Node* next = nullptr;
    Node* prev = nullptr;

    Node(){}
    Node(int value){ this->value = value; }
};

class DoublyLinkedList{
    public:
    int size = 0;
    Node* head = nullptr;

    DoublyLinkedList(){}

    void append(int value){
        Node* newNode = new Node(value);

        if(head == nullptr){
            head = newNode;
            size++;
            std::cout << "Appened:\t" << newNode->value << "\n";
            return;
        }

        Node* nodePtr = head;
        while(nodePtr->next){
            nodePtr = nodePtr->next;
        }

        nodePtr->next = newNode;
        newNode->prev = nodePtr;
        size++;
        std::cout << "Appened:\t" << newNode->value << "\n";
    }

    void prepend(int value){
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
        size++;

        if(newNode->prev != nullptr){ newNode->next->prev = newNode; }
        std::cout << "Prepened:\t" << newNode->value << "\n";
    }

    void traverse(){
        std::cout << "Traversing the doubly linked list:\n";
        Node* nodePtr = head;

        while(nodePtr){
            std::cout << nodePtr->value << ", ";
            nodePtr = nodePtr->next;
        }
        std::cout << "\n";
    }

    void insert(int index, int value){
        std::cout << "Attempting to insert " << value << " at index " << index << "\n";
        if(index<0 || index>size){
            std::cout << "Insertion operation failed: Index " << index << " is out of bound\n";
            return;
        }

        int indexPtr = 0;
        Node* newNode = new Node(value);

        Node* nodePtrL = nullptr;
        Node* nodePtrR = head;

        while(indexPtr<index && nodePtrR!=nullptr){
            nodePtrL = nodePtrR;
            nodePtrR = nodePtrR->next;
            indexPtr++;
        }

        if(nodePtrR != nullptr){
            newNode->next = nodePtrR;
            nodePtrR->prev = newNode;
        }
        if(nodePtrL != nullptr){
            newNode->prev = nodePtrL;
            nodePtrL->next = newNode;
        }

        if(indexPtr==0) head = newNode;

        size++;
        std::cout << "Inserted " << newNode->value << " at index " << indexPtr << "\n";
        return;
    }
};

int main(){
    DoublyLinkedList dl = DoublyLinkedList();

    // demonstrating append
    dl.append(50);
    dl.append(60);
    dl.append(30);
    dl.append(20);
    dl.append(90);



    // demonstrating insert
    std::cout << "\n";
    dl.traverse();

    std::cout << "\n";
    dl.insert(3, 5);
    std::cout << "\n";
    dl.traverse();

    std::cout << "\n";
    dl.insert(0, 8);
    std::cout << "\n";
    dl.traverse();

    std::cout << "\n";
    dl.insert(10, 9);
    std::cout << "\n";
    dl.traverse();

    std::cout << "\n";
    dl.insert(-1, 2);
    std::cout << "\n";
    dl.traverse();

    // demonstrating prepend
    dl.prepend(47);
    dl.prepend(28);
    dl.prepend(19);

    dl.traverse();
    
    return 0;
}
