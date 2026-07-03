#include <unordered_set>

class Solution {
   public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (size_t i = 0; i < 9; ++i) {
            unordered_set<char> rows;
            unordered_set<char> cols;

            for (size_t j = 0; j < 9; ++j) {
                char c = board[i][j];

                if (rows.find(c) != rows.end()) {
                    return false;
                }

                if (c != '.') {
                    rows.insert(c);
                }

                char col_c = board[j][i];

                if (cols.find(col_c) != cols.end()) {
                    return false;
                }

                if (col_c != '.') {
                    cols.insert(col_c);
                }
            }

            unordered_set<char> boxes;

            int startRow = (i / 3) * 3;
            int startCol = (i % 3) * 3;

            for (int r = 0; r < 3; r++) {
                for (int c = 0; c < 3; c++) {
                    char box_c = board[startRow + r][startCol + c];
                    if (box_c != '.') {
                        if (boxes.find(box_c) != boxes.end()) {
                            return false;
                        }

                        boxes.insert(box_c);
                    }
                }
            }
        }

        return true;
    }
};
