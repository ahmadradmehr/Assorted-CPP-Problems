/* Simplify Path
 * 
 * Given an absolute path for a file (Unix-style), simplify it. Or in other words, convert it to the canonical path.
 * In a UNIX-style file system, a period . refers to the current directory.
 * Furthermore, a double period .. moves the directory up a level.
 * 
 * Note that the returned canonical path must always begin with a slash /, and there must be only a single slash / between two directory names.
 * The last directory name (if it exists) must not end with a trailing /. Also, the canonical path must be the shortest string representing the absolute path.
 * 
 * Example 1:
 * Input: "/home/"
 * Output: "/home"
 * Explanation: Note that there is no trailing slash after the last directory name.
 * 
 * Example 2:
 * Input: "/../"
 * Output: "/"
 * Explanation: Going one level up from the root directory is a no-op, as the root level is the highest level you can go.
 * 
 * Example 3:
 * Input: "/home//foo/"
 * Output: "/home/foo"
 * Explanation: In the canonical path, multiple consecutive slashes are replaced by a single one.
 * 
 * Example 4:
 * Input: "/a/./b/../../c/"
 * Output: "/c"
 * 
 * Example 5:
 * Input: "/a/../../b/../c//.//"
 * Output: "/c"
 * 
 * Example 6:
 * Input: "/a//b////c/d//././/.."
 * Output: "/a/b/c"
 */
 
class SimplifyPath {
public:
    string simplifyPath(string path) {
        string res {"/"};
        for (int i {0}; i < path.length(); i++) {
            if (path.at(i) == '/' && res.back() != '/') {
                res += '/';
            } else if (path.at(i) == '.') {
                if (i < path.length()-1 && path.at(i+1) == '/')
                    continue;
                else if (i < path.length()-2 && path.at(i+1) == '.' && path.at(i+2) == '/' ||
                        i == path.length()-2 && path.at(i+1) == '.') {
                    res.pop_back();
                    while (!res.empty() && res.back() != '/')
                        res.pop_back();
                    if (res.empty())
                        res.push_back('/');
                } else if (i < path.length()-1) {
                    res += '.';
                    while (i < path.length()-1 && path.at(i+1) != '/') {
                        i++;
                        res += path.at(i);
                    }
                }
            } else if (path.at(i) != '/') {
                res.push_back(path.at(i));
            }
        }
        if (res.length() > 1 && res.back() == '/')
            res.pop_back();
        return res;
    }
};