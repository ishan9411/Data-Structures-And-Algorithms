//208. Implement Trie (Prefix Tree) 
struct Node {
    Node* links[26];
    bool flag = false;

    bool containsKey(char ch){
        if(links[ch - 'a'] != NULL){
            return true;
        }
        return false;
    }

    void put(char ch){
        Node* node = new Node();
        links[ch - 'a'] = node;
    }

    Node* get(char ch){
        return links[ch - 'a'];
    }
};
class Trie {
public:
    Node* root;

    Trie() {
        root = new Node();
    }
    
    //O(L)
    void insert(string word) {
        Node* node = root;
        for(int i = 0; i<word.length(); i++){
            if(!node->containsKey(word[i])){
                node->put(word[i]);
            }
            node = node->get(word[i]);
        }
        node->flag = true;
    }
    
    //O(L)
    bool search(string word) {
        Node* node = root;
        for(int i = 0; i<word.length(); i++){
            if(!node->containsKey(word[i])){
                return false;
            }
            node = node->get(word[i]);
        }
        return node->flag;
    }
    
    //O(L)
    bool startsWith(string prefix) {
        Node* node = root;
        for(int i = 0; i<prefix.length(); i++){
            if(!node->containsKey(prefix[i])){
                return false;
            }
            node = node->get(prefix[i]);
        }
        return true;
    }
};
