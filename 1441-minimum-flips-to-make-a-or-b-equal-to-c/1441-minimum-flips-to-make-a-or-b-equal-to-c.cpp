class Solution {
public:
    int minFlips(int a, int b, int c) {
        size_t flips = 0;
        while(a > 0 || b > 0 || c > 0) {
            //extract the LSB of each int
            //reviewed 8/20/2025
            int bit_a = a & 1;
            int bit_b = b & 1;
            int bit_c = c & 1;

            if( (bit_a | bit_b) != bit_c ) {
                if(bit_c == 1) flips++; //we only need to flip one bit
                else flips+= bit_a + bit_b; //we have two ones in a,b and need to flip to 0 which requires two flips
            }

            //shift all to the right to process next bit
            a >>= 1;
            b >>= 1;
            c >>= 1;
        }
    
        return flips;
    };
};
