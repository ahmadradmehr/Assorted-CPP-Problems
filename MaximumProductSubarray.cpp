/* *** Maximum Product Subarray ***
 * 
 * Given an integer array nums, find the contiguous subarray within an array (containing at least one number) which has the largest product.
 * 
 * Example 1:
 * Input: [2,3,-2,4]
 * Output: 6
 * Explanation: [2,3] has the largest product 6.
 * 
 * Example 2:
 * Input: [-2,0,-1]
 * Output: 0
 * Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
 */

class MaximumProductSubarray {
public:
    int maxProduct(vector<int>& nums) {
        int max_product = nums.front(), l = 0, r = 0;
        for (int i {0}; i < nums.size(); i++) {
            if (l == 0)
                l = nums.at(i);
            else
                l *= nums.at(i);
            if (r == 0)
                r = nums.at(nums.size()-1-i);
            else
                r *= nums.at(nums.size()-1-i);
            max_product = max(max_product, max(l, r));
        }
        return max_product;
    }
};