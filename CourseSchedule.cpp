/* Course Schedule
 * 
 * There are a total of numCourses courses you have to take, labeled from 0 to numCourses-1.
 * Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]
 * Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?
 * 
 * Example 1:
 * Input: numCourses = 2, prerequisites = [[1,0]]
 * Output: true
 * Explanation: There are a total of 2 courses to take. 
 *              To take course 1 you should have finished course 0. So it is possible.
 * 
 * Example 2:
 * Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
 * Output: false
 * Explanation: There are a total of 2 courses to take. 
 *              To take course 1 you should have finished course 0, and to take course 0 you should
 *              also have finished course 1. So it is impossible.
 * 
 * Constraints:
 * The input prerequisites is a graph represented by a list of edges, not adjacency matrices.
 * Read more about how a graph is represented.
 * You may assume that there are no duplicate edges in the input prerequisites.
 * 1 <= numCourses <= 10^5
 */
 
class CourseSchedule {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if (prerequisites.empty())
            return true;
        vector<vector<int>> graph = buildGraph(numCourses, prerequisites);
        vector<int> flags (numCourses, -1);
        stack<int> s;
        while (!s.empty() || *min_element(flags.begin(), flags.end()) == -1) {
            if (s.empty()) {
                for (int i {0}; i < numCourses; i++) {
                    if (flags.at(i) == -1) {
                        s.push(i);
                        flags.at(i) = 0;
                        break;
                    }
                }
            }
            int t = s.top();
            bool found = false;
            for (int i {0}; i < graph.at(t).size(); i++) {
                if (flags.at(graph.at(t).at(i)) == 0)
                    return false;
            }
            for (int i {0}; i < graph.at(t).size(); i++) {
                if (flags.at(graph.at(t).at(i)) == 1)
                    continue;
                s.push(graph.at(t).at(i));
                found = true;
                flags.at(graph.at(t).at(i)) = 0;
                break;
            }
            if (!found) {
                s.pop();
                flags.at(t) = 1;
            }
        }
        return true;
    }

    vector<vector<int>> buildGraph(int numCourses, vector<vector<int>> &prerequisites) {
        vector<vector<int>> g (numCourses);
        for (auto &p: prerequisites) {
            g.at(p.front()).push_back(p.back());
        }
        return g;
    }
};