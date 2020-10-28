/*
 * ### Single Element in a Sorted Array ###
 * 
 * 
 * You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once. Find this single element that appears only once.
 * Follow up: Your solution should run in O(log n) time and O(1) space.
 * 
 * Example 1:
 * Input: nums = [1,1,2,3,3,4,4,8,8]
 * Output: 2
 * 
 * Example 2:
 * Input: nums = [3,3,7,7,10,11,11]
 * Output: 10
 * 
 * Constraints:
 * 1 <= nums.length <= 10^5
 * 0 <= nums[i] <= 10^5
 */


class SingleElementSortedArray {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if (nums.size() == 1)
            return nums.at(0);
        int f {0}, l = nums.size()-1, m = (f + l) / 2;
        while (l - f > 2) {
            if (m % 2 == 0 && nums.at(m) == nums.at(m-1) ||
               m % 2 == 1 && nums.at(m) == nums.at(m+1))
                l = m;
            else if (m % 2 == 1 && nums.at(m) == nums.at(m-1) ||
               m % 2 == 0 && nums.at(m) == nums.at(m+1))
                f = m;
            else
                return nums.at(m);
            m = (f + l) / 2;
        }
        if (nums.at(f) == nums.at(f+1))
            return nums.at(l);
        return nums.at(f);
    }
};