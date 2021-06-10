/* ### My Calendar I ###
Implement a MyCalendar class to store your events. A new event can be added if adding the event will not cause a double booking.

Your class will have the method, book(int start, int end). Formally, this represents a booking on the half open interval [start, end), the range of real numbers x such that start <= x < end.

A double booking happens when two events have some non-empty intersection (ie., there is some time that is common to both events.)

For each call to the method MyCalendar.book, return true if the event can be added to the calendar successfully without causing a double booking. Otherwise, return false and do not add the event to the calendar.

Your class will be called like this: MyCalendar cal = new MyCalendar(); MyCalendar.book(start, end)
Example 1:

MyCalendar();
MyCalendar.book(10, 20); // returns true
MyCalendar.book(15, 25); // returns false
MyCalendar.book(20, 30); // returns true
Explanation: 
The first event can be booked.  The second can't because time 15 is already booked by another event.
The third event can be booked, as the first event takes every time less than 20, but not including 20.
 

Note:

The number of calls to MyCalendar.book per test case will be at most 1000.
In calls to MyCalendar.book(start, end), start and end are integers in the range [0, 10^9].

*/


class MyCalendar {
private:
    vector<pair<int, int>> intervals;

public:
    MyCalendar(){
        
    }
    
    bool book(int start, int end) {
        for (auto [s, e]: intervals) {
            if (max(s, start) < min(e, end))
                return false;
        }
        intervals.push_back({start, end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */

// class MyCalendar {
// private:
//     vector<int> intervals;

// public:
//     MyCalendar() : intervals {} {
        
//     }
    
//     bool book(int start, int end) {
//         int l = find_index(start);
//         int r = find_index(end);
//         if (r != 0 && intervals[r - 1] == end)
//             r--;
//         if (l % 2 == 1 || r != l)
//             return false;
//         intervals.insert(intervals.begin() + r, end);
//         intervals.insert(intervals.begin() + l, start);
//         return true;
//     }
    
//     int find_index(int x) {
//         if (intervals.empty())
//             return 0;
//         int l {0}, r = intervals.size() - 1;
//         while (r - l > 0) {
//             int m = (l + r) / 2;
//             if (x == intervals[m])
//                 return m+1;
//             if (x > intervals[m])
//                 l = m + 1;
//             else if (x < intervals[m])
//                 r = m;
//         }
//         if (x < intervals[l])
//             return l;
//         return l+1;
//     }
// };

// /**
//  * Your MyCalendar object will be instantiated and called as such:
//  * MyCalendar* obj = new MyCalendar();
//  * bool param_1 = obj->book(start,end);
//  */