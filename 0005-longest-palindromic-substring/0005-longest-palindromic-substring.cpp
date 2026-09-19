class Solution {
public:
    string expand(string s, int left, int right) {
        while (left >= 0 &&
               right < s.length() &&
               s[left] == s[right]) {

            left--;
            right++;
        }
        // left and right have gone one step outside
        return s.substr(left + 1, right - left - 1);
    }

    string longestPalindrome(string s) {

        string ans = "";
        for (int i = 0; i < s.length(); i++) {

            // Odd length palindrome
            string odd = expand(s, i, i);

            // Even length palindrome
            string even = expand(s, i, i + 1);

            // Update answer if odd palindrome is longer
            if (odd.length() > ans.length()) {
                ans = odd;
            }

            // Update answer if even palindrome is longer
            if (even.length() > ans.length()) {
                ans = even;
            }
        }

        return ans;
    }
};