/* Power of Four
 * 
 * Given an integer (signed 32 bits), write a function to check whether it is a power of 4.
 * 
 * Example 1:
 * Input: 16
 * Output: true
 * 
 * Example 2:
 * Input: 5
 * Output: false
 * Follow up: Could you solve it without loops/recursion?
 */
 
class PowerOfFour {
public:
    bool isPowerOfFour(int num) {
        if (num <= 0 || (num-1) % 3 != 0)
            return false;
        int x = num & (num-1);
        if (x > 0)
            return false;
        return true;
    }
};
