class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
       int m = boxGrid.size();
    int n = boxGrid[0].size();

    // Step 1: Simulate gravity in original rows BEFORE rotation
    for (int row = 0; row < m; ++row) {
        int empty = n - 1;
        for (int col = n - 1; col >= 0; --col) {
            if (boxGrid[row][col] == '*') {
                empty = col - 1; // reset drop point above obstacle
            } else if (boxGrid[row][col] == '#') {
                if (col != empty) {
                    swap(boxGrid[row][col], boxGrid[row][empty]);
                }
                empty--;
            }
        }
    }

    // Step 2: Rotate 90 degrees clockwise
    vector<vector<char>> res(n, vector<char>(m));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            res[j][m - 1 - i] = boxGrid[i][j];
        }
    }

    return res;
    }
};