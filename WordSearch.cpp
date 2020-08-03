/* Word Search
 * 
 * Given a 2D board and a word, find if the word exists in the grid.
 * The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.
 * 
 * Example:
 * board =
 * [
 *   ['A','B','C','E'],
 *   ['S','F','C','S'],
 *   ['A','D','E','E']
 * ]
 * Given word = "ABCCED", return true.
 * Given word = "SEE", return true.
 * Given word = "ABCB", return false.
 * 
 * Constraints:
 * board and word consists only of lowercase and uppercase English letters.
 * 1 <= board.length <= 200
 * 1 <= board[i].length <= 200
 * 1 <= word.length <= 10^3
 */
 
class wordSearch {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int i {0}; i < board.size(); i++) {
            for (int j {0}; j < board.at(0).size(); j++) {
                if (word.at(0) == board.at(i).at(j)) {
                    if (check(board, word, 0, i, j))
                        return true;
                }
            }
        }
        return false;
    }
    
    bool check(vector<vector<char>> &board, string &word, int ind, int i, int j) {
        if (word.at(ind) != board.at(i).at(j))
            return false;
        if (ind+1 == word.size())
            return true;
        char c = board.at(i).at(j);
        board.at(i).at(j) = '*';
        bool b {false};
        if (i > 0) {
            b = check(board, word, ind+1, i-1, j);
        }
        if (i < board.size()-1 && !b) {
            b = check(board, word, ind+1, i+1, j);
        }
        if (j > 0 && !b) {
            b = check(board, word, ind+1, i, j-1);
        }
        if (j < board.at(0).size()-1 && !b) {
            b = check(board, word, ind+1, i, j+1);
        }
        board.at(i).at(j) = c;
        return b;
    }
};