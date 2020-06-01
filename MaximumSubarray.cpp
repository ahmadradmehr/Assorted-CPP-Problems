/* Maximum Subarray
 * 
 * Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.
 * 
 * Example:
 * Input: [-2,1,-3,4,-1,2,1,-5,4],
 * Output: 6
 * Explanation: [4,-1,2,1] has the largest sum = 6.
 * 
 * Follow up:
 * If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
 */
 
// class MaximumSubarray {
// public:
//     int maxSubArray(vector<int>& nums) {
//         int max_sum = nums.at(0);
//         for (size_t i{0}; i < nums.size(); i++) {
//             int temp {0};
//             for (size_t j {i}; j < nums.size(); j++) {
//                 temp += nums.at(j);
//                 if (temp >= max_sum)
//                     max_sum = temp;
//             }
//         }
//         return max_sum;
//     }
// };

class MaximumSubarray {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sum = nums.at(0);
        int max_local = 0;
        for (size_t i{0}; i < nums.size(); i++) {
            max_local = std::max(nums[i], max_local+nums[i]);
            max_sum = std::max(max_local, max_sum);
        }
        return max_sum;
    }
};