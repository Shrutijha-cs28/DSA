class Solution {
public:
    string toGoatLatin(string sentence) {
        stringstream ss(sentence);
        string word;
        string result = "";
        int index = 1;
     while (ss >> word) {
            // Check if first character is a vowel
            char first = tolower(word[0]);

            if (first != 'a' && first != 'e' && 
                first != 'i' && first != 'o' && 
                first != 'u') {
                
                // Move first character to the end
                word = word.substr(1) + word[0];
            }

            // Add "ma"
            word += "ma";

            // Add 'a' according to word index
            word += string(index, 'a');

            // Add word to result
            if (!result.empty()) {
                result += " ";
            }

            result += word;
            index++;
        }

        return result;
    }
};

       