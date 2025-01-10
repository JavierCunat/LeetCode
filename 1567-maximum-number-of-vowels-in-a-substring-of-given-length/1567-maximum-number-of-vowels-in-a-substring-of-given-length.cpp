class Solution {
public:
    int maxVowels(string s, int k) {
        //second attempt I use direct checks instead of hash set to see if optimizes
        int size = s.size();
        int count = 0, maxVowels = 0;
        //unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};

        //do the sliding window approach of setting the first window
        for(int i = 0; i < k; i++) {
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
                count++;
            }
        }

        maxVowels = count;

        for(int i = k; i < size; i++) {
            if(maxVowels == k) {return k;}
            //remove oldest char
            if(s[i-k] == 'a' || s[i-k] == 'e' || s[i-k] == 'i' || s[i-k] == 'o' || s[i-k] == 'u') {
                count--;
            } 
            //add newest char
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
                count++;
            }

            maxVowels = max(count, maxVowels);
        }

        return maxVowels;
       
    }
};