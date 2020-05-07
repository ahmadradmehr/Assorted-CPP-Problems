/* ZigZag Conversion
 * 
 * The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this:
 * (you may want to display this pattern in a fixed font for better legibility)
 * 
 * P   A   H   N
 * A P L S I I G
 * Y   I   R
 * 
 * And then read line by line: "PAHNAPLSIIGYIR"
 * 
 * Write the code that will take a string and make this conversion given a number of rows:
 * string convert(string s, int numRows);
 * 
 * Example 1:
 * Input: s = "PAYPALISHIRING", numRows = 3
 * Output: "PAHNAPLSIIGYIR"
 * 
 * Example 2:
 * Input: s = "PAYPALISHIRING", numRows = 4
 * Output: "PINALSIGYAHRPI"
 * Explanation:
 * P     I    N
 * A   L S  I G
 * Y A   H R
 * P     I
 */
 
 class ZigZagConversion {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        vector<string> v(numRows, "");
        int n {0};
        bool down = true;
        while (!s.empty()) {
            v[n] += s[0];
            if (n < numRows-1 && down)
                n++;
            else if (n == numRows-1) {
                n--;
                down = false;
            } else if (n == 0) {
                n++;
                down = true;
            } else if (n < numRows-1 && !down)
                n--;
            s.erase(s.begin());
        }
        string ss {""};
        for (int i {0}; i < numRows; i++)
            ss += v[i];
        return ss;
    }
};