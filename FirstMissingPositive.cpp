/*
 * ### First Missing Positive ###
 * 
 * 
 * Given an unsorted integer array, find the smallest missing positive integer.
 * 
 * Example 1:
 * Input: [1,2,0]
 * Output: 3
 * 
 * Example 2:
 * Input: [3,4,-1,1]
 * Output: 2
 * 
 * Example 3:
 * Input: [7,8,9,11,12]
 * Output: 1
 * 
 * Follow up:
 * Your algorithm should run in O(n) time and uses constant extra space.
 */


class FirstMissingPositive {
public:
    int firstMissingPositive(vector<int>& nums) {
        for (int i {0}; i < nums.size(); i++) {
            while (nums[i] > 0 && nums[i] <= nums.size() && 
                   nums[i] != i+1 && nums[i] != nums[nums[i]-1]) {
                swap(nums[i], nums[nums[i]-1]);
            }
        }
        for (int i {0}; i < nums.size(); i++) {
            if (nums[i] != i+1)
                return i+1;
        }
        return nums.size()+1;
    }
};