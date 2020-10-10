/*
 * ### Repeated Substring Pattern ###
 * 
 * 
 * Given a non-empty string check if it can be constructed by taking a substring of it and appending multiple copies of the substring together.
 * You may assume the given string consists of lowercase English letters only and its length will not exceed 10000.
 * 
 * Example 1:
 * Input: "abab"
 * Output: True
 * Explanation: It's the substring "ab" twice.
 * 
 * Example 2:
 * Input: "aba"
 * Output: False
 * 
 * Example 3:
 * Input: "abcabcabcabc"
 * Output: True
 * Explanation: It's the substring "abc" four times. (And the substring "abcabc" twice.)
 */


class RepeatedSubstringPattern {
public:
    bool repeatedSubstringPattern(string s) {
        for (int i {2}; i <= s.length(); i++) {
            if (s.length() % i)
                continue;
            int l = s.length() / i;
            bool found = true;
            string ss = s.substr(0, l);
            for (int j {l}; j < s.length(); j++) {
                if (s.at(j) != ss.at(j % l)) {
                    found = false;
                    break;
                }
            }
            if (found)
                return true;
        }
        return false;
    }
};