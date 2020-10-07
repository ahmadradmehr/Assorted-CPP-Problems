/*
 * ### Sort Characters By Frequency ###
 * 
 * 
 * Given a string, sort it in decreasing order based on the frequency of characters.
 * 
 * Example 1:
 * Input:
 * "tree"
 * Output:
 * "eert"
 * Explanation:
 * 'e' appears twice while 'r' and 't' both appear once.
 * So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
 * 
 * Example 2:
 * Input:
 * "cccaaa"
 * Output:
 * "cccaaa"
 * Explanation:
 * Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
 * Note that "cacaca" is incorrect, as the same characters must be together.
 * 
 * Example 3:
 * Input:
 * "Aabb"
 * Output:
 * "bbAa"
 * Explanation:
 * "bbaA" is also a valid answer, but "Aabb" is incorrect.
 * Note that 'A' and 'a' are treated as two different characters.
 */


class SortCharactersByFrequency {
public:
    string frequencySort(string s) {
        unordered_map<char, int> m;
        for (auto &c: s) {
            m[c]++;
        }
        vector<pair<int, char>> vec;
        for (auto &mm: m) {
            vec.push_back({mm.second, mm.first});
        }
        sort(vec.rbegin(), vec.rend());
        string ss;
        for (int i {0}; i < vec.size(); i++) {
            string temp (vec.at(i).first, vec.at(i).second);
            ss += temp;
        }
        return ss;
    }
};