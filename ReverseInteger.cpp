/* Reverse Integer
 * 
 * Given a 32-bit signed integer, reverse digits of an integer.
 * 
 * Example 1:
 * Input: 123
 * Output: 321
 * 
 * Example 2:
 * Input: -123
 * Output: -321
 * 
 * Example 3:
 * Input: 120
 * Output: 21
 * 
 * Note:
 * Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1].
 * For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
 */

class ReverseInteger {
public:
    int reverse(int x) {
        int num {0};
        while (x != 0) {
            if (x > 0 && INT_MAX/10 < num || x < 0 && INT_MIN/10 > num)
                return 0;
            num = num * 10 + x % 10;
            x /= 10;
        }
        return num;
    }
};

//class ReverseInteger {
//public:
//    int reverse(int x) {
//        long rev {0};
//        long maxLimit = pow(2, 31)-1;
//        long minLimit = -pow(2, 31);
//        while (x != 0) {
//            if (rev * 10 + x % 10 <= maxLimit && 
//                rev * 10 + x %10 >= minLimit) {
//                rev = rev * 10 + x % 10;
//                x /= 10;
//            } else
//                return 0;
//        }
//        return rev;
//    }
//};