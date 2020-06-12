/* Subsets
 * 
 * Given a set of distinct integers, nums, return all possible subsets (the power set).
 * 
 * Note: The solution set must not contain duplicate subsets.
 * 
 * Example:
 * Input: nums = [1,2,3]
 * Output:
 * [
 *   [3],
 *   [1],
 *   [2],
 *   [1,2,3],
 *   [1,3],
 *   [2,3],
 *   [1,2],
 *   []
 * ]
 */
 
class Subsets {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> vec {{}};
        for (int i {0}; i < nums.size(); i++) {
            int n = vec.size();
            for (int j {0}; j < n; j++) {
                vector<int> v = vec.at(j);
                v.push_back(nums.at(i));
                vec.push_back(v);
            }
        }
        return vec;
    }
};