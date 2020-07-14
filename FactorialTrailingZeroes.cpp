/* Factorial Trailing Zeroes
 * 
 * Given an integer n, return the number of trailing zeroes in n!.
 * 
 * Example 1:
 * Input: 3
 * Output: 0
 * Explanation: 3! = 6, no trailing zero.
 * 
 * Example 2:
 * Input: 5
 * Output: 1
 * Explanation: 5! = 120, one trailing zero.
 * 
 * Note: Your solution should be in logarithmic time complexity.
 */
 
// class TrailingZeroes {
// public:
//     int trailingZeroes(int n) {
//         int num = 0;
//         n -= n % 5;
//         while (n >= 5) {
//             int temp = n;
//             while (temp >= 5) {
//                 num++;
//                 temp /= 5;
//                 if (temp % 5 != 0)
//                     break;
//             }
//             n -= 5;
//         }
//         return num;
//     }
// };

class TrailingZeroes {
public:
    int trailingZeroes(int n) {
        long num = 0, f = 5;
        while (log(n) / log(f) >= 1) {
            num += n / f;
            f *= 5;
        }
        return num;
    }
};