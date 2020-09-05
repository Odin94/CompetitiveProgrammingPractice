#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
  public:
    string longestCommonPrefix(vector<string> &strs) {
        if (strs.empty())
            return "";

        int i = 0;
        while (common_char_at(strs, i))
            i++;

        return strs[0].substr(0, i);
    }

    bool common_char_at(const vector<string> &strs, int i) {
        if (i >= strs[0].length())
            return false;

        char character = strs[0][i];
        for (const string &str : strs) {
            if (i >= str.length() || str[i] != character)
                return false;
        }

        return true;
    }
};