/* Top K Frequent Elements
 * 
 * Given a non-empty array of integers, return the k most frequent elements.
 * 
 * Example 1:
 * Input: nums = [1,1,1,2,2,3], k = 2
 * Output: [1,2]
 * 
 * Example 2:
 * Input: nums = [1], k = 1
 * Output: [1]
 * 
 * Note:
 * You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
 * Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
 * It's guaranteed that the answer is unique, in other words the set of the top k frequent elements is unique.
 * You can return the answer in any order.
 */

class TopKFrequent {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> freq;
        map<int, int> m_raw;
        map<int, vector<int>, greater<int>> m_freq;
        for (int &n: nums) {
            m_raw[n]++;
        }
        for (auto &[key, value]: m_raw) {
            m_freq[value].push_back(key);
        }
        for (auto &[key, value]: m_freq) {
            for (int &n: value) {
                freq.push_back(n);
                if (freq.size() == k)
                    break;
            }
            if (freq.size() == k)
                break;
        }
        return freq;
    }
};