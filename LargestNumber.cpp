/* Largest Number
 * 
 * Given a list of non negative integers, arrange them such that they form the largest number.
 * 
 * Example 1:
 * Input: [10,2]
 * Output: "210"
 * 
 * Example 2:
 * Input: [3,30,34,5,9]
 * Output: "9534330"
 * Note: The result may be very large, so you need to return a string instead of an integer.
 */
 
class LargestNumber {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> vec;
        for (int i {0}; i < nums.size(); i++) {
            vec.push_back(to_string(nums.at(i)));
        }
        sort(vec.begin(), vec.end(), [](string &x, string &y) {
            return x+y > y+x;
        });
        string s {""};
        for (int i {0}; i < vec.size(); i++) {
            if (s.empty() && vec.at(i).at(0) == '0')
                vec.at(i).erase(vec.at(i).begin());
            s += vec.at(i);
        }
        if (s.empty())
            s = "0";
        return s;
    }
};