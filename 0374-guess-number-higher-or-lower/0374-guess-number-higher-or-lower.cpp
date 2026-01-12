/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        //reviewed 1/11/2026
        int lowerBound = 1;

        while(lowerBound <= n) {
            int x = (n-lowerBound) / 2 + lowerBound; //same as (n-lowerbound) / 2 but to avoid overflow
            if(guess(x) == -1) {
                n = x-1; //we can set upperbound to our guess - 1 to move things and since guess is too high
            } else if(guess(x) == 1) {
                lowerBound = x+1; //same here
            } else {
                return x;
            }
        }
        
        return 1;
    }
};
