/* Find First and Last Position of Element in Sorted Array
 * 
 * Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.
 * 
 * Your algorithm's runtime complexity must be in the order of O(log n).
 * If the target is not found in the array, return [-1, -1].
 * Example 1:
 * Input: nums = [5,7,7,8,8,10], target = 8
 * Output: [3,4]
 * 
 * Example 2:
 * Input: nums = [5,7,7,8,8,10], target = 6
 * Output: [-1,-1]
 * 
 * Constraints:
 * 0 <= nums.length <= 10^5
 * -10^9 <= nums[i] <= 10^9
 * nums is a non decreasing array.
 * -10^9 <= target <= 10^9
 */
 
class SearchRange {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty())
            return {-1, -1};
        int l = lowerBand(nums, target);
        int r = lowerBand(nums, target+1)-1;
        if (l < nums.size() && nums.at(l) == target)
            return {l, r};
        return {-1, -1};
    }
    
    int lowerBand(vector<int> &nums, int target) {
        int l = 0, r = nums.size()-1, m = (l + r) / 2;
        while (l <= r) {
            if (nums.at(m) >= target)
                r = m - 1;
            else if (nums.at(m) < target)
                l = m + 1;
            m = (l + r) / 2;
        }
        return l;
    }
};