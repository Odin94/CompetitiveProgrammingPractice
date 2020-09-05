#include <string>
using namespace std;

class Solution {
  public:
    bool isPalindrome(int x) {
        string s = to_string(x);
        int len = s.length();
        int left = len / 2 - 1;
        int right = len / 2;

        if (len % 2 != 0)
            right++;

        for (int i = 0; i < len / 2; i++) {
            if (s[left - i] != s[right + i])
                return false;
        }

        return true;
    }
};