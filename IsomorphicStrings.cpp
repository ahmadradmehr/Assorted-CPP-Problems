/* Isomorphic Strings
 * 
 * Given two strings s and t, determine if they are isomorphic.
 * Two strings are isomorphic if the characters in s can be replaced to get t.
 * All occurrences of a character must be replaced with another character while preserving the order of characters.
 * No two characters may map to the same character but a character may map to itself.
 * 
 * Example 1:
 * Input: s = "egg", t = "add"
 * Output: true
 * 
 * Example 2:
 * Input: s = "foo", t = "bar"
 * Output: false
 * 
 * Example 3:
 * Input: s = "paper", t = "title"
 * Output: true
 * 
 * Note:
 * You may assume both s and t have the same length.
 */
 
class IsomorphicStrings {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length())
            return false;
        unordered_map<char, char> m;
        unordered_map<char, int> m_unique;
        for (int i {0}; i < s.length(); i++) {
            if (m.count(s.at(i)) && t.at(i) != m[s.at(i)] ||
               !m.count(s.at(i)) && m_unique.count(t.at(i)))
                return false;
            else {
                m[s.at(i)] = t.at(i);
                m_unique[t.at(i)]++;
            }
        }
        return true;
    }
};