
class Solution {
public:
    string makeGood(string s) {
        string result = "";

        for (char ch : s) {
            
            if (!result.empty() &&
                abs(result.back() - ch) == 32) {
                
                // Remove the previous character
                result.pop_back();
            }
            else {
                // Add the current character
                result.push_back(ch);
            }
        }

        return result;
    }
};
