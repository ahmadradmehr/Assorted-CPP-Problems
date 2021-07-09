/*
 * ### Longest Increasing Subsequence ###
 * 
 * 
 * Given an integer array nums, return the length of the longest strictly increasing subsequence.

A subsequence is a sequence that can be derived from an array by deleting some or no elements without changing the order of the remaining elements. For example, [3,6,2,7] is a subsequence of the array [0,3,1,6,2,2,7].

 

Example 1:

Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
Example 2:

Input: nums = [0,1,0,3,2,3]
Output: 4
Example 3:

Input: nums = [7,7,7,7,7,7,7]
Output: 1
 

Constraints:

1 <= nums.length <= 2500
-104 <= nums[i] <= 104
 

Follow up: Can you come up with an algorithm that runs in O(n log(n)) time complexity?
 */


class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        map<int, int, greater<int>> m {{1, nums[0]}};
        for (int i {1}; i < nums.size(); i++) {
            for (auto &mm: m) {
                if (nums[i] > mm.second && (m.count(mm.first+1) && nums[i] < m[mm.first+1] || !m.count(mm.first+1))) {
                    m[mm.first+1] = nums[i];
                    break;
                } else if (mm.first == 1 && nums[i] < mm.second) {
                    m[1] = nums[i];
                    break;
                }
            }
        }
        return m.begin()->first;
    }
};

// class Solution {
// public:
//     int lengthOfLIS(vector<int>& nums) {
//         vector<pair<int, int>> v {make_pair(nums[0], 1)};
//         for (int i {1}; i < nums.size(); i++) {
//             for (int j {0}; j < v.size(); j++) {
//                 if (nums[i] > v[j].first) {
//                     int k = j;
//                     while (k > 0 && v[k-1].second == v[j].second + 1 && nums[i] < v[k-1].first)
//                         k--;
//                     v.insert(v.begin() + k, make_pair(nums[i], v[j].second + 1));
//                     break;
//                 } else if (j == v.size() - 1) {
//                     int k = j+1;
//                     while (k > 0 && v[k-1].second == 1 && nums[i] < v[k-1].first)
//                         k--;
//                     v.insert(v.begin() + k, make_pair(nums[i], 1));
//                     break;
//                 }
//             }
//         }
//         return v[0].second;
//     }
// };