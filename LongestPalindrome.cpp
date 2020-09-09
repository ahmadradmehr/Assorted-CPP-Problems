/* Longest Palindrome
 * 
 * Given a string s which consists of lowercase or uppercase letters, return the length of the longest palindrome that can be built with those letters.
 * Letters are case sensitive, for example, "Aa" is not considered a palindrome here.
 * 
 * Example 1:
 * Input: s = "abccccdd"
 * Output: 7
 * Explanation:
 * One longest palindrome that can be built is "dccaccd", whose length is 7.
 * 
 * Example 2:
 * Input: s = "a"
 * Output: 1
 * 
 * Example 3:
 * Input: s = "bb"
 * Output: 2
 * 
 * Constraints:
 * 1 <= s.length <= 2000
 * s consits of lower-case and/or upper-case English letters only.
 */

class LongestPalindrome {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> m;
        int len {0}, max_odd {0};
        for (auto &c: s)
            m[c]++;
        for (auto &mm: m) {
            if (mm.second % 2 == 0)
                len += mm.second;
            else if (mm.second > max_odd) {
                if (max_odd == 0)
                    len += max_odd;
                else
                    len += max_odd - 1;
                max_odd = mm.second;
            } else {
                len += mm.second - 1;
            }
        }
        return len + max_odd;
    }
};