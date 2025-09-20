class Solution {
public:
    string toGoatLatin(string sentence) {
        std::vector<std::string> words;
        std::istringstream iss(sentence);
        string word;

        set<char> vowel = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

        while (iss >> word) { 
            words.push_back(word);
        }

        for(int i = 0; i < words.size(); i++) {
            if(vowel.count(words[i][0]) > 0) {
                words[i] += "ma";
            } else {
                char temp = words[i][0];
                words[i].erase(0, 1);
                words[i] += temp;
                words[i] += "ma";
            }
            words[i].append(i + 1, 'a');
        }

        string res = "";

        for(int i = 0; i < words.size(); i++) {
            if(i != words.size()-1) {
                res += words[i] + " ";
            } else {
                res += words[i];
            }
        }

        return res;
    }
};