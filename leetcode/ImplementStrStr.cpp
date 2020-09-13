#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
  public:
    int strStr(string haystack, string needle) {
        if (needle.empty())
            return 0;

        if (needle.size() > haystack.size())
            return -1;

        for (int i = 0; i < haystack.size(); i++) {
            if (needle.size() > haystack.size() - i)
                return -1;

            for (int j = 0; j < needle.size() && i + j < haystack.size(); j++) {
                if (needle[j] != haystack[i + j])
                    break;

                if (j == needle.size() - 1)
                    return i;
            }
        }

        return -1;
    }
};