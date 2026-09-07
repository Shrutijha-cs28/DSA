class Solution {
public:

    int countDigits(int num) {

        int count = 0;

        while (num > 0) {
            num /= 10;
            count++;
        }

        return count;
    }

    int findNumbers(vector<int>& nums) {

        int answer = 0;

        for (int num : nums) {

            int digits = countDigits(num);

            if (digits % 2 == 0)
                answer++;
        }

        return answer;
    }
};