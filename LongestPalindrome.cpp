/* Longest Palindromic Substring
 * 
 * Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.
 * 
 * Example 1:
 * Input: "babad"
 * Output: "bab"
 * Note: "aba" is also a valid answer.
 * 
 * Example 2:
 * Input: "cbbd"
 * Output: "bb"
 */
 
class LongestPalindrome {
public:
    string longestPalindrome(string s) {
        string longest {""}, temp {""};
        bool found = false;
        for (int i {0}; i < s.length(); i++) {
            temp.clear();
            for (int j {i}; j < s.length(); j++) {
                temp += s[j];
                found = false;
                for (int k {0}; k < temp.length()/2; k++) {
                    if (temp[k] != temp[temp.length() - k - 1]) {
                        found = true;
                        break;
                    }
                }
                if (!found && temp.length() > longest.length()) {
                    longest = temp;
                }
            }
            if (longest.length() >= s.length()-i-1)
                break;
        }
        return longest;
    }
};