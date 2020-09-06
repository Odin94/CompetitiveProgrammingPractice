#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
  public:
    string convert(string s, int numRows) {
        vector<string> rows(min(numRows, (int)s.length()), "");
        string dir = "down";
        int currentRow = 0;
        for (char &c : s) {
            rows[currentRow] += c;

            if (dir == "down" && currentRow == rows.size() - 1) {
                dir = "up";
            } else if (dir == "up" && currentRow == 0) {
                dir = "down";
            }

            if (dir == "down") {
                currentRow = min(currentRow + 1, (int)rows.size() - 1);
            } else {
                currentRow = max(currentRow - 1, 0);
            }
        }

        string result = "";
        for (string &str : rows) {
            result += str;
        }

        return result;
    }
};