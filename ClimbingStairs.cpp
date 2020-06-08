/* Climbing Stairs
 * 
 * You are climbing a stair case. It takes n steps to reach to the top.
 * Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
 * 
 * Note: Given n will be a positive integer.
 * 
 * Example 1:
 * Input: 2
 * Output: 2
 * Explanation: There are two ways to climb to the top.
 * 1. 1 step + 1 step
 * 2. 2 steps
 * 
 * Example 2:
 * Input: 3
 * Output: 3
 * Explanation: There are three ways to climb to the top.
 * 1. 1 step + 1 step + 1 step
 * 2. 1 step + 2 steps
 * 3. 2 steps + 1 step
 */
 
class ClimbStairs {
public:
    int climbStairs(int n) {
        int i {1}, sum {1};
        while (n >= 2*i) {
            double temp {1.0};
            int f {1};
            for (int j {i}; j < 2*i; j++) {
                temp *= static_cast<double>(n-j)/f;
                f++;
            }
            sum += temp;
            i++;
        }
        return sum;
    }
};