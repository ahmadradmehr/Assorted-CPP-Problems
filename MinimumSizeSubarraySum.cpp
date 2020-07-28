/* Minimum Size Subarray Sum
 * 
 * Given an array of n positive integers and a positive integer s, find the minimal length of a contiguous subarray of which the sum ≥ s.
 * If there isn't one, return 0 instead.
 * 
 * Example: 
 * Input: s = 7, nums = [2,3,1,2,4,3]
 * Output: 2
 * Explanation: the subarray [4,3] has the minimal length under the problem constraint.
 * 
 * Follow up:
 * If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log n).
 */
 
class MinSubArrayLen {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int len {INT_MAX}, sum {0}, j {0};
        bool found = false;
        for (int i {0}; i < nums.size(); i++) {
            while (j < nums.size() && sum < s) {
                sum += nums.at(j);
                j++;
            }
            if (sum < s)
                break;
            len = min(len, j - i);
            sum -= nums.at(i);
            found = true;
        }
        if (!found)
            return 0;
        return len;
    }
};