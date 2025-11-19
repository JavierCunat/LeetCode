class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if(str1+str2 != str2+str1) { return ""; } //this matches the intuition that if str1 is even str2 must be even and vice-versa, must share a repeating pattern

        //use euclidean algo to compute gcd
        int s1 = str1.size(), s2 = str2.size();
        while(s2 != 0) {
            int temp = s2;
            s2 = s1 % s2;//gcd where s1 == 0 and s2 == 0
            s1 = temp;
        }

        return str1.substr(0, s1);
    }
    
};