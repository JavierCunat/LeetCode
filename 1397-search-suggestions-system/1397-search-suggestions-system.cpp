class Solution {
public:

    struct Trie {
        Trie* children[26];
        Trie() {
            for(int i = 0; i < 26; i++) {
                children[i] = nullptr;
                isEnd = false;
            }
        }
        bool isEnd = false;
    };


    void dfs(Trie* node, string& curr, vector<string>& words) {
        if (words.size() == 3) return;  // limit reached
        if (node->isEnd) {
            words.push_back(curr);
        }
    
        for (int i = 0; i < 26; i++) {
            if (node->children[i] != nullptr) {
                curr.push_back('a' + i);
                dfs(node->children[i], curr, words);
                curr.pop_back();
            }
        }
    }

    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        //populate the trie with the words
        Trie *root = new Trie();

        for(string product : products) {
            Trie *node = root;
            for(char c : product) {
                if(node->children[c - 'a'] == nullptr) {
                    node->children[c - 'a'] = new Trie();
                }
                node = node->children[c - 'a'];
            }
            node->isEnd = true;
        }

        int size = searchWord.length();
        vector<vector<string>> res(size);
        for(int i = 0; i < size; i++) {
            string prefix = searchWord.substr(0, i + 1);
            Trie* node = root;

            for(char c : prefix) {
                if(node == nullptr) break;
                node = node->children[c - 'a'];
            }

            if (node != nullptr) {
                dfs(node, prefix, res[i]);
            }
        }

        return res;
    }
};