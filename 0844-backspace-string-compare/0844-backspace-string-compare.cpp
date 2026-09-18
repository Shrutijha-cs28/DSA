class Solution {
public:

    string process(string str) {
        string result;

        for (char c : str) {

            if (c != '#') {
                result.push_back(c);
            }
            else {
                if (!result.empty()) {
                    result.pop_back();
                }
            }
        }

        return result;
    }

    bool backspaceCompare(string s, string t) {

        string finalS = process(s);
        string finalT = process(t);

        return finalS == finalT;
    }
};