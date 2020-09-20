/*
 * ### Maximum XOR of Two Numbers in an Array ###
 * 
 * 
 * Given an integer array nums, return the maximum result of nums[i] XOR nums[j], where 0 ≤ i ≤ j < n.
 * Follow up: Could you do this in O(n) runtime?
 * 
 * Example 1:
 * Input: nums = [3,10,5,25,2,8]
 * Output: 28
 * Explanation: The maximum result is 5 XOR 25 = 28.
 * 
 * Example 2:
 * Input: nums = [0]
 * Output: 0
 * 
 * Example 3:
 * Input: nums = [2,4]
 * Output: 6
 * 
 * Example 4:
 * Input: nums = [8,10,2]
 * Output: 10
 * 
 * Example 5:
 * Input: nums = [14,70,53,83,49,91,36,80,92,51,66,70]
 * Output: 127
 * 
 * Constraints:
 * 1 <= nums.length <= 2 * 104
 * 0 <= nums[i] <= 231 - 1
 */


class FindMaximumXOR {
public:
    int findMaximumXOR(vector<int>& nums) {
        if (nums.empty() || nums.size() == 1)
            return 0;
        if (nums.size() == 2)
            return nums.front() ^ nums.back();
        list<int> set0, set1;
        int bit {0};
        for (auto &n: nums) {
            bit = max(bit, (int)log2(n) + 1);
        }
        while (bit >= 0 && set0.empty() || set1.empty()) {
            bit--;
            for (auto &n: nums) {
                if (n & (1 << bit))
                    set1.push_back(n);
                else
                    set0.push_back(n);
            }
        }
        if (set0.empty() || set1.empty())
            return 0;
        return pow(2, bit) + getMax(set0, set1, bit-1);
    }
    
    int getMax(list<int> &set0, list<int> &set1, int bit) {
        if (set0.empty() || set1.empty() || bit < 0)
            return 0;
        list<int> set0list0, set0list1, set1list0, set1list1;
        for (auto &n0: set0) {
            if (n0 & (1 << bit))
                set0list1.push_back(n0);
            else
                set0list0.push_back(n0);
        }
        for (auto &n1: set1) {
            if (n1 & (1 << bit))
                set1list1.push_back(n1);
            else
                set1list0.push_back(n1);
        }
        if (set0list0.empty() && set1list0.empty())
            return getMax(set0, set1, bit-1);
        if (set0list1.empty() && set1list1.empty())
            return getMax(set0, set1, bit-1);
        return pow(2, bit) + max(getMax(set0list0, set1list1, bit-1),
                                getMax(set0list1, set1list0, bit-1));
    }
};