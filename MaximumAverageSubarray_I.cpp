/*
 * ### Maximum Average Subarray I ###
 * 
 * 
 * Given an array consisting of n integers, find the contiguous subarray of given length k that has the maximum average value. And you need to output the maximum average value.
 * 
 * Example 1:
 * Input: [1,12,-5,-6,50,3], k = 4
 * Output: 12.75
 * Explanation: Maximum average is (12-5-6+50)/4 = 51/4 = 12.75
 * 
 * Note:
 * 1 <= k <= n <= 30,000.
 * Elements of the given array will be in the range [-10,000, 10,000].
 */
 
 
class MaximumAverageSubarray_I {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum {0}, max_ave {0};
        for (int i {0}; i < nums.size(); i++) {
            sum += nums.at(i);
            if (i == k - 1)
                max_ave = sum / k;
            else if (i > k - 1) {
                sum -= nums.at(i-k);
                if (sum / k > max_ave)
                    max_ave = sum / k;
            }
        }
        return max_ave;
    }
};