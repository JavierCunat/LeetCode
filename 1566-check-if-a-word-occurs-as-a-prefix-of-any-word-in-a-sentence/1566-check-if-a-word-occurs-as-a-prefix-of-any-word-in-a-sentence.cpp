class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
    
    //string split sort of function would help but ig none in C++ std so we make our own
    vector<string> words = stringSplit(sentence, ' ');
    
    int wordCounter = 1;
     for (string word : words) {
        if (word.size() >= searchWord.size() && 
            word.substr(0, searchWord.size()) == searchWord) {
            return wordCounter;
        }
        wordCounter++;
    }
    return -1;
    }

    vector<string> stringSplit(string sentence, char deliminator) {
    vector<string> res;
    int indexOfDel = sentence.find(deliminator);

        while(indexOfDel != -1) {
            string word = sentence.substr(0, indexOfDel);
            res.push_back(word);
            sentence.erase(sentence.begin(), sentence.begin() + indexOfDel + 1);
            indexOfDel = sentence.find(deliminator);
        }

        //add last word
        if (!sentence.empty()) {
            res.push_back(sentence);
        }

        return res;
    }


};