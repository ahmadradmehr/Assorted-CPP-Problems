/* Maximum Product of Three Numbers
 * 
 * 
 * Given an integer array nums, find three numbers whose product is maximum and return the maximum product.
 * 
 * Example 1:
 * Input: nums = [1,2,3]
 * Output: 6
 * 
 * Example 2:
 * Input: nums = [1,2,3,4]
 * Output: 24
 * 
 * Example 3:
 * Input: nums = [-1,-2,-3]
 * Output: -6
 * 
 * Constraints:
 * 3 <= nums.length <= 104
 * -1000 <= nums[i] <= 1000
 */


class MaximumProduct {
public:
    int maximumProduct(vector<int>& nums) {
        int min1 = INT_MAX, min2 = INT_MAX, max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;
        for (auto &n: nums) {
            if (n < min2 && n < min1) {
                min1 = min2;
                min2 = n;
            } else if (n < min1) {
                min1 = n;
            } 
            if (n > max1 && n > max2 && n > max3) {
                max1 = max2;
                max2 = max3;
                max3 = n;
            } else if (n > max1 && n > max2) {
                max1 = max2;
                max2 = n;
            } else if (n > max1) {
                max1 = n;
            }
        }
        return max(min1 * min2 * max3, max1 * max2 * max3);
    }
};

// class MaximumProduct {
// public:
//     int maximumProduct(vector<int>& nums) {
//         sort(nums.begin(), nums.end());
//         return max(nums.at(0) * nums.at(1) * nums.back(), nums.at(nums.size()-3) * nums.at(nums.size()-2) * nums.back());
//     }
// };