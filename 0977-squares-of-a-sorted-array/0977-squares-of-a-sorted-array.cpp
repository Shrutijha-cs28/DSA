class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {

        int n = nums.size();

        vector<int> answer(n);

        int left = 0;
        int right = n - 1;

        for (int pos = n - 1; pos >= 0; pos--) {

            int leftSquare = nums[left] * nums[left];
            int rightSquare = nums[right] * nums[right];

            if (leftSquare > rightSquare) {
                answer[pos] = leftSquare;
                left++;
            }
            else {
                answer[pos] = rightSquare;
                right--;
            }
        }

        return answer;
    }
};