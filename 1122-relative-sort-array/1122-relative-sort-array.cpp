class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1,
                                   vector<int>& arr2) {

        vector<int> freq(1001, 0);

        // Count frequency
        for (int num : arr1) {
            freq[num]++;
        }

        vector<int> answer;

        // Put arr2 elements first
        for (int num : arr2) {

            while (freq[num] > 0) {
                answer.push_back(num);
                freq[num]--;
            }
        }

        // Put remaining elements in sorted order
        for (int num = 0; num <= 1000; num++) {

            while (freq[num] > 0) {
                answer.push_back(num);
                freq[num]--;
            }
        }

        return answer;
    }
};