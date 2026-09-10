class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int i = 0, j = 0;

        while (j < typed.length()) {

            // If characters match, move both pointers
            if (i < name.length() && name[i] == typed[j]) {
                i++;
                j++;
            }

            // If characters don't match, check for long press
            else if (j > 0 && typed[j] == typed[j - 1]) {
                j++;
            }

            // Character cannot be explained by name or long press
            else {
                return false;
            }
        }

        // Every character of name must be matched
        return i == name.length();
    }
};