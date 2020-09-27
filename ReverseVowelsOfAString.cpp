/*
 * ### Reverse Vowels of a String ###
 * 
 * 
 * Write a function that takes a string as input and reverse only the vowels of a string.
 * 
 * Example 1:
 * Input: "hello"
 * Output: "holle"
 * 
 * Example 2:
 * Input: "leetcode"
 * Output: "leotcede"
 * 
 * Note:
 * The vowels does not include the letter "y".
 */


class ReverseVowels {
public:
    string reverseVowels(string s) {
        set<char> vowels {'a', 'e', 'i', 'o', 'u'};
        int l = 0, r = s.length()-1;
        while (l < r) {
            while (l < s.length() && !vowels.count(tolower(s[l])))
                l++;
            while (r >= 0 && !vowels.count(tolower(s[r])))
                r--;
            if (l < r) {
                swap(s[l], s[r]);
                l++;
                r--;
            }
        }
        return s;
    }
};