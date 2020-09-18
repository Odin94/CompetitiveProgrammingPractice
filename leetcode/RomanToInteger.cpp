#include <string>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
  public:
    unordered_map<char, int> numByRomanDigit = initNumByRomanDigit();
    unordered_map<char, int> initNumByRomanDigit() {
        unordered_map<char, int> map;
        map['I'] = 1;
        map['V'] = 5;
        map['X'] = 10;
        map['L'] = 50;
        map['C'] = 100;
        map['D'] = 500;
        map['M'] = 1000;

        return map;
    }

    // input in range from 1 to 3999.
    int romanToInt(string s) {
        int sum = 0;
        for (auto i = 0; i < s.size(); i++) {
            char c = s[i];

            if (i + 1 < s.size() && numByRomanDigit[c] < numByRomanDigit[s[i + 1]]) {
                sum += numByRomanDigit[s[i + 1]] - numByRomanDigit[c];
                i++;
            } else {
                sum += numByRomanDigit[c];
            }
        }

        return sum;
    }
};