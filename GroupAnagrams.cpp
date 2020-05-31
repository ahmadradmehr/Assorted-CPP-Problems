/* Group Anagrams
 * 
 * Given an array of strings, group anagrams together.
 * 
 * Example:
 * Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
 * Output:
 * [
 *   ["ate","eat","tea"],
 *   ["nat","tan"],
 *   ["bat"]
 * ]
 * 
 * Note:
 * All inputs will be in lowercase.
 * The order of your output does not matter.
 */
 
class GroupAnagrams {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> vec;
        map<string, vector<string>> m;
        for (int i {0}; i < strs.size(); i++) {
            string s = strs.at(i);
            sort(s.begin(), s.end());
            bool found = false;
            for (auto &mm: m) {
                if (s == mm.first) {
                    mm.second.push_back(strs.at(i));
                    found = true;
                }
            }
            if (!found) {
                m[s].push_back(strs.at(i));
            }
        }
        for (auto &mm: m) {
            vec.push_back(mm.second);
        }
        return vec;
    }
};