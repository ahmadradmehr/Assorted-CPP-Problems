/*
 * ### Find All Anagrams in a String ###
 * 
 * 
 * Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.
 * Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.
 * The order of output does not matter.
 * 
 * Example 1:
 * Input:
 * s: "cbaebabacd" p: "abc"
 * Output:
 * [0, 6]
 * Explanation:
 * The substring with start index = 0 is "cba", which is an anagram of "abc".
 * The substring with start index = 6 is "bac", which is an anagram of "abc".
 * 
 * Example 2:
 * Input:
 * s: "abab" p: "ab"
 * Output:
 * [0, 1, 2]
 * Explanation:
 * The substring with start index = 0 is "ab", which is an anagram of "ab".
 * The substring with start index = 1 is "ba", which is an anagram of "ab".
 * The substring with start index = 2 is "ab", which is an anagram of "ab".
 */


class FindAllAnagrams {
public:
    vector<int> findAnagrams(string s, string p) {
        if (p.length() > s.length())
            return {};
        vector<int> res;
        unordered_map<char, int> t;
        for (auto &c: p)
            t[c]++;
        int l = 0, r = 0;
        while (l <= s.length() - p.length()) {
            if (!t.count(s[r])) {
                while (l < r) {
                    t[s[l]]++;
                    l++;
                }
                r++;
                l = r;
            } else if (!t[s[r]]) {
                t[s[l]]++;
                l++;
            } else {
                t[s[r]]--;
                r++;
            }
            if (r - l == p.length()) {
                res.push_back(l);
                t[s[l]]++;
                l++;
            }
        }
        return res;
    }
};