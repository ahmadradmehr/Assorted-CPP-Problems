/* Median of Two Sorted Arrays
 * 
 * There are two sorted arrays nums1 and nums2 of size m and n respectively.
 * Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
 * 
 * You may assume nums1 and nums2 cannot be both empty.
 * 
 * Example 1:
 * 
 * nums1 = [1, 3]
 * nums2 = [2]
 * The median is 2.0
 * 
 * Example 2:
 * nums1 = [1, 2]
 * nums2 = [3, 4]
 * The median is (2 + 3)/2 = 2.5
 */
 
 class FindMedianSortedArrays {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        multiset<int> s;
        s.insert(nums1.begin(), nums1.end());
        s.insert(nums2.begin(), nums2.end());
        set<int>::iterator it = s.begin();
        if (s.size()%2 == 1) {
            advance(it, s.size()/2);
            return *it;
        }
        else {
            advance(it, s.size()/2-1);
            auto it2 = next(it, 1);
            return static_cast<double>(*it+*it2)/2;
        }
    }
};