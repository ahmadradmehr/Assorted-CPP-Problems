/* Longest Substring Without Repeating Characters
 * 
 * Given a string, find the length of the longest substring without repeating characters.
 * 
 * Example 1:
 * 
 * Input: "abcabcbb"
 * Output: 3 
 * Explanation: The answer is "abc", with the length of 3. 
 * 
 * Example 2:
 * 
 * Input: "bbbbb"
 * Output: 1
 * Explanation: The answer is "b", with the length of 1.
 * 
 * Example 3:
 * 
 * Input: "pwwkew"
 * Output: 3
 * Explanation: The answer is "wke", with the length of 3.
 * 
 * Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
 */
 
 class LengthOfLongestSubstring {
public:
    int lengthOfLongestSubstring(string s) {
        string longest {""}, temp {""};
        int n {0};
        for (int i {0}; i < s.length(); i++) {
            for (int j {i}; j < s.length(); j++) {
                auto it = find(temp.begin(), temp.end(), s[j]);
                if (it != temp.end()) {
                    temp.clear();
                    break;
                }
                else {
                    temp += s[j];
                    if (temp.length() > longest.length()) {
                        longest = temp;
                    }
                }
            }
            if (longest.length() > s.length()-i-1)
                break;
        }
        return longest.length();
    }
};