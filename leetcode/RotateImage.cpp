#include <vector>
#include <iostream>

using namespace std;

class Solution {
  public:
    void rotate(vector<vector<int>> &matrix) {
        if (matrix.size() == 0)
            return;

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