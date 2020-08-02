/* Pow(x, n)
 * 
 * Implement pow(x, n), which calculates x raised to the power n (xn).
 * 
 * Example 1:
 * Input: 2.00000, 10
 * Output: 1024.00000
 * 
 * Example 2:
 * Input: 2.10000, 3
 * Output: 9.26100
 * 
 * Example 3:
 * Input: 2.00000, -2
 * Output: 0.25000
 * Explanation: 2-2 = 1/22 = 1/4 = 0.25
 * 
 * Note:
 * -100.0 < x < 100.0
 * n is a 32-bit signed integer, within the range [−2^31, 2^31 − 1]
 */
 
class MyPow {
public:
    double myPow(double x, int n) {
        if (n == 0 || x == 1 || x == -1 && n % 2 == 0)
            return 1;
        else if (x == -1 && n % 2 == 1)
            return -1;
        if (n == INT_MIN)
            return myPow(1/x, INT_MAX) * (1/x);
        else if (n < 0)
            return myPow(1/x, -n);
        double res = myPow(x, n/2);
        return n%2 ? x * res * res : res * res;
    }
};