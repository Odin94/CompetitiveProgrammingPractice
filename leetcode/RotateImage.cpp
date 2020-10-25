#include <vector>
#include <iostream>

using namespace std;

class Solution {
  public:
    void rotate(vector<vector<int>> &matrix) {
        if (matrix.size() == 0)
            return;

        for (int i = 0; i < matrix.size() / 2; i++) {
            for (int j = i; j < matrix.size() - 1 - i; j++) {
                do_rotate(matrix, i, j);
            }
        }
    }

    void do_rotate(vector<vector<int>> &matrix, int i, int j) {
        int val_to_write_next = matrix[i][j];
        for (int k = 0; k <= 4; k++) {
            int new_i = j;
            int new_j = (matrix.size() - 1) - i;
            int temp = matrix[new_i][new_j];

            matrix[new_i][new_j] = val_to_write_next;
            
            val_to_write_next = temp;
            i = new_i;
            j = new_j;
        }
    }

    void inefficient_rotate(vector<vector<int>> &matrix) {
        auto new_matrix = vector<vector<int>>(matrix.size());
        for (int i = matrix.size() - 1; i >= 0; i--) {
            auto row = matrix[i];
            for (int j = 0; j < matrix.size(); j++) {
                new_matrix[j].push_back(row[j]);
            }
        }

        for (auto row : new_matrix) {
            for (auto entry : row) {
                cout << entry << ", ";
            }
            cout << "\n";
        }
    }
};
