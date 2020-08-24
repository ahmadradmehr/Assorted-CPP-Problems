/* Word Pattern
 * 
 * Given a pattern and a string str, find if str follows the same pattern.
 * Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.
 * 
 * Example 1:
 * Input: pattern = "abba", str = "dog cat cat dog"
 * Output: true
 * 
 * Example 2:
 * Input:pattern = "abba", str = "dog cat cat fish"
 * Output: false
 * 
 * Example 3:
 * Input: pattern = "aaaa", str = "dog cat cat dog"
 * Output: false
 * 
 * Example 4:
 * Input: pattern = "abba", str = "dog dog dog dog"
 * Output: false
 * Notes:
 * You may assume pattern contains only lowercase letters, and str contains lowercase letters that may be separated by a single space.
 */
 
class WordPattern {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<char, string> m_char;
        unordered_map<string, int> m_str;
        stringstream ss {str};
        for (int i {0}; i < pattern.length(); i++) {
            if (ss.eof())
                return false;
            string temp;
            ss >> temp;
            if (m_char.count(pattern.at(i))) {
                if (temp != m_char[pattern.at(i)])
                    return false;
            } else if (m_str.count(temp)) {
                return false;
            } else if (!m_char.count(pattern.at(i))) {
                m_char[pattern.at(i)] = temp;
            }
            m_str[temp]++;
        }
        if (!ss.eof())
            return false;
        return true;
    }
};