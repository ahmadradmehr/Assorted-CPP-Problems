/* Valid Palindrome
 * 
 * Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
 * 
 * Note: For the purpose of this problem, we define empty string as valid palindrome.
 * 
 * Example 1:
 * Input: "A man, a plan, a canal: Panama"
 * Output: true
 * 
 * Example 2:
 * Input: "race a car"
 * Output: false
 * 
 * Constraints:
 * s consists only of printable ASCII characters.
 */
 
class IsPalindrome {
public:
    bool isPalindrome(string s) {
        deque<char> d;
        for (auto &c: s) {
            if (isalnum(c))
                d.push_back(tolower(c));
        }
        while (d.size() > 1) {
            if (d.front() != d.back())
                return false;
            d.pop_front();
            d.pop_back();
        }
        return true;
    }
};