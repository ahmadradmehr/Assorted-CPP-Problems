/*
*** Combination Sum III ***
* 
* 
* Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.
* 
* Note:
* All numbers will be positive integers.
* The solution set must not contain duplicate combinations.
* 
* Example 1:
* Input: k = 3, n = 7
* Output: [[1,2,4]]
* 
* Example 2:
* Input: k = 3, n = 9
* Output: [[1,2,6], [1,3,5], [2,3,4]]
*/

class CombinationSum_III {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> current;
        create(res, current, k, n);
        return res;
    }
    
    void create(vector<vector<int>> &res, vector<int> &current, int k, int n) {
        if (k == 0 && n == 0) {
            res.push_back(current);
        } else if (n <= 0 || (k == 0 && n > 0))
            return;
        int i;
        if (current.empty())
            i = 1;
        else
            i = current.back() + 1;
        for (int j {i}; j <= 9; j++) {
            current.push_back(j);
            create(res, current, k - 1, n - j);
            current.pop_back();
        }
    }
};