/*
 * ### Subarray Sum Equals K ###
 * 
 * 
 * Given an array of integers nums and an integer k, return the total number of continuous subarrays whose sum equals to k.
 * 
 * Example 1:
 * Input: nums = [1,1,1], k = 2
 * Output: 2
 * 
 * Example 2:
 * Input: nums = [1,2,3], k = 3
 * Output: 2
 * 
 * Constraints:
 * 1 <= nums.length <= 2 * 104
 * -1000 <= nums[i] <= 1000
 * -107 <= k <= 107
 */


class SubarraySumEqualsK {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n {0}, cur {0};
        map<int, int> m;
        m[0]++;
        for (int i {0}; i < nums.size(); i++) {
            cur += nums.at(i);
            n += m[cur-k];
            m[cur]++;
        }
        return n;
    }
};