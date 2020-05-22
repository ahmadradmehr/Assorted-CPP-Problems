/* Search in Rotated Sorted Array
 * 
 * Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
 * (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).
 * You are given a target value to search. If found in the array return its index, otherwise return -1.
 * You may assume no duplicate exists in the array.
 * Your algorithm's runtime complexity must be in the order of O(log n).
 * 
 * Example 1:
 * Input: nums = [4,5,6,7,0,1,2], target = 0
 * Output: 4
 * 
 * Example 2:
 * Input: nums = [4,5,6,7,0,1,2], target = 3
 * Output: -1
 */
 
class SearchInRotatedSortedArray {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty())
            return -1;
        int ind = -1, f = 0, b = nums.size()-1, m = (f + b) / 2;
        while (true) {
            if (b - f <= 1) {
                if (nums.at(f) == target)
                    ind = f;
                else if (nums.at(b) == target) 
                    ind = b;
                break;
            }
            if (target >= nums.at(f) && (target <= nums.at(m) || (target > nums.at(m) && nums.at(m)-nums.at(f) <= 0)) || (target <= nums.at(f) && target <= nums.at(m) && nums.at(m)-nums.at(f) <= 0))
                b = m;
            else
                f = m+1;
            m = (f + b) / 2;
        }
        return ind;
    }
};