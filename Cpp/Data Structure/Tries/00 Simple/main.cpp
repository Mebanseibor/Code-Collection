#include <iostream>

class Trie{
    public:
    char c = '\0';
    bool isWord = false;
    Trie* tries[26] = {nullptr};

    Trie(){}
    Trie(char c){this->c = c;}

    void addWord(const std::string& word){
        if(word.empty()) return;

        char c = word[0];
        int pos = c - 'a';

        if(c<'a' || c>'z') return;

        if(tries[pos] == nullptr){
            tries[pos] = new Trie(c);
        }

        if(word.size() == 1) tries[pos]->isWord = true;
        else tries[pos]->addWord(word.substr(1));
    }

    void search(const std::string& word){
        if(word.empty()){
            if(isWord) std::cout << "Found\n";
            else std::cout << "Not Found\n";
            return;
        }

        char c = word[0];
        int pos = c - 'a';

        if(c<'a' || c>'z') {
            std::cout << "Contained invalid character\n";
            return;
        }

        if(tries[pos] == nullptr){
            std::cout << "Not Found\n";
            return;
        }

        if(word.size() == 1){
            if(tries[pos]->isWord) std::cout << "Found\n";
            else std::cout << "Not Found\n";
            return;
        }

        tries[pos]->search((word.substr(1)));
    }
};

int main(){
    Trie t = Trie();

    t.addWord("cat");
    t.addWord("car");
    t.addWord("catch");

    t.search("cat");
    t.search("cap");
    t.search("catch");
    
    return 0;
}
