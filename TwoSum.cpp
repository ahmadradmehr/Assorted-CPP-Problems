/* Given an array of integers, return indices of the two numbers such that they add up to a specific target.
 * You may assume that each input would have exactly one solution, and you may not use the same element twice.
 * 
 * Example:
 * Given nums = [2, 7, 11, 15], target = 9,
 * Because nums[0] + nums[1] = 2 + 7 = 9,
 * return [0, 1].
 */

class TwoSum {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> memory;
        for (int i {0}; i < nums.size(); i++) {
            int t = target - nums.at(i);
            if (memory.count(t))
                return {memory[t], i};
            memory[nums.at(i)] = i;
        }
        return {-1, -1};
    }
};

//class TwoSum {
//public:
//    vector<int> twoSum(vector<int>& nums, int target) {
//        int rem {0};
//        bool done {false};
//        int t {0};
//        vector<int> indices {0, 0};
//        while (!done) {
//            t = target;
//            for (int i {0}; i < nums.size(); i++) {
//                rem = t - nums[i];
//                for (int j {i+1}; j < nums.size(); j++) {
//                    if (nums[j] == rem) {
//                        done = true;
//                        indices.at(0) = i;
//                        indices.at(1) = j;
//                    }
//                }
//            }
//        }
//        return indices;
//    }
//};