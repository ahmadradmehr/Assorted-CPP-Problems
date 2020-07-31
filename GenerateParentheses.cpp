/* Generate Parentheses
 * 
 * Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
 * 
 * For example, given n = 3, a solution set is:
 * [
 *   "((()))",
 *   "(()())",
 *   "(())()",
 *   "()(())",
 *   "()()()"
 * ]
 */
 
class GenerateParentheses {
public:
    vector<string> generateParenthesis(int n) {
        int n_left = n, n_right = n;
        vector<string> vec;
        addPar(vec, "", n_left, n_right);
        return vec;
    }
    void addPar(vector<string> &vec, string par, int n_left, int n_right) {
        if (!n_left && !n_right)
            vec.push_back(par);
        if (n_left < n_right)
            addPar(vec, par + ')', n_left, n_right-1);
        if (n_left)
            addPar(vec, par + '(', n_left-1, n_right);
    }
};