/* Product of Array Except Self
 * 
 * Given an array nums of n integers where n > 1,  return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].
 * 
 * Example:
 * Input:  [1,2,3,4]
 * Output: [24,12,8,6]
 * 
 * Constraint: It's guaranteed that the product of the elements of any prefix or suffix of the array (including the whole array) fits in a 32 bit integer.
 * 
 * Note: Please solve it without division and in O(n).
 * 
 * Follow up:
 * Could you solve it with constant space complexity? (The output array does not count as extra space for the purpose of space complexity analysis.)
 */
 
class ProductExceptSelf {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> vec1 (n, 1), vec2 (n, 1);
        for (int i {1}; i < n; i++) {
            vec1.at(i) = vec1.at(i-1) * nums.at(i-1);
            vec2.at(n-i-1) = vec2.at(n-i) * nums.at(n-i);
        }
        for (int i {0}; i < n; i++) {
            vec1.at(i) *= vec2.at(i);
        }
        return vec1;
    }
};