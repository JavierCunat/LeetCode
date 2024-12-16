class Solution {
public:
    //edge cases 
    //empty string return empty string
    //odd n of vowels don't switch middle
    //even swap first with last, second with second to last ...

    //intution
    //1. set cotaining vowels in both upper and lower
    //2. two pointer starting from front and back unitl find vowel
    //3. if found swap, if not don't change anything
    //4. return reversed string vowels
    string reverseVowels(string s) {
    int i = 0;
    int j = s.size()-1;
    unordered_set<char> vowels = {'a', 'A', 'e', 'E', 'i', 'I', 'o', 'O', 'u', 'U'};

    while(i <= j) {
        if(vowels.count(s[i])) {
            char v1 = s[i];
            if(vowels.count(s[j])) {
                char v2 = s[j];
                s[i] = v2;
                s[j] = v1;
                i++;
                j--;
            } else {
                j--;
            }
        } else {
            i++;
        }
    }
    return s;
}
};