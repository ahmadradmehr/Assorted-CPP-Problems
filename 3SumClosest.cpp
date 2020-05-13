/* 3Sum Closest
 * 
 * Given an array nums of n integers and an integer target, find three integers in nums such that the sum is closest to target.
 * Return the sum of the three integers. You may assume that each input would have exactly one solution.
 * 
 * Example:
 * Given array nums = [-1, 2, 1, -4], and target = 1.
 * The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 */
 
class ThreeSumClosest {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int closest = nums.at(0) + nums.at(1) + nums.at(2);
        for (int i {0}; i < nums.size()-2; i++) {
            int second = i+1, third = nums.size()-1;
            while (second < third) {
                int temp = nums.at(i) + nums.at(second) + nums.at(third);
                if (abs(temp - target) < abs(closest - target))
                    closest = temp;
                if (temp < target) {
                    second++;
                } else if (temp > target)
                    third--;
                else
                    break;
            }
        }
        return closest;
    }
};