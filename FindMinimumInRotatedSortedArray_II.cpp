/* Find Minimum in Rotated Sorted Array II
 * 
 * Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
 * (i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).
 * Find the minimum element.
 * The array may contain duplicates.
 * 
 * Example 1:
 * Input: [1,3,5]
 * Output: 1
 * 
 * Example 2:
 * Input: [2,2,2,0,1]
 * Output: 0
 * 
 * Note:
 * This is a follow up problem to Find Minimum in Rotated Sorted Array.
 * Would allow duplicates affect the run-time complexity? How and why?
 */
 
class FindMinimum_II {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size()-1, m = (l + r) / 2;
        while (r - l > 0) {
            if (nums.at(l) == nums.at(m) && nums.at(m) == nums.at(r)) {
                l++;
                r--;
            } else if (nums.at(l) <= nums.at(m) && nums.at(m) <= nums.at(r))
                return nums.at(l);
            else if (nums.at(m) <= nums.at(r))
                r = m;
            else if (nums.at(m) > nums.at(r))
                l = m + 1;
            m = (l + r) / 2;
        }
        return nums.at(l);
    }
};