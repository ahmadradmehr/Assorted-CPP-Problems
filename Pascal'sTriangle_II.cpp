/* Pascal's Triangle II
 * 
 * Given a non-negative index k where k ≤ 33, return the kth index row of the Pascal's triangle.
 * Note that the row index starts from 0.
 * 
 * In Pascal's triangle, each number is the sum of the two numbers directly above it.
 * Example:
 * Input: 3
 * Output: [1,3,3,1]
 * 
 * Follow up:
 * Could you optimize your algorithm to use only O(k) extra space?
 */
 
class PascalTriangle_II {
public:
    vector<int> getRow(int rowIndex) {
        int n {0};
        vector<int> v1, v2;
        while (n <= rowIndex) {
            for (int i {0}; i <= n; i++) {
                if (i == 0 || i == n)
                    v1.push_back(1);
                else
                    v1.push_back(v2[i-1] + v2[i]);
            }
            v2 = v1;
            v1.clear();
            n++;
        }
        return v2;
    }
};