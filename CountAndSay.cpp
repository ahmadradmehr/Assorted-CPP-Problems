/* Count and Say
 * 
 * The count-and-say sequence is the sequence of integers with the first five terms as following:
 * 1.     1
 * 2.     11
 * 3.     21
 * 4.     1211
 * 5.     111221
 * 
 * 1 is read off as "one 1" or 11.
 * 11 is read off as "two 1s" or 21.
 * 21 is read off as "one 2, then one 1" or 1211.
 * 
 * Given an integer n where 1 ≤ n ≤ 30, generate the nth term of the count-and-say sequence.
 * You can do so recursively, in other words from the previous member read off the digits, counting the number of digits in groups of the same digit.
 * 
 * Note: Each term of the sequence of integers will be represented as a string.
 * 
 * Example 1:
 * Input: 1
 * Output: "1"
 * Explanation: This is the base case.
 * 
 * Example 2:
 * Input: 4
 * Output: "1211"
 * Explanation: For n = 3 the term was "21" in which we have two groups "2" and "1", "2" can be read as "12" which means frequency = 1 and value = 2, the same way "1" is read as "11", so the answer is the concatenation of "12" and "11" which is "1211".
 */
 
 // class CountAndSay {
// public:
//     string countAndSay(int n) {
//         static bool reached = false;
//         std::string say {""};
//         std::string m {""};
//         if (n == 1 && !reached) {
//             reached = true;
//             return "1";
//         } else if (n != 1 && !reached) {
//             m = countAndSay(n-1);
//         }
//         if (reached) {
//             for (size_t i {0}; i < m.size(); i++) {
//                 int count {0};
//                 for (size_t j {i}; j < m.size(); j++) {
//                     if (m[i] == m[j]) {
//                         count++;
//                     } else {
//                         break;
//                     }
//                     i = j;
//                 }
//                 say += to_string(count) + m[i];
//             }
//         }
//         return say;
//     }
// };

class CountAndSay {
public:
    string countAndSay(int n) {
        int m {1};
        std::string say {"1"};
        while (m < n) {
            std::string temp = say;
            say = "";
            for (size_t i {0}; i < temp.size(); i++) {
                int count {0};
                for (size_t j {i}; j < temp.size(); j++) {
                    if (temp[i] == temp[j]) {
                        count ++;
                    } else {
                        break;
                    }
                    i = j;
                }
                say += std::to_string(count) + temp[i];
            }
            m++;
        }
        return say;
    }
};