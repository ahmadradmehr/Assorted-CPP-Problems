/* 3Sum
 * 
 * Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0?
 * Find all unique triplets in the array which gives the sum of zero.
 * 
 * Note:
 * The solution set must not contain duplicate triplets.
 * 
 * Example:
 * Given array nums = [-1, 0, 1, 2, -1, -4],
 * A solution set is
 * [
 *  [-1, 0, 1],
 *  [-1, -1, 2]
 * ]
 */
 
 class ThreeSum {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> vec;
        sort(nums.begin(), nums.end());
        if (nums.size() < 3)
            return {};
        for (int i {0}; i < nums.size()-2; i++) {
            int target = -nums.at(i);
            int front = i + 1;
            int back = nums.size() - 1;
            while (front < back) {
                int res = nums.at(front) + nums.at(back);
                if (res < target) {
                    front++;
                } else if (res > target) {
                    back--;
                } else {
                    vec.push_back(vector<int> {nums.at(i), nums.at(front), nums.at(back)});
                    int j = front;
                    while (nums.at(front) == nums.at(j) && front < back) {
                        front++;
                    }
                    j = back;
                    while (nums.at(back) == nums.at(j) && front < back) {
                        back--;
                    }
                }
            }
            while (i < nums.size()-1 && nums.at(i) == nums.at(i+1))
                i++;
        }
        return vec;
    }
};