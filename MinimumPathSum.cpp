/* Minimum Path Sum
 * 
 * Given a m x n grid filled with non-negative numbers,
 * find a path from top left to bottom right which minimizes the sum of all numbers along its path.
 * 
 * Note: You can only move either down or right at any point in time.
 * 
 * Example:
 * Input:
 * [
 *   [1,3,1],
 *   [1,5,1],
 *   [4,2,1]
 * ]
 * Output: 7
 * Explanation: Because the path 1→3→1→1→1 minimizes the sum.
 */
 
class MinimumPathSum {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<int> vec (grid.at(0).size(), 0);
        for (int i {0}; i < grid.size(); i++) {
            for (int j {0}; j < vec.size(); j++) {
                if (i == 0 && j == 0)
                    vec.at(0) = grid.at(i).at(0);
                else if (i == 0)
                    vec.at(j) = vec.at(j-1) + grid.at(i).at(j);
                else if (j == 0)
                    vec.at(j) = vec.at(j) + grid.at(i).at(j);
                else
                    vec.at(j) = grid.at(i).at(j) + min(vec.at(j), vec.at(j-1));
            }
        }
        return vec.back();
    }
};