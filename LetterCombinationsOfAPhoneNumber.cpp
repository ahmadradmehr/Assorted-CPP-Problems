/* Letter Combinations of a Phone Number
 * 
 * Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.
 * A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.
 * 
 * Example:
 * Input: "23"
 * Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 * 
 * Note:
 * Although the above answer is in lexicographical order, your answer could be in any order you want.
 */
 
class LetterCombinations {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty())
            return vector<string> {};
        vector<string> vec;
        vector<int> v(digits.length(), 0);
        map<int, string> m {{2, "abc"},
                            {3, "def"},
                            {4, "ghi"},
                            {5, "jkl"},
                            {6, "mno"},
                            {7, "pqrs"},
                            {8, "tuv"},
                            {9, "wxyz"}};
        while (true) {
            string s {""};
            for (int i {0}; i < digits.length(); i++) {
                s += m[digits.at(i)-48].at(v.at(i));
            }
            vec.push_back(s);
            int j = v.size()-1;
            v.at(j)++;
            while (v.at(j) > m[digits.at(j)-48].length()-1) {
                v.at(j) = 0;
                j--;
                if (j < 0)
                    break;
                v.at(j)++;
            }
            if (j < 0)
                break;
        }
        return vec;
    }
};