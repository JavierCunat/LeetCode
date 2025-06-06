class Solution {
public:
    int minChanges(int n, int k) {
        //use XOR to see which bits we need to flip then count the number of ones by dividing by 2 and getting the remainders
        if ((n & k) != k) return -1; //if MSB of n is bigger than k 

        size_t numberOfones = n ^ k;
        size_t changes = 0;
        while(numberOfones > 0) {
            changes+= numberOfones & 1; //same as doing % 2 to check if last bit is 1 or 0
            numberOfones >>= 1; //same as doing numberOfOnes=/2
        }
        return changes;
    }
};