class Trie {

private:
    struct trie{
        trie *children[26];
        bool isEnd = false;
        trie() {
            for(int i = 0; i < 26; i++) children[i] = nullptr;
            isEnd = false;
        }
    };
    trie *root;

public:
    Trie() {
        root = new trie();
    }
    
    void insert(string word) {
        trie* node = root;

        for(char c : word) {
           if(node->children[c - 'a'] == nullptr) {
            node->children[c- 'a'] = new trie();
           }
           node = node->children[c - 'a'];
        }
        node->isEnd = true;
    }
    
    bool search(string word) {
        trie* node = root;
        for(char c : word) {
            if(node->children[c - 'a'] == nullptr) return false;
            node = node->children[c - 'a'];
        }

        return node->isEnd;
    }
    
    bool startsWith(string prefix) {
        trie* node = root;
        for(char c : prefix) {
            if(node->children[c - 'a'] == nullptr) return false;
            node = node->children[c - 'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */