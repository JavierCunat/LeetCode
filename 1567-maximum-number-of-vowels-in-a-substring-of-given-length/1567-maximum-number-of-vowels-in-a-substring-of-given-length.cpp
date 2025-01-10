class Solution {
public:
    int maxVowels(string s, int k) {
        int size = s.size();
        int count = 0, maxVowels = 0;
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};

        //do the sliding window approach of setting the first window
        for(int i = 0; i < k; i++) {
            if(vowels.count(s[i]) > 0) {
                count++;
            }
        }

        maxVowels = count;

        for(int i = k; i < size; i++) {
            if(maxVowels == k) {return k;}
            //remove oldest char
            if(vowels.count(s[i-k]) > 0) {
                count--;
            } 
            //add newest char
            if(vowels.count(s[i]) > 0) {
                count++;
            }

            maxVowels = max(count, maxVowels);
        }

        return maxVowels;
       
    }
};