/* Bitwise AND of Numbers Range
 * 
 * Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND of all numbers in this range, inclusive.
 * 
 * Example 1:
 * Input: [5,7]
 * Output: 4
 * 
 * Example 2:
 * Input: [0,1]
 * Output: 0
 */
 
class RangeBitwiseAnd {
public:
    int rangeBitwiseAnd(int m, int n) {
        long t {m}, power1, power2;
        m == 0 ? power1 = 0 : power1 = log2(m);
        n == 0 ? power2 = 0 : power2 = log2(n);
        if (power2 > power1 || m == 0 && n == 0)
            return 0;
        for (int i {m}; i <= n; i++) {
            t = t & i;
            if (i == INT_MAX)
                break;
        }
        return t;
    }
};