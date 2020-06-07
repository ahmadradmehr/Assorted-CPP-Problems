/* Add Binary
 * 
 * Given two binary strings, return their sum (also a binary string).
 * The input strings are both non-empty and contains only characters 1 or 0.
 * 
 * Example 1:
 * Input: a = "11", b = "1"
 * Output: "100"
 * 
 * Example 2:
 * Input: a = "1010", b = "1011"
 * Output: "10101"
 * 
 * Constraints:
 * Each string consists only of '0' or '1' characters.
 * 1 <= a.length, b.length <= 10^4
 * Each string is either "0" or doesn't contain any leading zero.
 */
 
class AddBinary {
public:
    string addBinary(string a, string b) {
        std::string sum_ab {""};
        int temp, ext {0}, aa {0}, bb {0};
        for (int i {1}; i <= max(a.length(), b.length()); i++) {
            if (a.length() < i && b.length() >= i) {
                aa = 0;
                bb = b[b.length()-i] - '0';
            } else if (a.length() >= i && b.length() < i) {
                aa = a[a.length()-i] - '0';
                bb = 0;
            } else if (a.length() < i && b.length() < i) {
                aa = 0;
                bb = 0;
            } else {
                aa = a[a.length()-i] - '0';
                bb = b[b.length()-i] - '0';
            }
            temp = aa + bb + ext;
            ext = 0;
            if (temp >= 2) {
                temp -= 2;
                ext = 1;
            }
            sum_ab += std::to_string(temp);
        }
        if (ext == 1) {
            sum_ab += std::to_string(ext);
        }
        std::reverse(sum_ab.begin(), sum_ab.end());
        return sum_ab;
    }
};