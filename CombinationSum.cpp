/* Combination Sum
 * 
 * Given a set of candidate numbers (candidates) (without duplicates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.
 * The same repeated number may be chosen from candidates unlimited number of times.
 * 
 * Note:
 * All numbers (including target) will be positive integers.
 * The solution set must not contain duplicate combinations.
 * 
 * Example 1:
 * Input: candidates = [2,3,6,7], target = 7,
 * A solution set is:
 * [
 *   [7],
 *   [2,2,3]
 * ]
 * 
 * Example 2:
 * Input: candidates = [2,3,5], target = 8,
 * A solution set is:
 * [
 *   [2,2,2,2],
 *   [2,3,3],
 *   [3,5]
 * ]
 * 
 * Constraints:
 * 1 <= candidates.length <= 30
 * 1 <= candidates[i] <= 200
 * Each element of candidate is unique.
 * 1 <= target <= 500
 */
 
class CombinationSum {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> combination;
        createCombination(candidates, combination, res, target, 0);
        return res;
    }
    
    void createCombination(vector<int> &candidates, vector<int> &combination, vector<vector<int>> &res, int target, int pos) {
        if (!target) {
            res.push_back(combination);
            return;
        }
        for (int i {pos}; i < candidates.size() && target - candidates.at(i) >= 0; i++) {
            combination.push_back(candidates.at(i));
            createCombination(candidates, combination, res, target - candidates.at(i), i);
            combination.pop_back();
        }
    }
};