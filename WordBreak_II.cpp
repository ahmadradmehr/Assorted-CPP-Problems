/* Word Break II
 * 
 * Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, add spaces in s to construct a sentence where each word is a valid dictionary word. Return all such possible sentences.
 * 
 * Note:
 * The same word in the dictionary may be reused multiple times in the segmentation.
 * You may assume the dictionary does not contain duplicate words.
 * 
 * Example 1:
 * Input:
 * s = "catsanddog"
 * wordDict = ["cat", "cats", "and", "sand", "dog"]
 * Output:
 * [
 *   "cats and dog",
 *   "cat sand dog"
 * ]
 * 
 * Example 2:
 * Input:
 * s = "pineapplepenapple"
 * wordDict = ["apple", "pen", "applepen", "pine", "pineapple"]
 * Output:
 * [
 *   "pine apple pen apple",
 *   "pineapple pen apple",
 *   "pine applepen apple"
 * ]
 * Explanation: Note that you are allowed to reuse a dictionary word.
 * 
 * Example 3:
 * Input:
 * s = "catsandog"
 * wordDict = ["cats", "dog", "sand", "and", "cat"]
 * Output:
 * []
 */
 
class WordBreak_II {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> vec;
        unordered_set<string> dictionary (wordDict.begin(), wordDict.end());
        unordered_set<char> initials, s_char (s.begin(), s.end()), dictionary_char;
        for (auto &ss: dictionary) {
            initials.insert(ss.front());
            dictionary_char.insert(ss.begin(), ss.end());
        }
        for (auto &c: s_char) {
            if (!dictionary_char.count(c))
                return {};
        }
        createString(s, dictionary, initials, vec, "", 0);
        return vec;
    }
    
    void createString(string &s, unordered_set<string> &dictionary, unordered_set<char> &initials, vector<string> &vec, string list, int ind) {
        if (ind == s.length()) {
            list.pop_back();
            vec.push_back(list);
            return;
        }
        if (!initials.count(s.at(ind)))
            return;
        string word = "";
        for (int i {ind}; i < s.length(); i++) {
            word += s.at(i);
            if (dictionary.count(word)) {
                createString(s, dictionary, initials, vec, list + word + " ", i+1);
            }
        }
        if (!word.empty())
            return;
    }
};