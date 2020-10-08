/*
 * ### Minimum Moves to Equal Array Elements ###
 * 
 * 
 * Given a non-empty integer array of size n, find the minimum number of moves required to make all array elements equal, where a move is incrementing n - 1 elements by 1.
 * 
 * Example:
 * Input:
 * [1,2,3]
 * Output:3
 * Explanation:
 * Only three moves are needed (remember each move increments two elements):
 * [1,2,3]  =>  [2,3,3]  =>  [3,4,3]  =>  [4,4,4]
 */


class MinimumMovesEqualElements {
public:
    int minMoves(vector<int>& nums) {
        int moves {0}, min_nums {nums[0]};
        for (int i {1}; i < nums.size(); i++) {
            if (nums[i] < min_nums) {
                moves += i * (min_nums - nums[i]);
                min_nums = nums[i];
            } else
                moves += nums[i] - min_nums;
        }
        return moves;
    }
};