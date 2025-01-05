class Solution {
public:
    int compress(vector<char>& chars) {
        int size = chars.size();
        int i = 0, index = 0;

        while(i < size) {
            char curr = chars[i];
            int count = 0;

            while(i < size && chars[i] == curr) {
                i++;
                count++;
            }

            chars[index++] = curr;

            if(count > 1) {
                string s = to_string(count);
                for(char c : s) {
                    chars[index++] = c;
                }
            }
        }
        
        chars.resize(index);

        return chars.size();
    }
};