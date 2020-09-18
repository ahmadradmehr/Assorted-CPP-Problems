/*
 * ### Partition Equal Subset Sum ###
 * 
 * 
 * Given a non-empty array containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.
 * 
 * Note:
 * Each of the array element will not exceed 100.
 * The array size will not exceed 200.
 * 
 * Example 1:
 * Input: [1, 5, 11, 5]
 * Output: true
 * Explanation: The array can be partitioned as [1, 5, 5] and [11].
 * 
 * Example 2:
 * Input: [1, 2, 3, 5]
 * Output: false
 * Explanation: The array cannot be partitioned into equal sum subsets.
 */


class PartitionEqualSubsetSum {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 == 1)
            return false;
        sort(nums.rbegin(), nums.rend());
        return checker(nums, 0, sum/2);
    }
    
    bool checker(vector<int> &nums, int i, int goal) {
        if (goal == nums.at(i))
            return true;
        if (goal < nums.at(i) || i == nums.size() - 1)
            return false;
        return checker(nums, i+1, goal-nums.at(i)) || checker(nums, i+1, goal);
    }
};