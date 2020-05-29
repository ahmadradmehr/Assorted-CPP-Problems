/* Permutations
 * 
 * Given a collection of distinct integers, return all possible permutations.
 * 
 * Example:
 * Input: [1,2,3]
 * Output:
 * [
 *  [1,2,3],
 *  [1,3,2],
 *  [2,1,3],
 *  [2,3,1],
 *  [3,1,2],
 *  [3,2,1]
 * ]
 */
 
class Permutation {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> perm;
        perm.push_back(nums);
        while (next_permutation(nums.begin(), nums.end()))
            perm.push_back(nums);
        return perm;
    }
};