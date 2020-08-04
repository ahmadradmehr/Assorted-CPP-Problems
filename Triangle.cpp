/* Triangle
 * 
 * Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.
 * For example, given the following triangle
 * [
 *      [2],
 *     [3,4],
 *    [6,5,7],
 *   [4,1,8,3]
 * ]
 * 
 * The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
 * 
 * Note:
 * Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.
 */
 
class Triangle {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        map<pair<int, int>, int> memory;
        return pathSum(triangle, 0, 0, memory);
    }
    int pathSum(vector<vector<int>> &triangle, int row, int ind, map<pair<int, int>, int> &memory) {
        if (triangle.size() == row)
            return 0;
        if (memory.count({row, ind}) == 0)
            memory[{row, ind}] = min(pathSum(triangle, row+1, ind, memory),
                                     pathSum(triangle, row+1, ind+1, memory)) + 
                                    triangle.at(row).at(ind);
        return memory[{row, ind}];
    }
};