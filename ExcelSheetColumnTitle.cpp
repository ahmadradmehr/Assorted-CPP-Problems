/* Excel Sheet Column Title
 * 
 * Given a positive integer, return its corresponding column title as appear in an Excel sheet.
 * 
 * For example:
 * 1 -> A
 * 2 -> B
 * 3 -> C
 *  ...
 * 26 -> Z
 * 27 -> AA
 * 28 -> AB 
 *  ...
 * 
 * Example 1:
 * Input: 1
 * Output: "A"
 * 
 * Example 2:
 * Input: 28
 * Output: "AB"
 * 
 * Example 3:
 * Input: 701
 * Output: "ZY"
 */
 
class ConvertToTitle {
public:
    string convertToTitle(int n) {
        string res;
        while (n > 0) {
            if (n % 26 == 0) {
                res.insert(res.begin(), 'Z');
                n -= 26;
            } else
                res.insert(res.begin(), n % 26 + 'A' - 1);
            n /= 26;
        }
        return res;
    }
};