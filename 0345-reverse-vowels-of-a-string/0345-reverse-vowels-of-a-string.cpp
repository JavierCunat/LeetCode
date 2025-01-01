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

    //intuition works but we can optimize
    //use static const for hash set
    //if we find that the first pointer is already not a vowel we can increase and just continue instead of overhead
    //same for second pointer
    //use swap function instead of making a temp and doing manual swapping
    string reverseVowels(string s) {
    int i = 0;
    int j = s.size()-1;
    static const unordered_set<char> vowels = {'a', 'A', 'e', 'E', 'i', 'I', 'o', 'O', 'u', 'U'};

    while(i <= j) {
        if(!vowels.count(s[i])) {
            i++;
            continue;
        }
        if(!vowels.count(s[j])) {
            j--;
            continue;
        }
       swap(s[i], s[j]);
       i++;
       j--;
    }
    return s;
}
};