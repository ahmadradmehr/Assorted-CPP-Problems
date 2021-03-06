/*
 * ### Number of Boomerangs ###
 * 
 * 
 * Given n points in the plane that are all pairwise distinct, a "boomerang" is a tuple of points (i, j, k) such that the distance between i and j equals the distance between i and k (the order of the tuple matters).
 * Find the number of boomerangs. You may assume that n will be at most 500 and coordinates of points are all in the range [-10000, 10000] (inclusive).
 * 
 * Example:
 * Input:
 * [[0,0],[1,0],[2,0]]
 * Output:
 * 2
 * Explanation:
 * The two boomerangs are [[1,0],[0,0],[2,0]] and [[1,0],[2,0],[0,0]]
 */


class NumberOfBoomerangs {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int num {0};
        for (int i {0}; i < points.size(); i++) {
            unordered_map<int, int> m_dis;
            for (int j {0}; j < points.size(); j++) {
                int dis = pow(points[j][1] - points[i][1], 2) + pow(points[j][0] - points[i][0], 2);
                m_dis[dis]++;
            }
            for (auto &[key, value]: m_dis) {
                num += value * (value - 1);
            }
        }
        return num;
    }
};