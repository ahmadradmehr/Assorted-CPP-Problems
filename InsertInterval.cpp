/*
*** Insert Interval ***
* 
* 
* Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).
* You may assume that the intervals were initially sorted according to their start times.
* 
* Example 1:
* Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
* Output: [[1,5],[6,9]]
* 
* Example 2:
* Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
* Output: [[1,2],[3,10],[12,16]]
* Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].
* NOTE: input types have been changed on April 15, 2019. Please reset to default code definition to get new method signature.
*/


class InsertInterval {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        bool found = false;
        for (int i {0}; i < intervals.size(); i++) {
            if (newInterval.front() < intervals.at(i).front() && !found) {
                for (int j {i}; j < intervals.size(); j++) {
                    if (newInterval.back() < intervals.at(j).front()) {
                        res.push_back(newInterval);
                        i = j - 1;
                        found = true;
                        break;
                    } else if (newInterval.back() < intervals.at(j).back()) {
                        res.push_back({newInterval.front(), intervals.at(j).back()});
                        i = j;
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    res.push_back(newInterval);
                    i = intervals.size()-1;
                    found = true;
                }
            } else if (newInterval.front() <= intervals.at(i).back() && !found) {
                for (int j {i}; j < intervals.size(); j++) {
                    if (newInterval.back() < intervals.at(j).front()) {
                        res.push_back({intervals.at(i).front(), newInterval.back()});
                        i = j - 1;
                        found = true;
                        break;
                    } else if (newInterval.back() < intervals.at(j).back()) {
                        res.push_back({intervals.at(i).front(), intervals.at(j).back()});
                        i = j;
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    res.push_back({intervals.at(i).front(), newInterval.back()});
                    i = intervals.size()-1;
                    found = true;
                }
            } else {
                res.push_back(intervals.at(i));
            }
        }
        if (!found)
            res.push_back(newInterval);
        return res;
    }
};