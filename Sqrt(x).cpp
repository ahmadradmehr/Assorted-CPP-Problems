/* Sqrt(x)
 * 
 * Implement int sqrt(int x).
 * Compute and return the square root of x, where x is guaranteed to be a non-negative integer.
 * Since the return type is an integer, the decimal digits are truncated and only the integer part of the result is returned.
 * 
 * Example 1:
 * Input: 4
 * Output: 2
 * 
 * Example 2:
 * Input: 8
 * Output: 2
 * Explanation: The square root of 8 is 2.82842..., and since 
 *              the decimal part is truncated, 2 is returned.
 */
 
class MySqrt {
public:
    int mySqrt(int x) {
        int a {0}, b {x}, d {b-a};
        while (d > 1) {
            std::pow((a+b)/2,2) >= x ? b=(a+b)/2 : a=(a+b)/2;
            d = b - a;
        }
        if (pow(b,2) > x)
            return a;
        else
            return b;
    }
};