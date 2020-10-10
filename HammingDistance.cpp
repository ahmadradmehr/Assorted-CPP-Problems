/*
 * ### Hamming Distance ###
 * 
 * 
 * The Hamming distance between two integers is the number of positions at which the corresponding bits are different.
 * Given two integers x and y, calculate the Hamming distance.
 * Note:
 * 0 ≤ x, y < 231.
 * 
 * Example:
 * Input: x = 1, y = 4
 * Output: 2
 * Explanation:
 * 1   (0 0 0 1)
 * 4   (0 1 0 0)
 *        ↑   ↑
 * The above arrows point to positions where the corresponding bits are different.
 */


class HammingDistance {
public:
    int hammingDistance(int x, int y) {
        int n = x ^ y, count {0};
        while (n != 0) {
            count++;
            n = n & (n-1);
        }
        return count;
    }
};

// class HammingDistance {
// public:
//     int hammingDistance(int x, int y) {
//         int z = x ^ y, res {0};
//         while (z > 0) {
//             res += z % 2;
//             z /= 2;
//         }
//         return res;
//     }
// };