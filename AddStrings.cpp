/*
 * ### Add Strings ###
 * 
 * 
 * Given two non-negative integers num1 and num2 represented as string, return the sum of num1 and num2.
 * 
 * Note:
 * The length of both num1 and num2 is < 5100.
 * Both num1 and num2 contains only digits 0-9.
 * Both num1 and num2 does not contain any leading zero.
 * You must not use any built-in BigInteger library or convert the inputs to integer directly.
 */


class AddStrings {
public:
    string addStrings(string num1, string num2) {
        string sum;
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        int i = 0, ext = 0;
        while (i < num1.length() || i < num2.length() || ext) {
            int temp {0};
            if (i < num1.length() && i < num2.length()) {
                temp = ext + num1.at(i) + num2.at(i) - 2 * '0';
            } else if (i < num1.length()) {
                temp = ext + num1.at(i) - '0';
            } else if (i < num2.length()) {
                temp = ext + num2.at(i) - '0';
            } else {
                temp = ext;
            }
            sum += to_string(temp % 10);
            ext = temp / 10;
            i++;
        }
        reverse(sum.begin(), sum.end());
        return sum;
    }
};