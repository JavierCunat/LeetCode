class LRUCache {
private:
//head (MRU) ----> tail (LRU)
//use link list vecctor struct to store most recent use at front and least in the back, then pop from back

    struct Node {
        int key = 0, val = 0;
        int prev = -1;
        int next = -1;
        bool used = false;
    };

    vector<Node> nodes;
    vector<int> freeIdx;
    unordered_map<int, int> keyToIdx;
    int _capacity = 0;
    int head = -1;
    int tail = -1;

    void unlink_(int idx) {
        int p = nodes[idx].prev, n = nodes[idx].next;
        if(p == -1) head = n; else nodes[p].next = n;
        if(n == -1) tail = p; else nodes[n].prev = p;
        nodes[idx].prev = nodes[idx].next = -1;
    }

    void link_front_(int idx) {
        nodes[idx].prev = -1;
        nodes[idx].next = head;
        if (head != -1) nodes[head].prev = idx;
        head = idx;
        if (tail == -1) tail = idx;
    }

    void free_slot_(int idx) {
        nodes[idx].used = false;
        nodes[idx].prev = nodes[idx].next = -1;
        freeIdx.push_back(idx);
    }

    int alloc_slot_() {
        int idx = freeIdx.back();
        freeIdx.pop_back();
        nodes[idx].used = true;
        nodes[idx].prev = nodes[idx].next = -1;
        return idx;
    }

    void evict_tail_() {
        if (tail == -1) return;
        int idx = tail;
        unlink_(idx);
        keyToIdx.erase(nodes[idx].key);
        free_slot_(idx);
    }

public:
    LRUCache(int capacity) {
        _capacity = capacity;
        nodes.resize(_capacity);
        freeIdx.reserve(_capacity);
        for (int i = _capacity - 1; i >= 0; --i) freeIdx.push_back(i);
    }
    
    int get(int key) {
        auto it = keyToIdx.find(key);
        if(it != keyToIdx.end()) {
            int index = it->second;
            unlink_(index);
            link_front_(index);
            return nodes[index].val;
        } else {
            return -1;
        }
    }
    
    void put(int key, int value) {
        if(_capacity == 0) return;
        auto it = keyToIdx.find(key);
        if(it != keyToIdx.end()) { //update exisiting node
            int idx = it->second;
            nodes[idx].val = value;
            unlink_(idx);
            link_front_(idx);
            return;
        }

        if ((int)keyToIdx.size() == _capacity) {
            evict_tail_();
        }
        int idx = alloc_slot_();
        nodes[idx].key = key;
        nodes[idx].val = value;
        link_front_(idx);
        keyToIdx[key] = idx;

    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */