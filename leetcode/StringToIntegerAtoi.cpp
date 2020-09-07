#include <string>

using namespace std;

class Solution {
  public:
    // would be faster with a hash set
    string digits = "0123456789";

    int myAtoi(string str) {
        bool isNegative = false;
        int result = do_atoi(str, 0, isNegative, false);

        if (isNegative)
            // problem assumes INT32 on leetcode
            if (result == INT32_MIN)
                return INT32_MIN;
            else
                return -result;
        else
            return result;
    }

    int do_atoi(string str, int acc, bool &isNegative, bool hasSeenDigit) {
        if (str.length() == 0)
            return acc;

        char head = str[0];
        string tail = str.substr(1);

        if (head == ' ') {
            if (hasSeenDigit)
                return acc;
            else
                return do_atoi(tail, acc, isNegative, hasSeenDigit);

        } else if (head == '+') {
            if (hasSeenDigit) {
                return acc;
            }

            return do_atoi(tail, acc, isNegative, true);
        } else if (head == '-') {
            if (hasSeenDigit) {
                return acc;
            }

            isNegative = true;
            return do_atoi(tail, acc, isNegative, true);
        } else if (digits.find(head) != std::string::npos) {
            int headNum = head - '0';

            // can't use long for overflow checking on leetcode for this problem
            if (isNegative && (-acc <= INT32_MIN / 10 + headNum - 8 || -acc * 10 + headNum - 8 == INT32_MIN)) {
                return INT32_MIN;
            }
            // INT_MAX ends in 7, which is lost in /10 so we add it back to avoid trigger INT_MAX when acc will be eg. INT_MAX-1
            if (acc >= INT32_MAX / 10 + 7 - headNum) {
                return INT32_MAX;
            }

            return do_atoi(tail, acc * 10 + headNum, isNegative, true);
        } else
            return acc;
    }
};