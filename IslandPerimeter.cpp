/*
 * ### Island Perimeter ###
 * 
 * 
 * You are given row x col grid representing a map where grid[i][j] = 1 represents land and grid[i][j] = 0 represents water.
 * Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells).
 * The island doesn't have "lakes", meaning the water inside isn't connected to the water around the island. One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.
 * 
 * Example 1:
 * Input: grid = [[0,1,0,0],[1,1,1,0],[0,1,0,0],[1,1,0,0]]
 * Output: 16
 * Explanation: The perimeter is the 16 yellow stripes in the image above.
 * 
 * Example 2:
 * Input: grid = [[1]]
 * Output: 4
 * 
 * Example 3:
 * Input: grid = [[1,0]]
 * Output: 4
 * 
 * Constraints:
 * row == grid.length
 * col == grid[i].length
 * 1 <= row, col <= 100
 * grid[i][j] is 0 or 1.
 */


class IslandPerimeter {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        if (grid.empty() || grid.at(0).empty())
            return 0;
        int perimeter {0};
        set<pair<int, int>> memory;
        for (int i {0}; i < grid.size(); i++) {
            for (int j {0}; j < grid.at(0).size(); j++) {
                if (grid.at(i).at(j) == 1) {
                    perimeter = islands(grid, i, j, perimeter, memory);
                    break;
                }
            }
            if (perimeter != 0)
                break;
        }
        return perimeter;
    }
    
    int islands(vector<vector<int>> &grid, int i, int j, int &perimeter, set<pair<int, int>> &memory) {
        memory.insert({i, j});
        if (i == 0 || grid.at(i-1).at(j) == 0)
            perimeter++;
        else if (memory.count({i-1, j}) == 0)
            perimeter = islands(grid, i-1, j, perimeter, memory);
        if (j == 0 || grid.at(i).at(j-1) == 0)
            perimeter++;
        else if (memory.count({i, j-1}) == 0)
            perimeter = islands(grid, i, j-1, perimeter, memory);
        if (i == grid.size()-1 || grid.at(i+1).at(j) == 0)
            perimeter++;
        else if (memory.count({i+1, j}) == 0)
            perimeter = islands(grid, i+1, j, perimeter, memory);
        if (j == grid.at(0).size()-1 || grid.at(i).at(j+1) == 0)
            perimeter++;
        else if (memory.count({i, j+1}) == 0)
            perimeter = islands(grid, i, j+1, perimeter, memory);
        return perimeter;
    }
};