/*
 * ### Find All Numbers Disappeared in an Array ###
 * 
 * 
 * Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.
 * Find all the elements of [1, n] inclusive that do not appear in this array.
 * Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.
 * 
 * Example:
 * Input:
 * [4,3,2,7,8,2,3,1]
 * Output:
 * [5,6]
 */


class FindDisappearedNumbers {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        for (int i {0}; i < nums.size(); i++) {
            int m = abs(nums.at(i)) - 1;
            if (nums.at(m) > 0)
                nums.at(m) *= -1;
        }
        for (int i {0}; i < nums.size(); i++) {
            if (nums.at(i) > 0)
                res.push_back(i+1);
        }
        return res;
    }
};

// class FindDisappearedNumbers {
// public:
//     vector<int> findDisappearedNumbers(vector<int>& nums) {
//         vector<int> res (nums.size(), 1);
//         for (auto &n: nums)
//             res.at(n-1) = 0;
//         for (int i {0}; i < res.size(); i++)
//             if (res.at(i) == 1)
//                 res.at(i) = i + 1;
//         res.erase(remove(res.begin(),res.end(), 0), res.end());
//         return res;
//     }
// };