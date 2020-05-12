/* Longest Common Prefix
 * 
 * Write a function to find the longest common prefix string amongst an array of strings.
 * 
 * If there is no common prefix, return an empty string "".
 * 
 * Example 1:
 * Input: ["flower","flow","flight"]
 * Output: "fl"
 * 
 * Example 2:
 * Input: ["dog","racecar","car"]
 * Output: ""
 * Explanation: There is no common prefix among the input strings.
 * 
 * Note:
 * All given inputs are in lowercase letters a-z.
 */
 
 class LongestCommonPrefix {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0)
            return "";
        std::string str {strs.at(0)};
        std::string longest {};
        for (size_t i {0}; i < strs.size(); i++) {
            if (strs[i].size() < str.size())
                str = strs[i];
        }
        auto it = std::find(strs.begin(), strs.end(), str);
        strs.erase(it);
        bool done {false};
        std::string temp {};
        size_t i {0};
        while (!done && i < str.size()) {
            temp += str[i];
            for (auto &s: strs) {
                auto it = s.find(temp);
                if (it != 0) {
                    done = true;
                    temp.pop_back();
                    if (temp.size() > longest.size())
                        longest = temp;
                    break;
                }
            }
            i++;
        }
        if (!done && i == str.size() && temp.size() > longest.size())
            longest = temp;
        return longest;
    }
};