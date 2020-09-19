/*
 * ### Battleships in a Board ###
 * 
 * 
 * Given an 2D board, count how many battleships are in it. The battleships are represented with 'X's, empty slots are represented with '.'s. You may assume the following rules:
 * You receive a valid board, made of only battleships or empty slots.
 * Battleships can only be placed horizontally or vertically. In other words, they can only be made of the shape 1xN (1 row, N columns) or Nx1 (N rows, 1 column), where N can be of any size.
 * At least one horizontal or vertical cell separates between two battleships - there are no adjacent battleships.
 * 
 * Example:
 * X..X
 * ...X
 * ...X
 * In the above board there are 2 battleships.
 * 
 * Invalid Example:
 * ...X
 * XXXX
 * ...X
 * This is an invalid board that you will not receive - as battleships will always have a cell separating between them.
 * 
 * Follow up:
 * Could you do it in one-pass, using only O(1) extra memory and without modifying the value of the board?
 */


class CountBattleships {
public:
    int countBattleships(vector<vector<char>>& board) {
        int num {0};
        vector<int> ships (board.front().size(), 0);
        for (int i {0}; i < board.size(); i++) {
            for (int j {0}; j < board.front().size(); j++) {
                if (board[i][j] == '.' && ships[j] == 1)
                    ships[j] = 0;
                else if (board[i][j] == 'X' && ships[j] == 0) {
                    num++;
                    ships[j] = 1;
                    while (j < board.front().size()-1 && board[i][j+1] == 'X') {
                        j++;
                    }
                }
            }
        }
        return num;
    }
};