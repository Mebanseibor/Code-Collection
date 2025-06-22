#include <iostream>
#include <vector>
#include <queue>

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

    Node* findValue(int id){
        std::cout << "Attempting to find the node with id: " << id << "\n";

        for(int i=0 ; i<size() ; i++){
            Node* node = nodes[i];
            if(node->id == id){
                std::cout << "Node was found\n";
                return node;
            }
        }

        std::cout << "Node was not found\n";
        return nullptr;
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

    void breadthFirstSearch(int a, int b){
        std::cout << "Attempting to perform BFS from " << a << " to " << b << "\n";
        if(a<0 || b<0){
            std::cout << "Invalid id's entered\n";
            return;
        }

        Node* nodeA = findValue(a);
        Node* nodeB = findValue(b);

        if(!nodeA) { std::cout << "Cannot find node with value: " << a << "\n"; return; }
        if(!nodeB) { std::cout << "Cannot find node with value: " << b << "\n"; return; }

        std::queue<Node*> toVisitNodes;
        toVisitNodes.push(nodeA);
        std::vector<Node*> visitedNodes;
        
        if(bFS(nodeB, toVisitNodes, visitedNodes)) std::cout << "Found a path between " << nodeA->value << " and " << nodeB->value << "\n";
        else std::cout << "Cannot jound a path between " << nodeA->value << " and " << nodeB->value << "\n";
        std::cout << "\n\n";
    }

    int size(){ return nodes.size(); }

    private:
    bool bFS(Node* nodeB, std::queue<Node*>& toVisitNodes, std::vector<Node*>& visitedNodes){
        while(toVisitNodes.size() != 0){
            Node* nodeA = toVisitNodes.front();
            std::cout << "At front: " << nodeA->value << "\n";
            toVisitNodes.pop();
            
            if(!nodeA || !nodeB) return false;
            if(nodeA == nodeB) return true;

            // checks if the nodeA is already visited
            bool isAlreadyVisited = false;
            for(int i=0 ; i<visitedNodes.size() ; i++){
                if(visitedNodes[i] == nodeA){
                    std::cout << "Front Already visited\n";
                    std::cout << "\n";
                    isAlreadyVisited = true;
                    break;
                }
            }
            if(isAlreadyVisited) continue;

            std::cout << "This Front Not visited yet\n";

            for(int i=0 ; i<nodeA->adjacentNodes.size() ; i++){
                Node* node = nodeA->adjacentNodes[i];
                if(node == nodeB) return true;

                std::cout << "Enqueuing node to visit: " << node->value << "\n";
                toVisitNodes.push(node);
            }
            visitedNodes.push_back(nodeA);
            std::cout << "\n";
        }
        return false;
    }
};

void testCreateNodes(Graph& g){
    std::cout << "---Test Create Nodes (Start)---\n";
    std::cout << "Creating Nodes:\n";

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
    std::cout << "---Test Create Nodes (End)---\n\n\n";
}

void testConnect(Graph& g){
    std::cout << "---Test Connect (Start)---\n";
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
    std::cout << "---Test Connect (End)---\n\n\n";
}

void testDisconnect(Graph& g){
    std::cout << "---Test Disconnect (Start)---\n";
    std::cout << "Disconnecting some relations:\n";
    g.disconnect("Alpha");
    
    g.listNodes();
    std::cout << "---Test Disconnect (End)---\n\n\n";
}

void testSearching(Graph& g){
    std::cout << "---Test Searching (Start)---\n";

    g.findValue("Alpha");

    g.listNodes();
    std::cout << "---Test Searching (End)---\n\n\n";
}

void testDeletion(Graph& g){
    std::cout << "---Test Deletion (Start)---\n";

    g.deleteNode(g.findValue("Delta"));
    g.listNodes();

    g.deleteNodes();
    g.listNodes();
    std::cout << "---Test Deletion (End)---\n\n\n";
}

void testReset(Graph& g){
    std::cout << "\n\n\n---Test Reset (Start)---\n";

    COUNTER_ID = 0;
    std::cout << "COUNTER_ID was reset to 0\n";

    g.deleteNodes();
    
    std::cout << "---Test Reset (End)---\n\n\n";
}

void testBreadthFirstSearch(Graph& g){
    std::cout << "\n\n\n---Test Breadth First Search (Start)---\n";

    g.breadthFirstSearch(7, 6);
    g.breadthFirstSearch(9, 4);
    g.breadthFirstSearch(1, 1);
    g.breadthFirstSearch(1, 10);
    g.breadthFirstSearch(10, 11);
    
    std::cout << "---Test Breadth First Search (End)---\n\n\n";
}

void testAddDisconnectedNodes(Graph& g){
    std::cout << "\n\n\n---Test Add Disconnected Nodes (Start)---\n";

    g.addNode("Juliet");
    g.addNode("Kilo");
    g.listNodes();

    std::cout << "---Test Add Disconnected Nodes (End)---\n\n\n";
}

int main(){
    Graph g = Graph();

    testCreateNodes(g);

    testConnect(g);

    testDisconnect(g);

    testSearching(g);

    testDeletion(g);

    // fresh nodes & reseting the ID
    testReset(g);

    testCreateNodes(g);
    testConnect(g);
    testBreadthFirstSearch(g);


    // fresh nodes & reseting the ID
    testReset(g);

    testCreateNodes(g);
    testAddDisconnectedNodes(g);
    testConnect(g);
    testBreadthFirstSearch(g);

    return 0;
}
