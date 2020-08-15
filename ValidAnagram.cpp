/* Valid Anagram
 * 
 * Given two strings s and t , write a function to determine if t is an anagram of s.
 * Example 1:
 * Input: s = "anagram", t = "nagaram"
 * Output: true
 * 
 * Example 2:
 * Input: s = "rat", t = "car"
 * Output: false
 * 
 * Note:
 * You may assume the string contains only lowercase alphabets.
 * 
 * Follow up:
 * What if the inputs contain unicode characters? How would you adapt your solution to such case?
 */
 
class ValidAnagram {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length())
            return false;
        unordered_map<char, int> m;
        for (auto &c: s)
            m[c]++;
        for (int i {0}; i < t.length(); i++) {
            if (m[t.at(i)] == 0)
                return false;
            m[t.at(i)]--;
        }
        return true;
    }
};