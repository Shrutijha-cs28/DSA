class Solution {
public:
    bool buddyStrings(string s, string goal) {
        // Lengths must be equal
        if (s.length() != goal.length()) {
            return false;
        }
        // Case 1: Strings are already equal
        if (s == goal) {

            // Check if any character appears twice
            vector<int> freq(26, 0);

            for (char c : s) {
                freq[c - 'a']++;
                if (freq[c - 'a'] >= 2) {
                    return true;
                }
            }
            return false;
        }

        // Case 2: Strings are different
        vector<int> diff;

        for (int i = 0; i < s.length(); i++) {

            if (s[i] != goal[i]) {
                diff.push_back(i);
            }
        }

        // There must be exactly 2 different positions
        if (diff.size() != 2) {
            return false;
        }

        int i = diff[0];
        int j = diff[1];

        // Check whether swapping them makes s equal to goal
        return s[i] == goal[j] && s[j] == goal[i];
    }
};