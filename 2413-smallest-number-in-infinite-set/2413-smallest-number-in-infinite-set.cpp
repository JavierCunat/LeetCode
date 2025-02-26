class SmallestInfiniteSet {
    //similar to huffman encoding but not rlly since not by frequency
    //infinite set but our constraints say we should have 1-1000
   
private:
    set<int> available;
    int nextSmallest;

public:
    SmallestInfiniteSet() {
       nextSmallest = 1;
    }
    
    int popSmallest() {
        if (!available.empty()) {
            int smallest = *available.begin();
            available.erase(smallest);
            return smallest;
        }
        return nextSmallest++;
    }
    
    void addBack(int num) {
       if (num < nextSmallest) {
            available.insert(num);
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */