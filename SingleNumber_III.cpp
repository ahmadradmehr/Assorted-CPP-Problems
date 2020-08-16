/* Single Number III
 * 
 * Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once.
 * 
 * Example:
 * Input:  [1,2,1,3,2,5]
 * Output: [3,5]
 * 
 * Note:
 * The order of the result is not important. So in the above example, [5, 3] is also correct.
 * Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?
 */
 
class SingleNumber_III {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int diff = accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
        diff &= -diff;
        vector<int> res (2, 0);
        for (auto &n: nums) {
            if (diff & n)
                res.at(0) ^= n;
            else
                res.at(1) ^= n;
        }
        return res;
    }
};