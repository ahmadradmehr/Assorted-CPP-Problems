/* Plus One
 * 
 * Given a non-empty array of digits representing a non-negative integer, plus one to the integer.
 * The digits are stored such that the most significant digit is at the head of the list,
 * and each element in the array contain a single digit.
 * 
 * You may assume the integer does not contain any leading zero, except the number 0 itself.
 * 
 * Example 1:
 * Input: [1,2,3]
 * Output: [1,2,4]
 * Explanation: The array represents the integer 123.
 * 
 * Example 2:
 * Input: [4,3,2,1]
 * Output: [4,3,2,2]
 * Explanation: The array represents the integer 4321.
 */
 
//class PlusOne {
//public:
//    vector<int> plusOne(vector<int>& digits) {
//        bool done = false;
//        int i = digits.size()-1;
//        while (!done) {
//            if (i < 0) {
//                std::reverse(digits.begin(), digits.end());
//                digits.push_back(1);
//                std::reverse(digits.begin(), digits.end());
//                done = true;
//            } else if (digits.at(i) != 9) {
//                digits.at(i)++;
//                done = true;
//            } else {
//                digits.at(i) = 0;
//                i--;
//            }
//        }
//        return digits;
//    }
//};

class PlusOne {
public:
    vector<int> plusOne(vector<int>& digits) {
        int i = digits.size()-1;
        while (true) {
            if (i < 0) {
                digits.insert(digits.begin(), 1);
                break;
            } else if (digits.at(i) != 9) {
                digits.at(i)++;
                break;
            } else {
                digits.at(i) = 0;
                i--;
            }
        }
        return digits;
    }
};