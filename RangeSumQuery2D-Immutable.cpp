/* Range Sum Query 2D - Immutable
 * 
 * Given a 2D matrix matrix, find the sum of the elements inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).
 * 
 * Range Sum Query 2D
 * The above rectangle (with the red border) is defined by (row1, col1) = (2, 1) and (row2, col2) = (4, 3), which contains sum = 8.
 * 
 * Example:
 * Given matrix = [
 *   [3, 0, 1, 4, 2],
 *   [5, 6, 3, 2, 1],
 *   [1, 2, 0, 1, 5],
 *   [4, 1, 0, 1, 7],
 *   [1, 0, 3, 0, 5]
 * ]
 * sumRegion(2, 1, 4, 3) -> 8
 * sumRegion(1, 1, 2, 2) -> 11
 * sumRegion(1, 2, 2, 4) -> 12
 * 
 * Note:
 * You may assume that the matrix does not change.
 * There are many calls to sumRegion function.
 * You may assume that row1 ≤ row2 and col1 ≤ col2.
 */
 
class NumMatrix {
    vector<vector<int>> matrix_sums;
public:
    NumMatrix(vector<vector<int>>& matrix): matrix_sums {matrix} {
        if (matrix.size() > 0 && matrix.front().size() > 0) {
            matrix_sums.at(0).at(0) = matrix.at(0).at(0);
            for (int i {1}; i < matrix.front().size(); i++) {
                matrix_sums.at(0).at(i) = matrix_sums.at(0).at(i-1) + matrix.at(0).at(i);
            }
            for (int i {1}; i < matrix.size(); i++) {
                matrix_sums.at(i).at(0) = matrix_sums.at(i-1).at(0) + matrix.at(i).at(0);
            }
            for (int i {1}; i < matrix.size(); i++) {
                for (int j {1}; j < matrix.front().size(); j++) {
                    matrix_sums.at(i).at(j) = matrix_sums.at(i-1).at(j) + matrix_sums.at(i).at(j-1) - matrix_sums.at(i-1).at(j-1) + matrix.at(i).at(j);
                }
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum {0};
        if (row1 > 0 && col1 > 0)
            sum += matrix_sums.at(row1-1).at(col2) + matrix_sums.at(row2).at(col1-1) - matrix_sums.at(row1-1).at(col1-1);
        else if (row1 > 0)
            sum += matrix_sums.at(row1-1).at(col2);
        else if (col1 > 0)
            sum += matrix_sums.at(row2).at(col1-1);
        return matrix_sums.at(row2).at(col2) - sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */