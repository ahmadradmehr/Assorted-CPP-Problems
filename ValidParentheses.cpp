/* Valid Parentheses
 * 
 * Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
 * 
 * An input string is valid if:
 * Open brackets must be closed by the same type of brackets.
 * Open brackets must be closed in the correct order.
 * Note that an empty string is also considered valid.
 * 
 * Example 1:
 * Input: "()"
 * Output: true
 * 
 * Example 2:
 * Input: "()[]{}"
 * Output: true
 * 
 * Example 3:
 * Input: "(]"
 * Output: false
 * 
 * Example 4:
 * Input: "([)]"
 * Output: false
 * 
 * Example 5:
 * Input: "{[]}"
 * Output: true
 */
 
class ValidParantheses {
public:
    bool isValid(std::string s) {
        std::stack<char> pr;
        size_t i {0};
        while (i < s.size()) {
            if (s[i] == ')' || s[i] == ']' || s[i] == '}') {
                if (pr.size() == 0)
                    return false;
                if ((pr.top() == '(' && s[i] == ')') || 
                    (pr.top() == '[' && s[i] == ']') || 
                    (pr.top() == '{' && s[i] == '}')) {
                    pr.pop();
                } else {
                    return false;
                }
            } else {
                pr.push(s[i]);
            }
            i++;
        }
        if (!pr.empty())
            return false;
        return true;
    }
};