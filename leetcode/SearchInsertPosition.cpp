#include <vector>
#include <math.h>
#include <iostream>

using namespace std;

class Solution {
  public:
    int searchInsertNaive(vector<int> &nums, int target, int startingPoint) {
        for (int i = startingPoint; i < nums.size(); i++) {
            if (nums[i] >= target)
                return i;
        }

        return nums.size();
    }

    int searchInsert(vector<int> &nums, int target) {
        int left = 0;
        int right = nums.size();
        int i = right / 2;
        while (left < right) {
            i = left + (right - left) / 2;

            if (nums[i] == target)
                return i;

            if (nums[i] > target) {
                right = i - 1;
            } else {
                left = i + 1;
            }
        }

        if (i - 2 < 0)
            i = 0;
        else
            i -= 2;

        return searchInsertNaive(nums, target, i);
    }
};