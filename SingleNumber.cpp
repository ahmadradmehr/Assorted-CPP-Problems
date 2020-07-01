/* Single Number
 * 
 * Given a non-empty array of integers, every element appears twice except for one. Find that single one.
 * 
 * Note:
 * Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
 * 
 * Example 1:
 * Input: [2,2,1]
 * Output: 1
 * 
 * Example 2:
 * Input: [4,1,2,1,2]
 * Output: 4
 */
 
// class SingleNumber {
// public:
//     int singleNumber(vector<int>& nums) {
//         map<int, int> m;
//         int res {0};
//         for (int i {0}; i < nums.size(); i++) {
//             m[nums.at(i)]++;
//         }
//         for (auto &mm: m) {
//             if (mm.second == 1)
//                 res = mm.first;
//         }
//         return res;
//     }
// };

class SingleNumber {
public:
    int singleNumber(vector<int>& nums) {
        int num = 0;
        for (auto &n: nums) {
            num ^= n;
        }
        return num;
    }
};