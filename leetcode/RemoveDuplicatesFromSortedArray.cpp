#include <string>
#include <vector>

using namespace std;

class Solution {
  public:
    int removeDuplicates(vector<int> &nums) {
        if (nums.size() <= 1)
            return nums.size();

        int lastIndex = nums.size() - 1;
        for (int i = 1; i < nums.size() && i < lastIndex; i++) {
            while (nums[i] == nums[i - 1] && i < lastIndex) {
                int temp = nums[i];

                for (int j = i + 1; j < nums.size(); j++) {
                    nums[j - 1] = nums[j];
                }

                nums[lastIndex] = temp;
                lastIndex--;
            }
        }

        return lastIndex + 1;
    }
};