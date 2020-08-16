/* Ugly Number II
 * 
 * Write a program to find the n-th ugly number.
 * Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. 
 * 
 * Example:
 * Input: n = 10
 * Output: 12
 * Explanation: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.
 * 
 * Note:  
 * 1 is typically treated as an ugly number.
 * n does not exceed 1690.
 */
 
class UglyNumber_II {
public:
    int nthUglyNumber(int n) {
        vector<int> res (1, 1);
        int i = 0, j = 0, k = 0;
        while (n-- > 1) {
            res.push_back(min(res.at(i) * 2, min(res.at(j) * 3, res.at(k) * 5)));
            if (res.back() == res.at(i) * 2)
                i++;
            if (res.back() == res.at(j) * 3)
                j++;
            if (res.back() == res.at(k) * 5)
                k++;
        }
        return res.back();
    }
};