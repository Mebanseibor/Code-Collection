#include <iostream>
#include <vector>

int COUNTER_ID = 0;

int assignID(){
    return ++COUNTER_ID;
}

class Node{
    public:
    int id;
    std::string value = "";

    std::vector<Node*> adjacentNodes;

    Node(){ id = assignID(); }
    Node(std::string value){
        id = assignID();
        this->value = value;
    }
};

class Graph{
    public:
    std::vector<Node*> nodes;

    Graph(){}

    void addNode(std::string value){
        Node* newNode = new Node(value);
        nodes.push_back(newNode);
    }

    void listNodes(){
        std::cout << "Nodes of the graphs:\n\n";
        std::cout << "id\tvalue\n";
        for(int i=0 ; i<size(); i++){
            Node* node = nodes[i];
            std::cout << node->id << "\t" << node->value << "\n";
        }
        std::cout << "\n";
    }

    bool connectionExist(Node* nodeA, Node* nodeB){
        for(int i=0 ; i<nodeA->adjacentNodes.size() ; i++)
            if(nodeA->adjacentNodes[i]->id == nodeB->id) return true;
        return false;
    }

    void connect(int a, int b){
        std::cout << "Attempting to connect " << a << " to " << b << "\n";
        if(a == b){ std::cout << "Can't connect the node to itself\n\n"; return; }

        Node* nodeA = nullptr;
        Node* nodeB = nullptr;

        for(int i=0 ; i<size(); i++){
            Node* node = nodes[i];
            if(node->id==a) nodeA = node;
            if(node->id==b) nodeB = node;
        }

        if(!nodeA){ std::cout << "Can't find the node with id: " << a << "\n"; return ;}
        if(!nodeB){ std::cout << "Can't find the node with id: " << b << "\n"; return ;}

        if(connectionExist(nodeA, nodeB)){
            std::cout << "Nodes are already connected\n\n";
            return;
        }

        nodeA->adjacentNodes.push_back(nodeB);
        nodeB->adjacentNodes.push_back(nodeA);
        std::cout << "Connected:\t" << nodeA->value << "(" << a << ")---" << "(" << b << ")" << nodeB->value << "\n\n";
    }

    int size(){ return nodes.size(); }
};

void test1(Graph g){
    std::cout << "---Test 1 starts ---\n";
    std::cout << "Creating relations between nodes\n";

    g.connect(1, 2);
    g.connect(1, 2);
    g.connect(2, 1);
    g.connect(1, 1);

    g.connect(1, 4);
    g.connect(1, 5);
    g.connect(1, 7);

    g.connect(2, 3);
    g.connect(4, 3);
    g.connect(3, 7);

    g.connect(5, 6);
    g.connect(8, 9);
    g.connect(8, 7);
    g.connect(9, 7);
    
    std::cout << "---Test 1 ends---\n\n\n";
}

int main(){
    Graph g = Graph();

    g.addNode("Alpha");
    g.addNode("Bravo");
    g.addNode("Charlie");
    g.addNode("Delta");
    g.addNode("Echo");
    g.addNode("Fox");
    g.addNode("Golf");
    g.addNode("Hotel");
    g.addNode("India");

    g.listNodes();

    test1(g);

    g.listNodes();

    return 0;

}
