/* Search a 2D Matrix II
 * 
 * Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
 * Integers in each row are sorted in ascending from left to right.
 * Integers in each column are sorted in ascending from top to bottom.
 * 
 * Example:
 * Consider the following matrix:
 * [
 *   [1,   4,  7, 11, 15],
 *   [2,   5,  8, 12, 19],
 *   [3,   6,  9, 16, 22],
 *   [10, 13, 14, 17, 24],
 *   [18, 21, 23, 26, 30]
 * ]
 * Given target = 5, return true.
 * Given target = 20, return false.
 */
 
class SearchMatrix_II {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if (!m)
            return false;
        int n = matrix.at(0).size();
        if (!n)
            return false;
        int i = 0, j = n-1;
        while (i < m && j >= 0) {
            if (matrix.at(i).at(j) == target)
                return true;
            else if (matrix.at(i).at(j) > target)
                j--;
            else if (matrix.at(i).at(j) < target)
                i++;
        }
        return false;
    }
};

// class SearchMatrix_II {
// public:
//     bool searchMatrix(vector<vector<int>>& matrix, int target) {
//         if (matrix.empty() || matrix.at(0).empty())
//             return false;
//         int m = matrix.size(), n = matrix.at(0).size(), row = -1, col = -1;
//         for (int i {0}; i < m; i++) {
//             if (target >= matrix.at(i).front() && target <= matrix.at(i).back()) {
//                 row = i;
//                 for (int j {0}; j < n; j++) {
//                     if (target == matrix.at(i).at(j))
//                         return true;
//                     else if (target > matrix.at(i).at(j) && target < matrix.at(i).at(j+1)) {
//                         col = j;
//                         break;
//                     }
//                 }
//                 break;
//             }
//         }
//         if (row == -1)
//             return false;
//         while (true) {
//             while (row < m-1 && target > matrix.at(row+1).at(col)) {
//                 row++;
//             }
//             if (row < m-1 && target == matrix.at(row+1).at(col))
//                 return true;
//             else if (row == m-1 && target > matrix.at(row).at(col))
//                 return false;
//             if (col > 0)
//                 col--;
//             else
//                 return false;
//         }
//         return false;
//     }
// };