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
        std::cout << "Nodes of the graphs:\n";
        if(size()==0){
            std::cout << "Graph has no nodes\n";
            return;
        }
        std::cout << "id\tvalue\tn of adjacentNodes\n";
        for(int i=0 ; i<size(); i++){
            Node* node = nodes[i];
            std::cout << node->id << "\t" << node->value << "\t" << node->adjacentNodes.size() << "\n";
        }
        std::cout << "\n";
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

    bool connectionExist(Node* nodeA, Node* nodeB){
        for(int i=0 ; i<nodeA->adjacentNodes.size() ; i++)
            if(nodeA->adjacentNodes[i]->id == nodeB->id) return true;
        return false;
    }

    void disconnect(std::string value){
        std::cout << "Attempting to disconnect the node: " << value << "\n";
        
        Node* node = findValue(value);
        if(!node){
            std::cout << "Failed to disconnect: Node doesn't exist\n";
            return;
        }

        for(int i=node->adjacentNodes.size()-1 ; i>=0; i--){
            Node* nodeN = node->adjacentNodes.back();

            // disconnects node from nodeN
            for(int j=0 ; j<nodeN->adjacentNodes.size() ; j++){
                if(nodeN->adjacentNodes[j] == node){
                    auto iterator = nodeN->adjacentNodes.begin()+j;
                    std::cout << "Disconnected edge \"" << node->value << "\" from node \"" << nodeN->value << "\"\n";
                    nodeN->adjacentNodes.erase(iterator);
                }
            }
            std::cout << "Disconnected edge \"" << nodeN->value << "\" from node \"" << node->value << "\"\n";
            std::cout << "\n";
            node->adjacentNodes.pop_back();
        }
        std::cout << "Disconnected all nodes from node: " << value << "\n";
    }

    Node* findValue(std::string value){
        std::cout << "Attempting to find the node: " << value << "\n";

        for(int i=0 ; i<size() ; i++)
            if(nodes[i]->value == value){
                std::cout << "Node was found\n";
                return nodes[i];
            }

        std::cout << "Node was not found\n";
        return nullptr;
    }

    bool deleteNode(Node* node){
        if(node == nullptr){
            std::cout << "Failed Node Deletion: Node was nullptr";
            return false;
        }
        std::cout << "Attempting to delete node: " << node->value << "\n";

        for(int i=0 ; i<size() ; i++){
            if(nodes[i] == node){
                std::cout << "Disconneting adjacent node(s) of " << node->value << ":\n";
                disconnect(node->value);
                
                auto iterator = nodes.begin()+i;
                std::cout << "Deleted node: " << node->value << "\n";
                std::cout << "\n";
                nodes.erase(iterator);
                return true;
            }
        }
        std::cout << "Failed Node Deletion: Node was not found\n";
        std::cout << "\n";
        return false;
    }

    void deleteNodes(){
        std::cout << "Deleting all " << size() << " nodes from the graph\n";
        for(int i=size()-1 ; i>=0 ; i--){
            auto iterator = nodes.begin()+i;
            std::cout << "Deleted node: " << nodes[i]->value << "\n";
            nodes.erase(iterator);
        }
        std::cout << "Deleted all nodes from the graph\n";
    }

    int size(){ return nodes.size(); }
};

void testConnectAndDisconnect(Graph& g){
    std::cout << "---Test 1 starts ---\n";
    std::cout << "Creating relations between nodes:\n";

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

    g.listNodes();
    std::cout << "Disconnecting some relations:\n";
    g.disconnect("Alpha");
    
    
    std::cout << "---Test 1 ends---\n\n\n";
}

void testSearching(Graph& g){
    std::cout << "---Test 2 starts ---\n";
    std::cout << "Testing searching\n";

    g.findValue("Alpha");

    std::cout << "---Test 2 ends---\n\n\n";
}

void testDeletion(Graph& g){
    std::cout << "---Test 3 starts ---\n";
    std::cout << "Testing Deletion\n";

    g.deleteNode(g.findValue("Delta"));
    g.listNodes();

    g.deleteNodes();
    g.listNodes();

    std::cout << "---Test 3 ends---\n\n\n";
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

    testConnectAndDisconnect(g);

    g.listNodes();

    testSearching(g);

    g.listNodes();

    testDeletion(g);

    g.listNodes();

    return 0;
}
