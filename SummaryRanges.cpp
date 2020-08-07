/* Summary Ranges
 * 
 * Given a sorted integer array without duplicates, return the summary of its ranges.
 * 
 * Example 1:
 * Input:  [0,1,2,4,5,7]
 * Output: ["0->2","4->5","7"]
 * Explanation: 0,1,2 form a continuous range; 4,5 form a continuous range.
 * 
 * Example 2:
 * Input:  [0,2,3,4,6,8,9]
 * Output: ["0","2->4","6","8->9"]
 * Explanation: 2,3,4 form a continuous range; 8,9 form a continuous range.
 */
 
class SummaryRanges {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if (nums.empty())
            return {};
        int low = nums.at(0), high = low, i = 1;
        vector<string> res;
        while (high <= nums.back()) {
            if (high == nums.back()) {
                if (high == low) {
                    res.push_back(to_string(high));
                } else {
                    res.push_back(to_string(low) + "->" + to_string(high));
                }
                break;
            } else if (static_cast<long>(nums.at(i)) - high == 1) {
                high++;
            } else {
                if (low == high) {
                    res.push_back(to_string(high));
                } else {
                    res.push_back(to_string(low) + "->" + to_string(high));
                }
                low = high = nums.at(i);
            }
            i++;
        }
        return res;
    }
};