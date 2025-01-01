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

    //intuition works but we can optimize from beats 14% to 42%
    //use static const for hash set
    //if we find that the first pointer is already not a vowel we can increase and just continue instead of overhead
    //same for second pointer
    //use swap function instead of making a temp and doing manual swapping
    //instead of hash set we can make our own vector to directly access the index without it needing to do hashing
    //lmao this gets to the point where the code is complicated and not very readable but fast nonetheless
    string reverseVowels(string s) {
    int i = 0, j = s.size()-1;
    static const vector<bool> isVowel = []() {
    vector<bool> v(256, false);
    v['a'] = v['e'] = v['i'] = v['o'] = v['u'] = true;
    v['A'] = v['E'] = v['I'] = v['O'] = v['U'] = true;
    return v;
    }();

    while(i <= j) {
        if(!isVowel[s[i]]) { i++; continue; }
        if(!isVowel[s[j]]) { j--; continue; }
       swap(s[i], s[j]);
       i++;
       j--;
    }
    return s;
}
};