/* Pascal's Triangle
 * 
 * Given a non-negative integer numRows, generate the first numRows of Pascal's triangle.
 * In Pascal's triangle, each number is the sum of the two numbers directly above it.
 * 
 * Example:
 * Input: 5
 * Output:
 * [
 *     [1],
 *    [1,1],
 *   [1,2,1],
 *  [1,3,3,1],
 * [1,4,6,4,1]
 * ]
 */
 
class PascalTriangle {
public:
    vector<vector<int>> generate(int numRows) {
        if (numRows == 0) return {};
        int n {1};
        vector<int> v;
        vector<vector<int>> vv;
        while (n <= numRows) {
            for (int i {0}; i < n; i++) {
                if (i == 0 || i == n-1)
                    v.push_back(1);
                else
                    v.push_back(vv[n-2][i-1]+vv[n-2][i]);
            }
            vv.push_back(v);
            v.clear();
            n++;
        }
        return vv;
    }
};