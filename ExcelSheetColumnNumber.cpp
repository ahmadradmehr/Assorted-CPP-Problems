/* Excel Sheet Column Number
 * 
 * Given a column title as appear in an Excel sheet, return its corresponding column number.
 * 
 * For example:
 * A -> 1
 * B -> 2
 * C -> 3
 *  ...
 * Z -> 26
 * AA -> 27
 * AB -> 28 
 *  ...
 * 
 * Example 1:
 * Input: "A"
 * Output: 1
 * 
 * Example 2:
 * Input: "AB"
 * Output: 28
 * 
 * Example 3:
 * Input: "ZY"
 * Output: 701
 * 
 * Constraints:
 * 1 <= s.length <= 7
 * s consists only of uppercase English letters.
 * s is between "A" and "FXSHRXW".
 */
 
class TitleToNumber {
public:
    int titleToNumber(string s) {
        int i = s.length()-1, power = 0, num = 0;
        while (i >= 0) {
            num += (s.at(i) - 'A' + 1) * pow(26, power);
            i--;
            power++;
        }
        return num;
    }
};