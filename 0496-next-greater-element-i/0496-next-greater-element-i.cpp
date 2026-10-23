#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1,
                                   vector<int>& nums2) {
        stack<int> st;
        unordered_map<int, int> mp;

        // Find next greater elements in nums2
        for (int num : nums2) {

            // If current number is greater than the stack's top,
            // it is the next greater element for that top value.
            while (!st.empty() && num > st.top()) {
                mp[st.top()] = num;
                st.pop();
            }

            // Current number may have a greater element later
            st.push(num);
        }

        // Remaining elements have no greater element on the right
        while (!st.empty()) {
            mp[st.top()] = -1;
            st.pop();
        }

        // Get answers for nums1 in its original order
        vector<int> ans;

        for (int num : nums1) {
            ans.push_back(mp[num]);
        }

        return ans;
    }
};
