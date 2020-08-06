/* Basic Calculator II
 * 
 * Implement a basic calculator to evaluate a simple expression string.
 * The expression string contains only non-negative integers, +, -, *, / operators and empty spaces.
 * The integer division should truncate toward zero.
 * 
 * Example 1:
 * Input: "3+2*2"
 * Output: 7
 * 
 * Example 2:
 * Input: " 3/2 "
 * Output: 1
 * 
 * Example 3:
 * Input: " 3+5 / 2 "
 * Output: 5
 * 
 * Note:
 * You may assume that the given expression is always valid.
 * Do not use the eval built-in library function.
 */
 
class BasicCalculator_II {
public:
    int calculate(string s) {
        int res {0};
        stack <string> st;
        for (int i {0}; i < s.length(); i++) {
            if (s.at(i) == '*' || s.at(i) == '/') {
                char c = s.at(i);
                int val {0};
                string ss {""};
                while (i < s.length()-1 && s.at(i+1) == ' ') {
                    i++;
                }
                while (i < s.length()-1 && s.at(i+1) != '+' && s.at(i+1) != '-' &&
                      s.at(i+1) != '*' && s.at(i+1) != '/' && s.at(i+1) != ' ') {
                    ss += s.at(i+1);
                    i++;
                }
                val = stoi(ss);
                int tp = stoi(st.top());
                st.pop();
                if (c == '*') {
                    tp *= val;
                } else if (c == '/') {
                    tp /= val;
                }
                st.push(to_string(tp));
            } else if (s.at(i) == ' ')
                continue;
            else if (s.at(i) == '-') {
                st.push("-");
            } else if (s.at(i) == '+')
                st.push("+");
            else {
                string ss = {""};
                ss += s.at(i);
                while (i < s.length()-1 && s.at(i+1) != '+' && s.at(i+1) != '-' &&
                      s.at(i+1) != '*' && s.at(i+1) != '/' && s.at(i+1) != ' ') {
                    ss += s.at(i+1);
                    i++;
                }
                st.push(ss);
            }
        }
        while (!st.empty()) {
            int val = stoi(st.top());
            st.pop();
            string ss;
            if (!st.empty()) {
                ss = st.top();
                st.pop();
            }
            if (st.empty() || ss == "+")
                res += val;
            else if (ss == "-")
                res -= val;
        }
        return res;
    }
};