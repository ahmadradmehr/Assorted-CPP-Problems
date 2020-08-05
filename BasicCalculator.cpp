/* Basic Calculator
 * 
 * Implement a basic calculator to evaluate a simple expression string.
 * The expression string may contain open ( and closing parentheses ), the plus + or minus sign -, non-negative integers and empty spaces .
 * 
 * Example 1:
 * Input: "1 + 1"
 * Output: 2
 * 
 * Example 2:
 * Input: " 2-1 + 2 "
 * Output: 3
 * 
 * Example 3:
 * Input: "(1+(4+5+2)-3)+(6+8)"
 * Output: 23
 * 
 * Note:
 * You may assume that the given expression is always valid.
 * Do not use the eval built-in library function.
 */
 
class BasicCalculator {
public:
    int calculate(string s) {
        int res {0};
        stack<string> st;
        for (int i {0}; i < s.length(); i++) {
            if (s.at(i) == '(')
                st.push("(");
            else if (s.at(i) == '+' || s.at(i) == ' ')
                continue;
            else if (s.at(i) == ')') {
                int val {0};
                while (st.top() != "(") {
                    val += std::stoi(st.top());
                    st.pop();
                }
                st.pop();
                if (!st.empty() && st.top() == "-") {
                    st.pop();
                    st.push(to_string(-val));
                } else {
                    st.push(to_string(val));
                }
            } else if (s.at(i) == '-') {
                string ss {"-"};
                while (i < s.length()-1 && s.at(i+1) != '(' && s.at(i+1) != '+' &&
                       s.at(i+1) != '-' && s.at(i+1) != ')' && s.at(i+1) != ' ') {
                    ss += s.at(i+1);
                    i++;
                }
                st.push(ss);
            } else {
                string ss {""};
                ss += s.at(i);
                while (i < s.length()-1 && s.at(i+1) != '(' && s.at(i+1) != '+' &&
                       s.at(i+1) != '-' && s.at(i+1) != ')' && s.at(i+1) != ' ') {
                    ss += s.at(i+1);
                    i++;
                }
                st.push(ss);
            }
        }
        while (!st.empty()) {
            res += std::stoi(st.top());
            st.pop();
        }
        return res;
    }
};