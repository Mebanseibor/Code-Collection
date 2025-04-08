# include <iostream>

class Node{
    public:
    int value = -1;
    Node* next = nullptr;

    Node(){}

    Node(int value){
        this->value = value;
    }

    Node(int value, Node* next){
        this->value = value;
        this->next = next;
    }
};

class LinkedList{
    public:
    Node* head = nullptr;
    int size = 0;


    LinkedList(){
        std::cout << "Created an linked list\n";
    }

    LinkedList(Node node){
        head = &node;
        size++;
    }



    Node appendNode(int value){
        Node* newNode = new Node(value);
        size++;

        std::cout << "New node was created with value:\t" << value << "\n";
        if(head != nullptr) std::cout << "Value of non-null head:\t" << head->value << "\n";

        if(head == nullptr){
            std::cout << "Current head is empty\n";
            head = newNode;
            
            std::cout << "New head was assigned\n";

            std::cout << "Head has value:\t" << head->value << " \n";
            std::cout << "Head has next:\t" << head->next << " \n";


            return *newNode;
        };

        std::cout << "Current head is not empty\n";

        
        std::cout << "Head has value:\t" << head->value << " \n";
        std::cout << "Head has next:\t" << head->next << " \n";
        
        Node* nodePtr = head;


        while(nodePtr->next != nullptr){
            std::cout << "Not at the end of the list yet, travsersing to next\n";
            nodePtr = nodePtr->next;
        }
        
        std::cout << "Reached at end of the list\n";
        std::cout << "nodePtr has value:\t" << nodePtr->value << " \n";
        std::cout << "nodePtr has next:\t" << nodePtr->next << " \n";


        nodePtr->next = newNode;

        return *newNode;
    }

    void traverse(){
        std::cout << "Traversing:\n";
        if (head == nullptr) return;

        Node* nodePtr = head;

        int counterNode = 0;

        while(nodePtr != nullptr){
            std::cout << "At index " << counterNode << ":\t" << nodePtr->value << "\n";
            nodePtr = nodePtr->next;
            counterNode++;
        }
    }
};

int main(){
    std::cout << "Starting of main()\n";

    LinkedList ll = LinkedList();

    ll.appendNode(1);
    ll.appendNode(2);
    ll.appendNode(3);
    ll.appendNode(4);
    ll.appendNode(5);

    ll.traverse();
    std::cout << "Size:\t" << ll.size << "\n";

    return 0;
}
