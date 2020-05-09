/* Palindrome Number
 * 
 * Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.
 * 
 * Example 1:
 * Input: 121
 * Output: true
 * 
 * Example 2:
 * Input: -121
 * Output: false
 * Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
 * 
 * Example 3:
 * Input: 10
 * Output: false
 * Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
 * 
 * Follow up:
 * Coud you solve it without converting the integer to a string?
 */
 
 class PalindromeNumber {
public:
    bool isPalindrome(int x) {
        int rev {0};
        if (x < 0)
            return false;
        else {
            int temp {x};
            while (temp != 0) {
                if (rev <= (INT_MAX-temp%10)/10) {
                    rev = 10*rev + temp%10;
                    temp /= 10;
                } else
                    return 0;
            }
        }
        if (x == rev)
            return true;
        else
            return false;
    }
};