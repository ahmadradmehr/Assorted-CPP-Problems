/* Number of Islands
 * 
 * Given a 2d grid map of '1's (land) and '0's (water), count the number of islands.
 * An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically.
 * You may assume all four edges of the grid are all surrounded by water.
 * 
 * Example 1:
 * Input: grid = [
 *   ["1","1","1","1","0"],
 *   ["1","1","0","1","0"],
 *   ["1","1","0","0","0"],
 *   ["0","0","0","0","0"]
 * ]
 * Output: 1
 * 
 * Example 2:
 * Input: grid = [
 *   ["1","1","0","0","0"],
 *   ["1","1","0","0","0"],
 *   ["0","0","1","0","0"],
 *   ["0","0","0","1","1"]
 * ]
 * Output: 3
 */
 
class NumIslands {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty())
            return 0;
        int num {0}, m = grid.size(), n = grid.at(0).size();
        for (int i {0}; i < m; i++) {
            for (int j {0}; j < n; j++) {
                if (grid.at(i).at(j) == '1') {
                    num++;
                    makezero(grid, i, j);
                }
            }
        }
        return num;
    }
private:
    void makezero(vector<vector<char>> &grid, int i, int j) {
        if (i == grid.size() || i < 0 || j == grid.at(0).size() || j < 0 || grid.at(i).at(j) == '0') {
            return;
        }
        grid.at(i).at(j) = '0';
        makezero(grid, i-1, j);
        makezero(grid, i, j-1);
        makezero(grid, i+1, j);
        makezero(grid, i, j+1);
    }
};

// class NumIslands {
// public:
//     int numIslands(vector<vector<char>>& grid) {
//         if (grid.empty())
//             return 0;
//         int num {0}, m = grid.size(), n = grid.at(0).size();
//         for (int i {0}; i < m; i++) {
//             for (int j {0}; j < n; j++) {
//                 if (grid.at(i).at(j) == '1') {
//                     num++;
//                     queue<pair<int, int>> q;
//                     q.push(make_pair(i, j));
//                     while (!q.empty()) {
//                         pair<int, int> p = q.front();
//                         q.pop();
//                         grid.at(p.first).at(p.second) = '0';
//                         if (p.first - 1 >= 0 && grid.at(p.first-1).at(p.second) == '1')
//                             q.push(make_pair(p.first-1, p.second));
//                         if (p.first + 1 < m && grid.at(p.first+1).at(p.second) == '1')
//                             q.push(make_pair(p.first+1, p.second));
//                         if (p.second - 1 >= 0 && grid.at(p.first).at(p.second-1) == '1')
//                             q.push(make_pair(p.first, p.second-1));
//                         if (p.second + 1 < n && grid.at(p.first).at(p.second+1) == '1')
//                             q.push(make_pair(p.first, p.second+1));
//                     }
//                 }
//             }
//         }
//         return num;
//     }
// };