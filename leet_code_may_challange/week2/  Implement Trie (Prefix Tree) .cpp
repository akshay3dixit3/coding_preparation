class TireNode{
public:
    unordered_map<char, TireNode*> children;
    char val;
    bool isEnd = false;
    
    TireNode(){}
    
    TireNode(char v){
        this->val = v;
    }
};

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TireNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TireNode* node = root;
        for(int i = 0; i < word.size(); i++){
            char c = word[i];
            if(node->children.find(c) == node->children.end()){
                node->children[c] = new TireNode(c);                        // if not find children, creat new TireNode
            }
            
            node = node->children[c];                                               // if find move to child node
        }
        
        node->isEnd = true;                                                             // set the end of TireNode to true
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TireNode* node = root;
        for(int i = 0; i < word.size(); i++){
            char c = word[i];
            if(node->children.find(c) == node->children.end()) 
                return false;
            node = node->children[c];
        }
        
        return node->isEnd;                            // check is it at the end of the TireNode
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TireNode* node = root;
        for(int i = 0; i < prefix.size(); i++){
            char c = prefix[i];
            if(node->children.find(c) == node->children.end()) 
                return false;
            node = node->children[c];
        }
        return true;
    }
private:
    TireNode* root;
};
/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */