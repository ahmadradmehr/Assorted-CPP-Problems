/* Spiral Matrix II
 * 
 * Given a positive integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.
 * 
 * Example:
 * Input: 3
 * Output:
 * [
 *   [ 1, 2, 3 ],
 *   [ 8, 9, 4 ],
 *   [ 7, 6, 5 ]
 * ]
 */
 
class SpiralMatrix_II {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> vec (n, vector<int> (n, 0));
        int num {1}, min_i {0}, min_j {0}, max_i {n-1}, max_j {n-1};
        while (max_j >= min_j && max_i >= min_i) {
            for (int j = min_j; j <= max_j; j++) {
                vec.at(min_i).at(j) = num++;
            }
            min_i++;
            for (int i = min_i; i <= max_i; i++) {
                vec.at(i).at(max_j) = num++;
            }
            max_j--;
            for (int j = max_j; j >= min_j; j--) {
                vec.at(max_i).at(j) = num++;
            }
            max_i--;
            for (int i = max_i; i >= min_i; i--) {
                vec.at(i).at(min_j) = num++;
            }
            min_j++;
        }
        return vec;
    }
};

// class SpiralMatrix_II {
// public:
//     vector<vector<int>> generateMatrix(int n) {
//         vector<vector<int>> vec (n, vector<int> (n, 0));
//         vec.front().front() = 1;
//         propagate(vec, 0, 0, "right", n, n-1, n-1, 1, 0);
//         return vec;
//     }
    
//     void propagate(vector<vector<int>> &vec, int i, int j, string dir, int n, int max_i, int max_j, int min_i, int min_j) {
//         if (vec.at(i).at(j) == n * n)
//             return;
//         if (dir == "right" && j < max_j) {
//             vec.at(i).at(j+1) = vec.at(i).at(j) + 1;
//             propagate(vec, i, j+1, "right", n, max_i, max_j, min_i, min_j);
//         } else if (dir == "right" && j == max_j) {
//             vec.at(i+1).at(j) = vec.at(i).at(j) + 1;
//             propagate(vec, i+1, j, "down", n, max_i, max_j-1, min_i, min_j);
//         } else if (dir == "down" && i < max_i) {
//             vec.at(i+1).at(j) = vec.at(i).at(j) + 1;
//             propagate(vec, i+1, j, "down", n, max_i, max_j, min_i, min_j);
//         } else if (dir == "down" && i == max_i) {
//             vec.at(i).at(j-1) = vec.at(i).at(j) + 1;
//             propagate(vec, i, j-1, "left", n, max_i-1, max_j, min_i, min_j);
//         } else if (dir == "left" && j > min_j) {
//             vec.at(i).at(j-1) = vec.at(i).at(j) + 1;
//             propagate(vec, i, j-1, "left", n, max_i, max_j, min_i, min_j);
//         } else if (dir == "left" && j == min_j) {
//             vec.at(i-1).at(j) = vec.at(i).at(j) + 1;
//             propagate(vec, i-1, j, "up", n, max_i, max_j, min_i, min_j+1);
//         } else if (dir == "up" && i > min_i) {
//             vec.at(i-1).at(j) = vec.at(i).at(j) + 1;
//             propagate(vec, i-1, j, "up", n, max_i, max_j, min_i, min_j);
//         } else if (dir == "up" && i == min_i) {
//             vec.at(i).at(j+1) = vec.at(i).at(j) + 1;
//             propagate(vec, i, j+1, "right", n, max_i, max_j, min_i+1, min_j);
//         }
//     }
// };