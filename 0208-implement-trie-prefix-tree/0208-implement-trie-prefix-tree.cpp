struct Node{
    bool isWord = false;
    Node* links[26] = {};
    
    bool isContainsKey(char ch){
        return links[ch - 'a'] != NULL;
    }
    
    Node* getKey(char ch){
        return links[ch - 'a'];
    }
    
    void setKey(char ch){
        links[ch - 'a'] = new Node;
    }
};

class Trie {
    Node* root;
public:
    Trie() {
        root = new Node;
    }
    
    void insert(string word) {
        Node* node = root;
        for(char &ch: word){
            if(!node->isContainsKey(ch)) node->setKey(ch);
            node = node->getKey(ch);
        }
        node->isWord = true;
    }
    
    bool search(string word, bool prefixMatch = false) {
        Node* node = root;
        for(char &ch: word){
            if(!node->isContainsKey(ch)) return false;
            node = node->getKey(ch);
        }
        
        if(prefixMatch) return true;
        return node->isWord;
    }
    
    bool startsWith(string prefix) {
        return search(prefix, true);
    }
};